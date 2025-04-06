`default_nettype none

module comb_divider_tb;

  logic [3:0] a;
  logic [3:0] b;
  logic [7:0] quotient;
  logic [7:0] remainder;

  initial begin
    a = 4'b1000; 
    b = 4'b1111;
    #10us;
    $display("quotient: %b", quotient);
    $stop;
  end

  comb_divider div(
    .a(a),
    .b(b),
    .quotient(quotient),
    .remainder(remainder)
  );
endmodule
