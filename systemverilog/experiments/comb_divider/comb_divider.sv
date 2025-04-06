// fractional combinational divider.
// 4bits divided by 4bits. result is 4 integer bits plus 4 fractional bits

module comb_divider(
  input logic [3:0] a,
  input logic [3:0] b,
  output logic [7:0] quotient,
  output logic [7:0] remainder
);
  logic signed [5:0] partial; // 1 extra bit for sign, 1 extra bit for fractional operations

  // since operads are 4 bits each, the partials are formed by adding one extra 'sign' bit to it, so that we can perform
  // a signed subtraction for each run. this extra sign bit is then checked to decide whether the result was positive or negative.
  // if positive(0) then the corresponding quotient bit is 1.
  always_comb begin
    partial = {5'b0, a[3]};
    for(int i = 7; i >= 1; i--) begin
      // IMPORTANT: b needs explicit size casting. if the expression was just $signed(partial)-$signed(b), then the sign extension combined with width extension would change the value of the subtraend if the MSB of subtraend was 1.
      // for example if b = 1000, sign extending it to 6bits makes it 111000, and that would be the value that would be subtracted instead of 001000.
      // so we need to first cast it to a larger width, and then apply $signed(). this casts 1000 to 001000 first, and then does a signed subtraction.
      partial = $signed(partial) - $signed($bits(partial)'(b)); 
      quotient[i] = ~partial[5];
      if(quotient[i]) begin
        partial = {1'b0, partial[3:0], a[i - 5 < 0 ? 0 : i - 5]}; // form a new partial by using ever decreasing indexed bits of 'a'. after bit0, use 0 instead
      end
      else begin
        partial = partial + b;
        partial = {1'b0, partial[3:0], a[i - 5 < 0 ? 0 : i - 5]};  // form a new partial by using ever decreasing indexed bits of 'a'. after bit0, use 0 instead
      end
    end
    partial = $signed(partial) - $signed($bits(partial)'(b));
    quotient[0] = ~partial[5];
    if(~quotient[0]) 
      partial = partial + b;

    remainder = partial[5:0];
  end

endmodule

