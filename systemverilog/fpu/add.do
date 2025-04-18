onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix binary /fpu_tb/fpu_top/arst
add wave -noupdate -radix binary /fpu_tb/fpu_top/clk
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_operand
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_operand
add wave -noupdate -radix binary /fpu_tb/fpu_top/operation
add wave -noupdate -radix binary /fpu_tb/fpu_top/start
add wave -noupdate -radix binary /fpu_tb/fpu_top/ieee_packet_out
add wave -noupdate -radix binary /fpu_tb/fpu_top/cmd_end
add wave -noupdate -radix binary /fpu_tb/fpu_top/busy
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_mantissa
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_mantissa_shifted
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_mantissa_adjusted
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_exp
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_exp_adjusted
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_sign
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_mantissa
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_mantissa_shifted
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_mantissa_adjusted
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_exp
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_exp_adjusted
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_sign
add wave -noupdate -radix binary /fpu_tb/fpu_top/sticky_bit
add wave -noupdate -radix binary /fpu_tb/fpu_top/ab_exp_diff
add wave -noupdate -radix binary /fpu_tb/fpu_top/ab_shift_amount
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_m_addsub_prenorm
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_m_addsub_abs
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_m_addsub_norm
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_m_addsub_subnorm_check
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_m_addsub_rounded
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_m_addsub_renorm
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_m_addsub
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_e_addsub_prenorm
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_e_addsub_norm
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_e_addsub_renorm
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_e_addsub
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_s_addsub
add wave -noupdate -radix binary /fpu_tb/fpu_top/result_addsub_is_subnormal
add wave -noupdate -radix binary /fpu_tb/fpu_top/zcount_addsub
add wave -noupdate -radix binary /fpu_tb/fpu_top/addsub_effective_normalization_shift
add wave -noupdate -radix binary /fpu_tb/fpu_top/addsub_guard
add wave -noupdate -radix binary /fpu_tb/fpu_top/addsub_round
add wave -noupdate -radix binary /fpu_tb/fpu_top/addsub_sticky
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_neg
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_overflow
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_underflow
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_nan
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_inf
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_pos_inf
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_neg_inf
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_zero
add wave -noupdate -radix binary /fpu_tb/fpu_top/a_subnormal
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_overflow
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_underflow
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_nan
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_inf
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_pos_inf
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_neg_inf
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_zero
add wave -noupdate -radix binary /fpu_tb/fpu_top/b_subnormal
add wave -noupdate -radix binary /fpu_tb/fpu_top/zero_inf_or_inf_zero
add wave -noupdate -radix binary /fpu_tb/fpu_top/inf_or_inf
add wave -noupdate -radix binary /fpu_tb/fpu_top/zero_or_zero
add wave -noupdate -radix binary /fpu_tb/fpu_top/zero_and_zero
add wave -noupdate -radix binary /fpu_tb/fpu_top/zero_inf
add wave -noupdate -radix binary /fpu_tb/fpu_top/inf_zero
add wave -noupdate -radix binary /fpu_tb/fpu_top/nan_or_nan
add wave -noupdate -radix binary /fpu_tb/fpu_top/nan_inf_or_inf_nan
add wave -noupdate -radix binary /fpu_tb/fpu_top/zero_nan_or_nan_zero
add wave -noupdate -radix binary /fpu_tb/fpu_top/curr_state_main_fsm
add wave -noupdate -radix binary /fpu_tb/fpu_top/curr_state_arith_fsm
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {3966 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 301
configure wave -valuecolwidth 312
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ns} {5209 ns}
