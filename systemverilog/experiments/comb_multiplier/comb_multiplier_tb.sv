module comb_multiplier_tb;

  logic [3:0] a;
  logic [3:0] b;
  logic [7:0] result;

  initial begin
    a = 4'b1110; // 6
    b = 4'b1100; // -4
    #10us;
    $display("%d(%b) * %d(%b) = %d(%b)", $signed(a), a, $signed(b), b, $signed(result), result);
    $stop;
  end


  comb_multiplier multiplier(
    .a(a),
    .b(b),
    .result(result)
  );

endmodule
