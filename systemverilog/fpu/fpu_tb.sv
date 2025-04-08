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
    real af;
    real bf;
  } st_fpu_computation;

  st_fpu_computation computation_list[] = {
    st_fpu_computation'{32'h4d96890d, 32'h4a447fad, 315695520.0,  3219435.3},  // 0
    st_fpu_computation'{32'h3f800000, 32'h3f8ccccd, 1.0,          1.1},        // 1  
    st_fpu_computation'{32'h4cbebc20, 32'h0,        100000000,    0},          // 2     
    st_fpu_computation'{32'h3ee839f1, 32'h0,        0.4535670493, 0},          // 3        
    st_fpu_computation'{32'h40000000, 32'h0,        2,            0},          // 4          
    st_fpu_computation'{32'h41200000, 32'h0,        10,           0},          // 5        
    st_fpu_computation'{32'h40490fda, 32'h402df854, 3.1415926,    2.7182818},  // 6         
    st_fpu_computation'{32'h40490fda, 32'h402df854, 3.1415926,    2.7182818},  // 7        
    st_fpu_computation'{32'h3fffffff, 32'h402df854, 1.9999999,    2.7182818},  // 8         
    st_fpu_computation'{32'h42168f5c, 32'h0,        37.64,        0},          // 9           
    st_fpu_computation'{32'h41800000, 32'h42000000, 16.0,         32.0},       // 10           
    st_fpu_computation'{32'h3e800000, 32'h3f000000, 0.25,         0.5}         // 11           
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

    a_operand = computation_list[11].b; 
    b_operand = computation_list[8].b; 
    operation = pa_fpu::op_log2;
    start = 1'b1;

    @(cmd_end) start = 1'b0;
    #1us;
    $display("Result: 0x%x, %.6f", ieee_packet_out, $bitstoshortreal(ieee_packet_out));

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