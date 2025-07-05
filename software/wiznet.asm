; Sol-1 W5300 TCP Echo Server (8-bit indirect mode)
; ---------------------------------------------------
; Sets up W5300 to listen on TCP port 51515
; Echoes received bytes back to sender

; Constants -------------------------------------------------------------
W5300_ADDR_REG      .equ $fff0       ; I/O port to write W5300 register address
W5300_DATA_REG      .equ $fff1       ; I/O port to read/write W5300 data

W5300_MR            .equ $0000
W5300_GAR           .equ $0001
W5300_SUBR          .equ $0005
W5300_SHAR          .equ $0009
W5300_SIPR          .equ $000F

W5300_S0_MR         .equ $0400
W5300_S0_PORT       .equ $0404
W5300_S0_CR         .equ $0406
W5300_S0_SR         .equ $0403
W5300_S0_IR         .equ $0402
W5300_S0_RX_RSR     .equ $0426
W5300_S0_RX_FIFOR   .equ $0028
W5300_S0_TX_FIFOR   .equ $0024
W5300_S0_TX_WR      .equ $0424

SEND_CMD            .equ $20
SEND_OK_MASK        .equ $10

; Data -----------------------------------------------------------------
gw_ip:         .db 192, 168, 1, 1
gw_mask:       .db 255, 255, 255, 0
mac_addr:      .db 02h, 00h, 00h, 00h, 00h, 01h
local_ip:      .db 192, 168, 1, 88

; Helpers --------------------------------------------------------------

; Write byte AL to W5300 register in BL
write_w5300_reg:
    mov [W5300_ADDR_REG], bl
    mov [W5300_DATA_REG], al
    ret

; Write C bytes from [D] into W5300 starting at reg BL
write_w5300_mem:
    push si
    mov si, d
.wr_loop:
    mov al, [si]
    call write_w5300_reg
    inc bl
    inc si
    dec c
    jnz .wr_loop
    pop si
    ret

; Setup W5300 and start listening on TCP port 51515
setup_w5300:
    mov d, gw_ip
    mov bl, W5300_GAR
    mov c, 4
    call write_w5300_mem

    mov d, gw_mask
    mov bl, W5300_SUBR
    mov c, 4
    call write_w5300_mem

    mov d, mac_addr
    mov bl, W5300_SHAR
    mov c, 6
    call write_w5300_mem

    mov d, local_ip
    mov bl, W5300_SIPR
    mov c, 4
    call write_w5300_mem

    ; Socket 0 Mode: TCP
    mov al, $01
    mov bl, W5300_S0_MR
    call write_w5300_reg

    ; Set port 51515 (0xC90B)
    mov al, $C9
    mov bl, W5300_S0_PORT
    call write_w5300_reg
    mov al, $0B
    inc bl
    call write_w5300_reg

    ; OPEN socket
    mov al, $01
    mov bl, W5300_S0_CR
    call write_w5300_reg

.wait_sock_init:
    mov bl, W5300_S0_SR
    mov [W5300_ADDR_REG], bl
    mov al, [W5300_DATA_REG]
    cmp al, $13  ; SOCK_INIT
    jne .wait_sock_init

    ; LISTEN
    mov al, $02
    mov bl, W5300_S0_CR
    call write_w5300_reg
    ret

; Echo Loop ------------------------------------------------------------
tcp_echo_loop:
.loop:
    ; Wait for data
    mov bl, W5300_S0_RX_RSR
    mov [W5300_ADDR_REG], bl
    mov al, [W5300_DATA_REG]
    cmp al, 0
    je .loop

    ; Read byte from RX FIFO
    mov bl, W5300_S0_RX_FIFOR
    mov [W5300_ADDR_REG], bl
    mov al, [W5300_DATA_REG]

    ; Print to screen
    mov ah, 0
    syscall sys_io

    ; Echo back
    call send_byte_tcp
    jmp .loop

; Send AL via TCP socket 0 ---------------------------------------------
send_byte_tcp:
    push ax
    push bx

    ; Write to TX FIFO
    mov bl, W5300_S0_TX_FIFOR
    mov [W5300_ADDR_REG], bl
    mov [W5300_DATA_REG], al

    ; Read TX_WR (2 bytes)
    mov bl, W5300_S0_TX_WR
    mov [W5300_ADDR_REG], bl
    mov ah, [W5300_DATA_REG]    ; Low byte
    inc bl
    mov [W5300_ADDR_REG], bl
    mov al, [W5300_DATA_REG]    ; High byte

    ; Increment WR += 1
    inc ah
    jnz .skip_carry
    inc al
.skip_carry:

    ; Write back updated TX_WR
    mov bl, W5300_S0_TX_WR
    mov [W5300_ADDR_REG], bl
    mov [W5300_DATA_REG], ah
    inc bl
    mov [W5300_ADDR_REG], bl
    mov [W5300_DATA_REG], al

    ; Send
    mov al, SEND_CMD
    mov bl, W5300_S0_CR
    call write_w5300_reg

.wait_send_ok:
    mov bl, W5300_S0_IR
    mov [W5300_ADDR_REG], bl
    mov al, [W5300_DATA_REG]
    test al, SEND_OK_MASK
    jz .wait_send_ok

    ; Clear SEND_OK
    mov al, SEND_OK_MASK
    mov bl, W5300_S0_IR
    call write_w5300_reg

    pop bx
    pop ax
    ret

; Entry ----------------------------------------------------------------
start:
    call setup_w5300
    call tcp_echo_loop
    hlt
