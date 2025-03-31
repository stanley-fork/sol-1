module comb_multiplier_tb;

  logic [3:0] a;
  logic [3:0] b;
  logic [7:0] result;

  initial begin
    a = 4'b1111; // 15 or -1
    b = 4'b1111; // 2
    #10us;
    $display("%b * %b = %b", a, b, result);
    $stop;
  end


  comb_multiplier multiplier(
    .a(a),
    .b(b),
    .result(result)
  );

endmodule
