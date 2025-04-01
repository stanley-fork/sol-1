module comb_multiplier_tb;

  logic [23:0] a;
  logic [23:0] b;
  logic [47:0] result;

  initial begin
    a = 129; 
    b = -59; 
    #10us;
    $display("%d(%b) * %d(%b) = %d(%b)", $signed(a), a, $signed(b), b, $signed(result), result);
    $stop;
  end


  comb_multiplier multiplier(
    .a(a),
    .b(b),
    ._signed(1),
    .result(result)
  );

endmodule
