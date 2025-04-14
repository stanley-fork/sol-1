/*
*/

module gpu #(
  parameter int mem_size = 65536
)(
  input  logic arst,
  input  logic [3 : 0] addr,
  input  logic [7 : 0] data,
  input  logic cs,
  input  logic rd,
  input  logic wr,
  output logic clk
);

  logic [MEM_SIZE - 1 : 0] vram;

endmodule
