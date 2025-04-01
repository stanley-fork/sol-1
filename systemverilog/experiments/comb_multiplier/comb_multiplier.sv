module comb_multiplier(
  input logic [23:0] a,
  input logic [23:0] b,
  output logic [47:0] result
);

  logic [23:0][47:0] partial;
  logic [47:0]       partial23_signed;
  logic [47:0]       product;
  logic [47:0][23:0] carry;

/*
                     a3  a2  a1  a0
                     b3  b2  b1  b0
                b0a3 b0a2 b0a1 b0a0     partial[0]
           b1a3 b1a2 b1a1 b1a0          partial[1]
      b2a3 b2a2 b2a1 b2a0               partial[2]
 b3a3 b3a2 b3a1 b3a0                    partial[3]
   p6   p5   p4   p3   p2   p1   p0
*/


  for(genvar i = 0; i < 24; i++) begin
    assign partial[i] = {(48){b[i]}} & {{(24 - i){a[23]}},  a, {(i){1'b0}}};
  end

  assign partial3_signed = b[3] ? ~partial[3] + 1'b1 : partial[3]; // if b is negative then we subtract partial3 rather than add

/*
  assign {carry[1], product[0]} = {1'b0, partial[0][0]};
  assign {carry[2], product[1]} = partial[0][1] + partial[1][1];
  assign {carry[3], product[2]} = partial[0][2] + partial[1][2] + partial[2][2] + carry[2];
  assign {carry[4], product[3]} = partial[0][3] + partial[1][3] + partial[2][3] + partial3_signed[3] + carry[3];
  assign {carry[5], product[4]} = partial[0][4] + partial[1][4] + partial[2][4] + partial3_signed[4] + carry[4];
  assign {carry[6], product[5]} = partial[0][5] + partial[1][5] + partial[2][5] + partial3_signed[5] + carry[5];
  assign {carry[7], product[6]} = partial[0][6] + partial[1][6] + partial[2][6] + partial3_signed[6] + carry[6];
  assign {          product[7]} = partial[0][7] + partial[1][7] + partial[2][7] + partial3_signed[7] + carry[7];
  
  assign result = product;
  */

endmodule

