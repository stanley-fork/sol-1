module comb_multiplier(
  input logic [23:0] a,
  input logic [3:0] b,
  output logic [47:0] result
);
  logic [3:0][7:0] partial;
  logic [7:0]      partial3_signed;
  logic [7:0]      product;
  logic [7:0][2:0] carry;

/*
                     a3  a2  a1  a0
                     b3  b2  b1  b0
                b0a3 b0a2 b0a1 b0a0     partial[0]
           b1a3 b1a2 b1a1 b1a0          partial[1]
      b2a3 b2a2 b2a1 b2a0               partial[2]
 b3a3 b3a2 b3a1 b3a0                    partial[3]
   p6   p5   p4   p3   p2   p1   p0
*/

  assign partial[0] = {{(4){b[0] & a[3]}}, b[0] & a[3], b[0] & a[2], b[0] & a[1], b[0] & a[0]        };
  assign partial[1] = {{(3){b[1] & a[3]}}, b[1] & a[3], b[1] & a[2], b[1] & a[1], b[1] & a[0], 1'b0  };
  assign partial[2] = {{(2){b[2] & a[3]}}, b[2] & a[3], b[2] & a[2], b[2] & a[1], b[2] & a[0], 2'b00 };
  assign partial[3] = {{(1){b[3] & a[3]}}, b[3] & a[3], b[3] & a[2], b[3] & a[1], b[3] & a[0], 3'b000};
  assign partial3_signed = b[3] ? ~partial[3] + 1'b1 : partial[3]; // if b is negative then we subtract partial3 rather than add

  assign {carry[1], product[0]} = {1'b0, partial[0][0]};
  assign {carry[2], product[1]} = partial[0][1] + partial[1][1];
  assign {carry[3], product[2]} = partial[0][2] + partial[1][2] + partial[2][2] + carry[2];
  assign {carry[4], product[3]} = partial[0][3] + partial[1][3] + partial[2][3] + partial3_signed[3] + carry[3];
  assign {carry[5], product[4]} = partial[0][4] + partial[1][4] + partial[2][4] + partial3_signed[4] + carry[4];
  assign {carry[6], product[5]} = partial[0][5] + partial[1][5] + partial[2][5] + partial3_signed[5] + carry[5];
  assign {carry[7], product[6]} = partial[0][6] + partial[1][6] + partial[2][6] + partial3_signed[6] + carry[6];
  assign {          product[7]} = partial[0][7] + partial[1][7] + partial[2][7] + partial3_signed[7] + carry[7];
  
  assign result = product;

endmodule

