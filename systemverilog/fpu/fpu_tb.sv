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
    st_fpu_computation'{32'h4d96890d, 32'h4a447fad}   // 0   315695520.0,  3219435.3},
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
      operation = pa_fpu::op_add;
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