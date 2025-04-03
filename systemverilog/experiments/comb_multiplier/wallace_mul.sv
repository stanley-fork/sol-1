module wallace_mul(
  input  logic [7:0] a,
  input  logic [7:0] b,
  output logic [15:0] result
);

  logic [7:0][15:0] partial;
  logic [15:0]      product;
  logic [15:0]      carry;

/*
                        a3  a2  a1  a0
                        b3  b2  b1  b0
                   b0a3 b0a2 b0a1 b0a0     partial[0]
              b1a3 b1a2 b1a1 b1a0          partial[1]
         b2a3 b2a2 b2a1 b2a0               partial[2]
    b3a3 b3a2 b3a1 b3a0                    partial[3]
 p7   p6   p5   p4   p3   p2   p1   p0
*/

  logic [15:0] stage1_0;
  logic [15:0] stage1_1;
  logic [15:0] stage1_2;

  for(genvar i = 0; i < 8; i++) 
    assign partial[i] = b[i] ? {{(8 - i){1'b0}},  a, {(i){1'b0}}} : 8'b0;


  assign stage1_0[0] = partial[0][0];
  assign stage1_0[1] = partial[0][1] + partial[1][1];
  assign stage1_0[2] = partial[0][2] + partial[1][2] + partial[2][2];
  assign stage1_1[2] = {partial[0][1] + partial[1][1]}[1];

  assign stage1_0[3] = partial[0][3] + partial[1][3] + partial[2][3];
  assign stage1_0[4] = partial[0][4] + partial[1][4] + partial[2][4];
  assign stage1_0[5] = partial[0][5] + partial[1][5] + partial[2][5];

  //assign stage1_1[2] = partial[0][2] + partial[1][2] + partial[2][2];
  assign stage1_2[2] = partial[0][1] + partial[1][1];



  assign result = product;

endmodule

