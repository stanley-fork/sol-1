module comb_divider(
  input logic [3:0] a,
  input logic [3:0] b,
  output logic [3:0] quotient,
  output logic [3:0] remainder
);
  logic [4:0] partial;

  // since operads are 4 bits each, the partials are formed by adding one extra 'sign' bit to it, so that we can perform
  // a signed subtraction for each run. this extra sign bit is then checked to decide whether the result was positive or negative.
  // if positive(0) then the corresponding quotient bit is 1.
  always_comb begin
    partial = $signed({4'b0, a[3]}) - $signed(b);
    quotient[3] = ~partial[4];
    if(quotient[3])
      partial = {1'b0, partial[2:0], a[2]};
    else begin
      partial = partial + b;
      partial = {1'b0, partial[2:0], a[2]};
    end

    partial = $signed(partial) - $signed(b);

    quotient[2] = ~partial[4];
    if(quotient[2])
      partial = {1'b0, partial[2:0], a[1]};
    else begin
      partial = partial + b;
      partial = {1'b0, partial[2:0], a[1]};
    end

    partial = $signed(partial) - $signed(b);

    quotient[1] = ~partial[4];
    if(quotient[1])
      partial = {1'b0, partial[2:0], a[0]};
    else begin
      partial = partial + b;
      partial = {1'b0, partial[2:0], a[0]};
    end

    partial = $signed(partial) - $signed(b);

    quotient[0] = ~partial[4];

    if(!quotient[0]) begin
      partial = partial + b;
    end
    remainder   = partial[3:0];
  end

endmodule

