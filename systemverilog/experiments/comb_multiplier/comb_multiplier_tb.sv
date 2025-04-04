module comb_multiplier_tb;

  logic [7:0] a;
  logic [7:0] b;
  logic [15:0] result;

  initial begin
    a = '1; 
    b = '1; 
    #10us;
    $display("%d(%b) * %d(%b) = %d(%b)", $signed(a), a, $signed(b), b, $signed(result), result);
    $display("result: %b", {2'(1'b1+1'b1)}[1]);
    $stop;
  end


  wallace_mul multiplier(
    .a(a),
    .b(b),
    .result(result)
  );

endmodule
