module fpu_tb;

  logic [31:0] a_operand;
  logic [31:0] b_operand;
  logic [31:0] ieee_packet_out;
  pa_fpu::e_fpu_op operation; // arithmetic operation to be performed

  typedef struct{
    logic [31:0] a;
    logic [31:0] b;
    logic [31:0] result_add;
    logic [31:0] result_sub;
  } st_fpu_computation;

  st_fpu_computation list_subnormal[] = '{
    '{32'h00000001, 32'h00000000, 32'h00000001, 32'h00000001},  // smallest, zero
    '{32'h00000001, 32'h00000001, 32'h00000002, 32'h00000000},  // smallest + smallest
    '{32'h00000002, 32'h00000002, 32'h00000004, 32'h00000000},  // 2nd smallest + 2nd
    '{32'h00000002, 32'h00000001, 32'h00000003, 32'h00000001},  // 2nd + smallest
    '{32'h007fffff, 32'h00000001, 32'h00800000, 32'h007ffffe},  // largest sub + smallest
    '{32'h007fffff, 32'h007fffff, 32'h00fffffe, 32'h00000000},  // largest sub + same
    '{32'h00800000, 32'h007fffff, 32'h00ffffff, 32'h00000001},  // smallest norm + largest sub
    '{32'h00800000, 32'h00000001, 32'h00800001, 32'h007fffff},  // smallest norm + smallest sub

    // More interesting edge combos
    '{32'h00400000, 32'h00400000, 32'h00800000, 32'h00000000},  // two mid-subnormals adding to smallest norm
    '{32'h00400000, 32'h00000001, 32'h00400001, 32'h003fffff},  // mid-sub + smallest
    '{32'h00700000, 32'h000fffff, 32'h007fffff, 32'h00600001},  // combo that sums to largest sub
    '{32'h007ffffe, 32'h00000001, 32'h007fffff, 32'h007ffffd},  // just below largest sub + smallest
    '{32'h007fffff, 32'h00000002, 32'h00800001, 32'h007ffffd},  // crossing into norm
    '{32'h00000003, 32'h00000002, 32'h00000005, 32'h00000001},  // random tiny combo
    '{32'h0000ffff, 32'h0000ffff, 32'h0001fffe, 32'h00000000},  // bigger subnormals
    '{32'h007ffffe, 32'h007ffffe, 32'h00fffffc, 32'h00000000},  // 2nd largest + same
    '{32'h007ffffe, 32'h00000002, 32'h00800000, 32'h007ffffc},  // 2nd largest + 2nd smallest

    // Cross zero behavior
    '{32'h00000001, 32'h80000001, 32'h00000000, 32'h00000002},  // smallest - smallest
    '{32'h80000001, 32'h00000001, 32'h00000000, 32'h80000002},  // -smallest - smallest
    '{32'h00000001, 32'h80000000, 32'h00000001, 32'h00000001},  // smallest - (-0)
    '{32'h80000001, 32'h00000000, 32'h80000001, 32'h80000001}   // -smallest - 0
  };

  st_fpu_computation list_normal[] = '{
    '{32'h3f800000, 32'h3f8ccccd, 32'h40066666, 32'hbdcccccd},  // 1   1.0,          1.1},      
    '{32'h3fffffff, 32'h402df854, 32'h4096fc2a, 32'hbf37e151},  // 8   1.9999999,    2.7182818},      
    '{32'h42168f5c, 32'h00000000, 32'h42168f5c, 32'h42168f5c},  // 9   37.64,        0},                
    '{32'h41800000, 32'h42000000, 32'h42400000, 32'hc1800000},  // 10  16.0,         32.0},              
    '{32'h3e800000, 32'h3f000000, 32'h3f400000, 32'h3e800000}   // 11  0.25,         0.5}                
  };

  st_fpu_computation list_special[] = '{
    '{32'h00000000, 32'h3f800000, 32'h3f800000, 32'hbf800000},   // 2   0.0,          1.0},          
    '{32'h3f800000, 32'h00000000, 32'h3f800000, 32'h3f800000},   // 3   1.0,          0.0},             
    '{32'h7F800000, 32'h41200000, 32'h7f800000, 32'h7f800000},   // 4   inf,          10.0},               
    '{32'h41200000, 32'h7F800000, 32'h7f800000, 32'hff800000},   // 5   10,           inf},             
    '{32'h7F800000, 32'h00000000, 32'h7f800000, 32'h7f800000},   // 4   inf,          0.0},               
    '{32'h00000000, 32'h7F800000, 32'h7f800000, 32'hff800000},   // 5   0.0,          inf},             

    '{32'hFF800000, 32'h41200000, 32'hff800000, 32'hff800000},   // 4   -inf,          10.0},               
    '{32'h41200000, 32'hFF800000, 32'hff800000, 32'h7f800000},   // 5   10,           -inf},             
    '{32'hFF800000, 32'h00000000, 32'hff800000, 32'hff800000},   // 4   -inf,          0.0},               
    '{32'h00000000, 32'hFF800000, 32'hff800000, 32'h7f800000},   // 5   0.0,          -inf},             

    '{32'hFF800000, 32'hFF800000, 32'hff800000, 32'h7fc00000},   // 5   -inf,         -inf},             
    '{32'h7F800000, 32'h7F800000, 32'h7f800000, 32'h7fc00000},   // 5    inf,          inf},             
    '{32'hFF800000, 32'h7F800000, 32'h7fc00000, 32'hff800000},   // 5   -inf,          inf},             
    '{32'h7F800000, 32'hFF800000, 32'h7fc00000, 32'h7f800000},   // 5    inf,         -inf},             

    '{32'h7FC00000, 32'h402df854, 32'h7fc00000, 32'h7fc00000},   // 6   NAN,          2.7182818},      
    '{32'h402df854, 32'h7FC00000, 32'h7fc00000, 32'h7fc00000}    // 7   2.7182818,    NAN}
  };

  typedef enum {type_single, type_all} e_test_type;

  st_fpu_computation test_list[];
  e_test_type test_type;
  pa_fpu::e_fpu_op test_op;
  int test_index;
  int nbr_pass, nbr_fail;

  function string op_to_str(pa_fpu::e_fpu_op op);
    case(op)
      pa_fpu::op_add: return "+";
      pa_fpu::op_sub: return "-";
      pa_fpu::op_mul: return "*";
      pa_fpu::op_div: return "/";
    endcase
  endfunction

  initial begin
    test_type = type_all;
    test_index = 0;
    test_op = pa_fpu::op_add;
    test_list = list_normal;

    if(test_type == type_all) begin
      for(int i = 0; i < test_list.size(); i++) begin
        a_operand = test_list[i].a; 
        b_operand = test_list[i].b; 
        operation = test_op;
        #1us;
        $display("%53.50f(%h) %s %53.50f(%h) = %53.50f(%h, %b %b %b) : %s", $bitstoshortreal(a_operand), 
                                                                            (a_operand), 
                                                                            op_to_str(test_op),
                                                                            $bitstoshortreal(b_operand), 
                                                                            (b_operand), 
                                                                            $bitstoshortreal(ieee_packet_out),
                                                                            (ieee_packet_out),
                                                                            ieee_packet_out[31], ieee_packet_out[30:23], ieee_packet_out[22:0],
                                                                            test_op == pa_fpu::op_add ? (ieee_packet_out == test_list[i].result_add ? "PASS" : "FAIL") :
                                                                            test_op == pa_fpu::op_sub ? (ieee_packet_out == test_list[i].result_sub ? "PASS" : "FAIL") : "Fix me"
        );
      end
    end
    else if(test_type == type_single) begin
      a_operand = test_list[test_index].a; 
      b_operand = test_list[test_index].b; 
      operation = test_op;
      #1us;
      $display("%53.50f(%h) %s %53.50f(%h) = %53.50f(%h, %b %b %b) : %s", $bitstoshortreal(a_operand), 
                                                                          (a_operand), 
                                                                          op_to_str(test_op),
                                                                          $bitstoshortreal(b_operand), 
                                                                          (b_operand), 
                                                                          $bitstoshortreal(ieee_packet_out),
                                                                          (ieee_packet_out),
                                                                          ieee_packet_out[31], ieee_packet_out[30:23], ieee_packet_out[22:0],
                                                                          test_op == pa_fpu::op_add ? (ieee_packet_out == test_list[test_index].result_add ? "PASS" : "FAIL") :
                                                                          test_op == pa_fpu::op_sub ? (ieee_packet_out == test_list[test_index].result_sub ? "PASS" : "FAIL") : "Fix me"
      );
    end

    $stop;
  end

  fpu fpu_top(
    .a_operand       (a_operand),
    .b_operand       (b_operand),
    .ieee_packet_out (ieee_packet_out),
    .operation       (operation)
  );

endmodule