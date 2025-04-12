`default_nettype none

module fpu_tb;

  logic arst;
  logic clk;
  logic [31:0] a_operand;
  logic [31:0] b_operand;
  logic [31:0] ieee_packet_out;
  logic start;
  pa_fpu::e_fpu_op operation; // arithmetic operation to be performed
  logic cmd_end;      // end of command / irq
  logic busy;   // active high when an operation is in progress

  typedef struct{
    logic [31:0] a;
    logic [31:0] b;
  } st_fpu_computation;

  st_fpu_computation computation_list[] = {
    st_fpu_computation'{32'h4d96890d, 32'h4a447fad},   // 0   315695520.0,  3219435.3},
    st_fpu_computation'{32'h3f800000, 32'h3f8ccccd},   // 1   1.0,          1.1},      

    st_fpu_computation'{32'h00000000, 32'h3f800000},   // 2   0.0,          1.0},          
    st_fpu_computation'{32'h3f800000, 32'h00000000},   // 3   1.0,          0.0},             
    st_fpu_computation'{32'h7F800000, 32'h41200000},   // 4   inf,          10.0},               
    st_fpu_computation'{32'h41200000, 32'h7F800000},   // 5   10,           inf},             
    st_fpu_computation'{32'h7F800000, 32'h00000000},   // 4   inf,          0.0},               
    st_fpu_computation'{32'h00000000, 32'h7F800000},   // 5   0.0,          inf},             

    st_fpu_computation'{32'hFF800000, 32'h41200000},   // 4   -inf,          10.0},               
    st_fpu_computation'{32'h41200000, 32'hFF800000},   // 5   10,           -inf},             
    st_fpu_computation'{32'hFF800000, 32'h00000000},   // 4   -inf,          0.0},               
    st_fpu_computation'{32'h00000000, 32'hFF800000},   // 5   0.0,          -inf},             

    st_fpu_computation'{32'hFF800000, 32'hFF800000},   // 5   -inf,         -inf},             
    st_fpu_computation'{32'h7F800000, 32'h7F800000},   // 5    inf,          inf},             
    st_fpu_computation'{32'hFF800000, 32'h7F800000},   // 5   -inf,          inf},             
    st_fpu_computation'{32'h7F800000, 32'hFF800000},   // 5    inf,         -inf},             

    st_fpu_computation'{32'h7FC00000, 32'h402df854},   // 6   NAN,          2.7182818},      
    st_fpu_computation'{32'h402df854, 32'h7FC00000},   // 7   2.7182818,    NAN},     

    st_fpu_computation'{32'h3fffffff, 32'h402df854},   // 8   1.9999999,    2.7182818},      
    st_fpu_computation'{32'h42168f5c, 32'h0},          // 9   37.64,        0},                
    st_fpu_computation'{32'h41800000, 32'h42000000},   // 10  16.0,         32.0},              
    st_fpu_computation'{32'h3e800000, 32'h3f000000}    // 11  0.25,         0.5}                
  };

  initial begin
    clk = 0;
    forever #250ns clk = ~clk;
  end

  initial begin
    arst = 1;
    start = 1'b0;
    #1us;
    arst = 0;

    for(int i = 0; i < computation_list.size(); i++) begin
    //for(int i = 3; i < 4; i++) begin
      a_operand = computation_list[i].a; 
      b_operand = computation_list[i].b; 
      operation = pa_fpu::op_sqrt;
      start = 1'b1;
      @(cmd_end) start = 1'b0;
      #1us;
      $display("a: %-18.6f, b: %-18.6f, result: %-18.6f (%h, %b)", $bitstoshortreal(a_operand), $bitstoshortreal(b_operand), $bitstoshortreal(ieee_packet_out), ieee_packet_out, ieee_packet_out);
    end

    $stop;
  end

  fpu fpu_top(
    .arst        (arst),
    .clk         (clk),
    .start(start),
    .a_operand(a_operand),
    .b_operand(b_operand),
    .ieee_packet_out(ieee_packet_out),
    .operation(operation),
    .cmd_end     (cmd_end),
    .busy        (busy)
  );

endmodule