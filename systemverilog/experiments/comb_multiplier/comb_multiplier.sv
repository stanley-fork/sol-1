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

  assign partial23_signed = b[23] ? ~partial[23] + 1'b1 : partial[23]; // if b is negative then we subtract partial23 rather than add

  assign carry[0] = '0;
  assign {carry[1],  product[0]}  = partial[0][0]  + carry[0];         
  assign {carry[2],  product[1]}  = partial[0][1]  + partial[1][1]  + carry[1];        
  assign {carry[3],  product[2]}  = partial[0][2]  + partial[1][2]  + partial[2][2]  + carry[2];       
  assign {carry[4],  product[3]}  = partial[0][3]  + partial[1][3]  + partial[2][3]  + partial[3][3]  + carry[3];      
  assign {carry[5],  product[4]}  = partial[0][4]  + partial[1][4]  + partial[2][4]  + partial[3][4]  + partial[4][4]  + carry[4];     
  assign {carry[6],  product[5]}  = partial[0][5]  + partial[1][5]  + partial[2][5]  + partial[3][5]  + partial[4][5]  + partial[5][5]  + carry[5];    
  assign {carry[7],  product[6]}  = partial[0][6]  + partial[1][6]  + partial[2][6]  + partial[3][6]  + partial[4][6]  + partial[5][6]  + partial[6][6]  + carry[6];   
  assign {carry[8],  product[7]}  = partial[0][7]  + partial[1][7]  + partial[2][7]  + partial[3][7]  + partial[4][7]  + partial[5][7]  + partial[6][7]  + partial[7][7]  + carry[7];  
  assign {carry[9],  product[8]}  = partial[0][8]  + partial[1][8]  + partial[2][8]  + partial[3][8]  + partial[4][8]  + partial[5][8]  + partial[6][8]  + partial[7][8]  + partial[8][8]  + carry[8]; 
  assign {carry[10], product[9]}  = partial[0][9]  + partial[1][9]  + partial[2][9]  + partial[3][9]  + partial[4][9]  + partial[5][9]  + partial[6][9]  + partial[7][9]  + partial[8][9]  + partial[9][9]  + carry[9];
  assign {carry[11], product[10]} = partial[0][10] + partial[1][10] + partial[2][10] + partial[3][10] + partial[4][10] + partial[5][10] + partial[6][10] + partial[7][10] + partial[8][10] + partial[9][10] + partial[10][10] + carry[10];

/*
  assign {carry[6], product[5]} = partial[0][5] + partial[1][5] + partial[2][5] + partial[3][5] + carry[5];
  assign {carry[7], product[6]} = partial[0][6] + partial[1][6] + partial[2][6] + partial[3][6] + carry[6];
  assign {          product[7]} = partial[0][7] + partial[1][7] + partial[2][7] + partial[3][7] + carry[7];
  */
  
  assign result = product;

endmodule

