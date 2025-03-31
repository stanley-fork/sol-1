module comb_multiplier(
  input logic [3:0] a,
  input logic [3:0] b,
  output logic [7:0] result
);
  logic [7:0] partial0;
  logic [7:0] partial1;
  logic [7:0] partial2;
  logic [7:0] partial3;
  logic [7:0] product;
  logic [7:0][2:0] carry;
/*
                     a3  a2  a1  a0
                     b3  b2  b1  b0
                b0a3 b0a2 b0a1 b0a0     partial0
           b1a3 b1a2 b1a1 b1a0          partial1
      b2a3 b2a2 b2a1 b2a0               partial2
 b3a3 b3a2 b3a1 b3a0                    partial3
   p6   p5   p4   p3   p2   p1   p0
*/

  assign partial0 = {4'b0000, b[0] & a[3], b[0] & a[2], b[0] & a[1], b[0] & a[0]        };
  assign partial1 = {3'b000,  b[1] & a[3], b[1] & a[2], b[1] & a[1], b[1] & a[0], 1'b0  };
  assign partial2 = {2'b00,   b[2] & a[3], b[2] & a[2], b[2] & a[1], b[2] & a[0], 2'b00 };
  assign partial3 = {1'b0,    b[3] & a[3], b[3] & a[2], b[3] & a[1], b[3] & a[0], 3'b000};

  assign {carry[1],   product[0]} = {1'b0, partial0[0]};
  assign {carry[2],   product[1]} = partial0[1] + partial1[1];
  assign {carry[3],   product[2]} = partial0[2] + partial1[2] + partial2[2] + carry[2];
  assign {carry[4],   product[3]} = partial0[3] + partial1[3] + partial2[3] + partial3[3] + carry[3];
  assign {carry[5],   product[4]} = partial0[4] + partial1[4] + partial2[4] + partial3[4] + carry[4];
  assign {carry[6],   product[5]} = partial0[5] + partial1[5] + partial2[5] + partial3[5] + carry[5];
  assign {product[7], product[6]} = partial0[6] + partial1[6] + partial2[6] + partial3[6] + carry[6];
  
  assign result = product;

endmodule

