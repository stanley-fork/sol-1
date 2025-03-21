module test_fpu;
  timeunit 1ns;
  timeprecision 1ps;

  interface_fpu in_fpu();

  // Test program
  test_program test_program_fpu(
    .in_fpu (in_fpu)
  );

  assign in_fpu.arst = `p_fpu.arst;
  assign in_fpu.clk  = `p_fpu.clk;
  assign in_fpu.errorCount = in_fpu.errorCntTb + in_fpu.errorCntAs;

  FPU_TOP #() u_FPU_TOP(

  );

endmodule