// FPU PROTOTYPE
// This is an FPU unit that will perform addition, subtraction, multiplication, division, square root, and transcendental functions
// Totally non-optimized and for prototyping and studying purposes only!

/*
  SQRT: NEWTON-RAPHSON
    xn = 0.5(xn + A/xn)

  DOT PRODUCT:
    a dot b 
    = a0b0 + a1b1 + ... + anbn 
    = |a||b|cos(arg(a,b))

  CROSS PRODUCT:
    a cross b 
    = (a2b3 - a3b2)i + (a3b1 - a1b3)j + (a1b2 - a2b1)k
    = |a||b|sin(arg(a,b))n where n is the unit vector normal to both a & b

  APPROXIMATING LOG2:
    take exponent - 127 as starting point. exponent is the approximate log2
    because mantissa is < 1, log of mantissa is approximately equal to the mantissa itself plus a constant sigma = 0.0430357.
    hence an aproximation is (exponent - 127) + mantissa + sigma.
    log(x) = log((1+m)2^e) = e + 1 + m = e + m + sigma

  INTEGER TO FLOAT:
    exponent = 31 - #leading zeroes.
    mantissa placed on msb side with leading 1 removed

  FLOAT TO INTEGER:
    if exponent < 0, return 0
    else truncate the number 1.mantissa after #exponent places and that is the integer
    example: 1.1101010 * 2^3 = 1110. 

  OPERATIONS:
    add
    sub
    mul
    div
    sqrt
    log2

    1/a
    int2float
    float2int

  TRIGONOMETRIC FUNCTIONS:

  Slow converging series. Look at chebyshev polynomials.
    sin(x)    = x - x^3/3! + x^5/5! - x^7/7! + ...
    cos(x)    = 1 - x^2/2 + x^4/4! - x^6/6! + ...
    exp(x)    = 1 + x + x^2/2 + x^3/3! + x^4/4! + x^5/5! + ...
    ln(1+x)   = x - x^2/2 + x^3/3 - x^4/4 + x^5/5 - ...  (|x| < 1)
    arctan(x) = x - x^3/3 + x^5/5 - x^7/7 + ... (slow convergence)

  chebyshev polynomials:
    Tn   = cos(nx)
    Tn+1 = 2xTn - Tn-1
    T0 = 1, T1 = x, T2 = 2x^2-1, T3 = 4x^3 - 3x, T4 = 8x^4 - 8x^2 + 1

  Chebyshev approximations
    f           range        c0         c1          c2           c3            c4             c5
    sinπx       [-0.5,0.5]   0	        1.1336	    0           -0.13807	     0	            0.0045584
    cosπx       [-0.5,0.5]   0.472	    0	         -0.4994	     0	           0.027985	      0
    sqrt        [1,4]	       1.542	    0.49296    -0.040488	   0.0066968	  -0.0013836	    0.00030211
    log2        [1,2]	       0.54311	  0.49505	   -0.042469	   0.0048576	  -0.00062481	    8.3994e-05
    exp         [0,1]	       1.7534	    0.85039	    0.10521	     0.0087221	   0.00054344	    2.7075e-05
    (2/π)*atan  [-1,1]	     0	        0.5274	    0	          -0.030213	     0	            0.0034855

  OBSERVATIONS:
  if any number is NAN, then the result is also set to NAN, not only that, but it is set to be a copy of the first 
  NAN operand. so if operand_a is NAN, the result is set to operand_a, and vice versa. this is done so that NAN information is kept and propagated.

*/

module fpu(
  input  logic           arst,
  input  logic           clk,
  input  logic    [31:0] a_operand,
  input  logic    [31:0] b_operand,
  input pa_fpu::e_fpu_op operation, // arithmetic operation to be performed
  input  logic           start,
  output logic    [31:0] ieee_packet_out,
  output logic           cmd_end, // end of command / irq
  output logic           busy     // active high when an operation is in progress
);

  logic  [25:0] a_mantissa; // 24 bits plus 2 upper guard bits for dealing with signed arithmetic
  logic [25:-3] a_mantissa_shifted;
  logic [25:-3] a_mantissa_adjusted;
  logic   [7:0] a_exp;
  logic   [7:0] a_exp_adjusted;
  logic         a_sign;

  logic  [25:0] b_mantissa;  // 24 bits plus 2 upper guard bits for dealing with signed arithmetic
  logic [25:-3] b_mantissa_shifted;  // 24 mantissa, 2 upper guards for signed arithmetic, 3 lower rounding guard bits
  logic [25:-3] b_mantissa_adjusted; // 24 mantissa, 2 upper guards for signed arithmetic, 3 lower rounding guard bits
  logic   [7:0] b_exp;
  logic   [7:0] b_exp_adjusted;
  logic         b_sign;

  logic              sticky_bit; // sticky bit is used for whichever number has the smallest exponent and is shifted right for alignment during add or sub operations
  logic signed [8:0] ab_exp_diff;
  logic        [8:0] ab_shift_amount;

  // sign bit for result_m_addsub is at bit 25, so that we have an extra bit position at bit 24 which is the carry bit from bit 23 
  // so the idea is that we don't simply extend a mantissa value by one bit, we extend it by 2 bits so we always have one bit of space for the carry
  // that can come out of bit 23
  // addition/subtraction datapath
  logic [25:-3] result_m_addsub_prenorm;  // 24 bits plus carry plus 3 guard bits
  logic [25:-3] result_m_addsub_abs;      // 24 bits plus carry plus 3 guard bits
  logic [25:-3] result_m_addsub_norm;     // after first normalization
  logic  [25:0] result_m_addsub_rounded;  // after rounding
  logic  [25:0] result_m_addsub_renorm;   // renormalization after rounding (if there is a carry after rounding up)
  logic  [22:0] result_m_addsub;          // 23 bits for final mantissa
  logic   [7:0] result_e_addsub_prenorm;
  logic   [7:0] result_e_addsub_norm;  
  logic   [7:0] result_e_addsub_renorm;   
  logic   [7:0] result_e_addsub;
  logic         result_s_addsub;
  logic   [5:0] zcount_addsub;
  logic         addsub_guard; // guard bits
  logic         addsub_round; 
  logic         addsub_sticky;

  // multiplication datapath
  logic [47:0] product_pre_norm;     // result after multiplication
  logic [48:0] product_norm;         // after first normalization
  logic [48:0] product_renorm;       // after second normalization (after rounding)
  logic [48:0] product_rounded;      // after rounding
  logic [22:0] result_mantissa_mul;  // final value
  logic [ 7:0] result_exp_mul;       // final exponent
  logic        result_sign_mul;      // resulting sign
  logic [ 7:0] mul_exp;              // exponent sum
  logic [ 7:0] mul_exp_norm;         // normalized exponent
  logic [ 7:0] mul_exp_renorm;       // exponent after renormalization

  // division datapath 
  logic [7:0]  exp_div_prenorm;
  logic [7:0]  exp_div_norm;
  logic [23:0] div_quotient_prenorm_out;
  logic [23:0] quotient_mantissa_div_norm;
  logic [4:0]  zcount_div;
  logic [22:0] result_mantissa_div;
  logic [ 7:0] result_exp_div;
  logic        result_sign_div;
  
  // sqrt datapath
  logic [23:0] sqrt_xn_mantissa;
  logic  [7:0] sqrt_xn_exp;
  logic        sqrt_xn_sign;
  logic [23:0] sqrt_A_mantissa;
  logic  [7:0] sqrt_A_exp;
  logic        sqrt_A_sign;
  logic  [3:0] sqrt_counter;

  // fsm control
  logic start_operation_sqrt_fsm;  
  logic operation_done_sqrt_fsm;   
  logic sqrt_xn_A_wrt;
  logic sqrt_xn_a_approx_wrt;
  logic sqrt_xn_a_wrt;
  logic sqrt_xn_add_wrt;
  logic sqrt_A_a_wrt;
  logic sqrt_a_xn_wrt;
  logic sqrt_a_A_wrt;
  logic sqrt_b_xn_wrt;
  logic sqrt_b_div_wrt;

  // float2int
  logic [31:0] result_float2int;

  logic start_operation_ar_fsm;  // ...
  logic operation_done_ar_fsm;   // for handshake between main fsm and arithmetic fsm

  // logarithm
  logic [30:0] log2_prenorm;       
  logic [30:0] log2_norm;       
  logic [30:0] log2_abs;       
  logic  [7:0] log2_exp_prenorm;       
  logic  [7:0] log2_exp_norm;       
  logic  [5:0] log2_zcount;
  logic        log2_sign;

  // status
  logic a_overflow, a_underflow;
  logic b_overflow, b_underflow;
  logic a_nan, a_inf, a_pos_inf, a_neg_inf, a_zero;
  logic b_nan, b_inf, b_pos_inf, b_neg_inf, b_zero;
  // for multiplication
  logic zero_inf_or_inf_zero;
  logic inf_or_inf;
  logic zero_or_zero;
  // for division
  logic zero_and_zero;
  logic zero_inf;
  logic inf_zero;
  // unused
  logic nan_or_nan;
  logic nan_inf_or_inf_nan;
  logic zero_nan_or_nan_zero;

  // fsm states
  pa_fpu::e_main_st  curr_state_main_fsm;
  pa_fpu::e_main_st  next_state_main_fsm;
  pa_fpu::e_arith_st curr_state_arith_fsm;
  pa_fpu::e_arith_st next_state_arith_fsm;
  pa_fpu::e_sqrt_st  curr_state_sqrt_fsm;
  pa_fpu::e_sqrt_st  next_state_sqrt_fsm;

  // ---------------------------------------------------------------------------------------------------------------------------------------------------

  function integer unsigned abs(integer a);
    return a < 0 ? -a : a;
  endfunction

  // counts number of leading zeroes
  function logic [5 : 0] lzc(
    input logic [31:0] a
  );
    for(int unsigned i = 0; i < 32; i++) begin
      if(a[31 - i]) return (6)'(i);
    end

    return (6)'(32);    
  endfunction

  assign a_nan     = a_exp == 8'hff && |a_mantissa[22:0];
  assign a_zero    = a_exp == 8'h00 &&  a_mantissa[22:0] == 23'h0;
  assign a_inf     = a_exp == 8'hff &&  a_mantissa[22:0] == 23'h0;
  assign a_pos_inf = a_sign == 1'b0 &&  a_inf;
  assign a_neg_inf = a_sign == 1'b1 &&  a_inf;

  assign b_nan     = b_exp == 8'hff && |b_mantissa[22:0];
  assign b_zero    = b_exp == 8'h00 &&  b_mantissa[22:0] == 23'h0;
  assign b_inf     = b_exp == 8'hff &&  b_mantissa[22:0] == 23'h0;
  assign b_pos_inf = b_sign == 1'b0 &&  b_inf;
  assign b_neg_inf = b_sign == 1'b1 &&  b_inf;

  assign zero_or_zero         = a_zero || b_zero;
  assign zero_and_zero        = a_zero && b_zero;
  assign zero_nan_or_nan_zero = a_zero && b_nan || a_nan && b_zero;
  assign zero_inf_or_inf_zero = a_zero && b_inf || a_inf && b_zero;
  assign nan_or_nan           = a_nan  || b_nan;
  assign nan_inf_or_inf_nan   = a_nan  && b_inf || a_inf && b_nan;
  assign inf_or_inf           = a_inf  || b_inf;
  assign zero_inf             = a_zero && b_inf;
  assign inf_zero             = a_inf  && b_zero;
                     
  assign ab_exp_diff = 9'(a_exp) - 9'(b_exp); // (a|b)_exp is 8bit, ab_exp_diff is 9bit. 
                                              // thus (a|b)_exp are zero-extended to 9bit first and then an unsigned subtraction is performed
                                              // however for clarity, the operands are explicitly extended to 9 bits.

  assign ieee_packet_out = operation == pa_fpu::op_add          ? {result_s_addsub, result_e_addsub, result_m_addsub[22:0]} :
                           operation == pa_fpu::op_sub          ? {result_s_addsub, result_e_addsub, result_m_addsub[22:0]} :
                           operation == pa_fpu::op_mul          ? {result_sign_mul, result_exp_mul, result_mantissa_mul[22:0]} :
                           operation == pa_fpu::op_square       ? {result_sign_mul, result_exp_mul, result_mantissa_mul[22:0]} :
                           operation == pa_fpu::op_div          ? {result_sign_div, result_exp_div, result_mantissa_div[22:0]} :
                           operation == pa_fpu::op_sqrt         ? {1'b0, sqrt_xn_exp, sqrt_xn_mantissa[22:0]} :
                           operation == pa_fpu::op_float_to_int ? result_float2int :
                           operation == pa_fpu::op_log2         ? {log2_sign, log2_exp_norm, log2_norm[29:7]} : '0;

  assign ab_shift_amount = 9'(abs(ab_exp_diff));
  // sticky bit (guard -3) = OR of all bits from index (s-3) down to 0
  assign sticky_bit = ab_shift_amount inside {0, 1, 2} ? 1'b0 :
                      ab_shift_amount ==  3 ? (a_exp < b_exp ?  a_mantissa[0]    :  b_mantissa[0]   ) :
                      ab_shift_amount ==  4 ? (a_exp < b_exp ? |a_mantissa[1:0]  : |b_mantissa[1:0] ) :
                      ab_shift_amount ==  5 ? (a_exp < b_exp ? |a_mantissa[2:0]  : |b_mantissa[2:0] ) :
                      ab_shift_amount ==  6 ? (a_exp < b_exp ? |a_mantissa[3:0]  : |b_mantissa[3:0] ) :
                      ab_shift_amount ==  7 ? (a_exp < b_exp ? |a_mantissa[4:0]  : |b_mantissa[4:0] ) :
                      ab_shift_amount ==  8 ? (a_exp < b_exp ? |a_mantissa[5:0]  : |b_mantissa[5:0] ) :
                      ab_shift_amount ==  9 ? (a_exp < b_exp ? |a_mantissa[6:0]  : |b_mantissa[6:0] ) :
                      ab_shift_amount == 10 ? (a_exp < b_exp ? |a_mantissa[7:0]  : |b_mantissa[7:0] ) :
                      ab_shift_amount == 11 ? (a_exp < b_exp ? |a_mantissa[8:0]  : |b_mantissa[8:0] ) :
                      ab_shift_amount == 12 ? (a_exp < b_exp ? |a_mantissa[9:0]  : |b_mantissa[9:0] ) :
                      ab_shift_amount == 13 ? (a_exp < b_exp ? |a_mantissa[10:0] : |b_mantissa[10:0]) :
                      ab_shift_amount == 14 ? (a_exp < b_exp ? |a_mantissa[11:0] : |b_mantissa[11:0]) :
                      ab_shift_amount == 15 ? (a_exp < b_exp ? |a_mantissa[12:0] : |b_mantissa[12:0]) :
                      ab_shift_amount == 16 ? (a_exp < b_exp ? |a_mantissa[13:0] : |b_mantissa[13:0]) :
                      ab_shift_amount == 17 ? (a_exp < b_exp ? |a_mantissa[14:0] : |b_mantissa[14:0]) :
                      ab_shift_amount == 18 ? (a_exp < b_exp ? |a_mantissa[15:0] : |b_mantissa[15:0]) :
                      ab_shift_amount == 19 ? (a_exp < b_exp ? |a_mantissa[16:0] : |b_mantissa[16:0]) :
                      ab_shift_amount == 20 ? (a_exp < b_exp ? |a_mantissa[17:0] : |b_mantissa[17:0]) :
                      ab_shift_amount == 21 ? (a_exp < b_exp ? |a_mantissa[18:0] : |b_mantissa[18:0]) :
                      ab_shift_amount == 22 ? (a_exp < b_exp ? |a_mantissa[19:0] : |b_mantissa[19:0]) :
                      ab_shift_amount == 23 ? (a_exp < b_exp ? |a_mantissa[20:0] : |b_mantissa[20:0]) :
                      ab_shift_amount == 24 ? (a_exp < b_exp ? |a_mantissa[21:0] : |b_mantissa[21:0]) :
                      ab_shift_amount == 25 ? (a_exp < b_exp ? |a_mantissa[22:0] : |b_mantissa[22:0]) :
                      ab_shift_amount == 26 ? (a_exp < b_exp ? |a_mantissa[23:0] : |b_mantissa[23:0]) :
                      ab_shift_amount == 27 ? (a_exp < b_exp ? |a_mantissa[24:0] : |b_mantissa[24:0]) :
                      ab_shift_amount >= 28 ? (a_exp < b_exp ? |a_mantissa[25:0] : |b_mantissa[25:0]) : 1'b0;

  // ADDITION & SUBTRACTION COMBINATIONAL DATAPATH
  // if aexp < bexp, then increase aexp and right-shift a_mantissa by same number
  // else if aexp > bexp, then increase bexp and right-shift b_mantissa by same number
  // else, exponents are the same
  assign a_mantissa_shifted[25:-3] = a_exp < b_exp ? {{a_mantissa, 2'b00} >> ab_shift_amount, sticky_bit} : {a_mantissa, 3'b000};
  assign b_mantissa_shifted[25:-3] = b_exp < a_exp ? {{b_mantissa, 2'b00} >> ab_shift_amount, sticky_bit} : {b_mantissa, 3'b000};
  assign a_exp_adjusted = a_exp < b_exp ? b_exp : a_exp;
  assign b_exp_adjusted = b_exp < a_exp ? a_exp : b_exp;
  assign a_mantissa_adjusted = a_sign ? ~a_mantissa_shifted + 1'b1 : a_mantissa_shifted;
  assign b_mantissa_adjusted = b_sign ? ~b_mantissa_shifted + 1'b1 : b_mantissa_shifted;
  // sign bit for result_m_addsub is at bit 25, so that we have an extra bit position at bit 24 which is the carry bit from bit 23 
  // so the idea is that we don't simply extend a mantissa value by one bit, we extend it by 2 bits so we always have one bit of space for the carry
  // that can come out of bit 23

  // here we need to be careful, because some other operations make use of the internal add/sub circuit, for example op_sqrt makes use
  // of the addition operation. so here we make it such that if the current operation is sqrt, then we select addition instead of
  // subtraction. 
  assign result_m_addsub_prenorm = operation == pa_fpu::op_add || operation == pa_fpu::op_sqrt ? a_mantissa_adjusted + b_mantissa_adjusted :
                                                                                                 a_mantissa_adjusted - b_mantissa_adjusted;
  assign result_e_addsub_prenorm = a_exp_adjusted;
  assign result_m_addsub_abs = result_m_addsub_prenorm[25] ? -result_m_addsub_prenorm : result_m_addsub_prenorm;
  // lzc function is 32bit, hence need to add extra 3bits to left of the argument. 
  // also, the variable result_m_addsub_abs itself has an extra 2 bits (the sign bit + carry bit), 
  // so for counting leading zeroes we need to subtract the extra count of 2. hence we subtract a total of 5 from the result.
  assign zcount_addsub = lzc({3'b000, result_m_addsub_abs}) - 6'd5; // result_m_addsub_abs is 29bits wide, so add 3 extra bits to make 32 to satisfy lzc function
  
  // normalize the result
  assign result_m_addsub_norm = result_m_addsub_abs[24] ? result_m_addsub_abs >> 1 : result_m_addsub_abs << zcount_addsub; // if there was a carry bit after the addition then shift right
  assign result_e_addsub_norm = result_m_addsub_abs[24] ? result_e_addsub_prenorm + 1'b1 : result_e_addsub_prenorm - zcount_addsub;
  
  // set the guard bits
  assign {addsub_guard, addsub_round, addsub_sticky} = result_m_addsub_norm[-1:-3];
  
  // ROUND TO NEAREST TIES TO EVEN
  // if G is 0, round down
  // else if G is 1 and at least one bit after G is 1 then round up
  // else if G is 1 and all bits after that are 0 then there's a tie: if L = 0 round down else if L = 1 round up
  assign result_m_addsub_rounded = (addsub_guard && (addsub_round || addsub_sticky)) || 
                                   (addsub_guard && ~addsub_round && ~addsub_sticky && result_m_addsub_norm[0]) ? result_m_addsub_norm[25:0] + 1'b1 : result_m_addsub_norm[25:0];

  // renormalize if rounding caused a carry
  assign result_m_addsub_renorm = result_m_addsub_rounded[24] ? result_m_addsub_rounded >> 1 : result_m_addsub_rounded;
  assign result_e_addsub_renorm = result_m_addsub_rounded[24] ? result_e_addsub_norm + 1'b1 : result_e_addsub_norm;
  
  // final result
  assign {result_s_addsub, 
          result_e_addsub, 
          result_m_addsub[22:0]} = a_nan                                            ? {a_sign, a_exp, a_mantissa[22:0]} : // 'a' as NAN
                                   b_nan                                            ? {b_sign, b_exp, b_mantissa[22:0]} : // 'b' as NAN
                                   a_pos_inf && b_neg_inf || a_neg_inf && b_pos_inf ? {1'b0, 8'hFF, 23'h400000}         : // NAN
                                   a_pos_inf && b_pos_inf                           ? {1'b0, 8'hFF, 23'h000000}         : // inf
                                   a_neg_inf && b_neg_inf                           ? {1'b1, 8'hFF, 23'h000000}         : // inf
                                   a_inf                                            ? {a_sign, 8'hFF, 23'h000000}       : // inf with same sign as a
                                   b_inf                                            ? {b_sign, 8'hFF, 23'h000000}       : // inf with same sign as b
                                   result_m_addsub_abs == '0                        ? {1'b0, 8'h00, 23'h0}              : // if mantissa result is '0, then set entire result to zero including exponents
                                   {result_m_addsub_prenorm[25], result_e_addsub_renorm, result_m_addsub_renorm[22:0]};

  // MULTIPLICATION DATAPATH
  // for multiplication an example follows:
  //     1.00   minimum possible multiplication
  //     1.00
  //  01.0000   
  //   1.00     normalized and truncated

  //     1.11   maximum possible multiplication
  //     1.11
  //  11.0001
  //   1.10     normalized and truncated

  // rounding example with carry after rounding is performed: 
  //  1.11101
  //  1.11|101  bit after machine epsilon is 1, hence round up
  // 10.00      rounding up causes a carry, hence it needs another normalization
  //  1.00 * 2  hence exponent increases by 1

  // rounding example:
  //      1.111
  //      1.000
  //   01111000 multiplication result
  //   11110000 msb is 0 hence shift left
  //  100000000 rounding: bits after epsilon are all zero and adding epsilon to lsb results in even lsb, hence add epsilon, which creates a carry out
  //   10000000 finally, shift right to renormalize
  comb_mul mantissa_mul(
    .a(a_mantissa[23:0]),
    .b(b_mantissa[23:0]),
    ._signed(1'b0),
    .result(product_pre_norm)
  );
  assign mul_exp = (a_exp - 8'd127) + b_exp;
  // normalize floating point result
  assign mul_exp_norm =  product_pre_norm[47] ? mul_exp + 1'b1 : mul_exp;                  // if MSB is 1, then increment exp by one to normalize because in this case, we have two digits before the decimal point, 
  assign product_norm = ~product_pre_norm[47] ? product_pre_norm << 1 : product_pre_norm;  // and so really the result we had was 10.xxx or 11.xxx for example, and so the final exponent needs to be incremented
                                                                                           // else if the MSB of result is a 0, then shift left the result to normalize. in this case, nothing is changed in the mantissa 
                                                                                           // or exponent. we only shift here because of the way we are copying the mantissa from the result variable to the final packet.
  // rounding: round to nearest ties to even
  // if first bit after epsilon is 1, then round up (and account for possible carry out)
  // if all bits after epsilon are 0, we have a tie
  // if rounding up produces an even result, then round up (and account for possible carry out)
  // else if first bit after epsilon is 0, and at least one bit after that is a 1, then round up (and account for possible carry out)
  assign product_rounded[48:24] = product_norm[23] || 
                                 (product_norm[23:0] == '0 && ~{product_norm[47:24] + 1'b1}[0]) || 
                                (~product_norm[23] && |product_norm[22:0]) ? product_norm[47:24] + 1'b1 : product_norm[47:24];
  // now check whether there was a carry out after rounding up
  // if there was a carry, then re-normalize
  assign product_renorm = product_rounded[48] ? product_rounded >> 1 : product_rounded; // if there was a carry, then shift right (divided by 2)
  assign mul_exp_renorm = product_rounded[48] ? mul_exp_norm + 1'b1  : mul_exp_norm;    // and increase exponent
  // output result to final variables. but before that, test for special cases.
  assign {result_sign_mul, 
          result_exp_mul, 
          result_mantissa_mul} = a_nan                ?  {a_sign, a_exp, a_mantissa[22:0]}    : // a
                                 b_nan                ?  {b_sign, b_exp, b_mantissa[22:0]}    : // b
                                 zero_inf_or_inf_zero ?  {1'b0, 8'hFF, 23'h400000}            : // NAN
                                 inf_or_inf           ?  {a_sign ^ b_sign, 8'hFF, 23'h000000} : // inf
                                 zero_or_zero         ?  {a_sign ^ b_sign, 8'h00, 23'h000000} : // zero
                                 {a_sign ^ b_sign, mul_exp_renorm, product_renorm[46:24]};           

  // ---------------------------------------------------------------------------------------------------------------------------------------------------

  // DIVISION DATAPATH
  comb_div24_frac div24_frac(
    .a(a_mantissa[23:0]),
    .b(b_mantissa[23:0]),
    .quotient(div_quotient_prenorm_out[23:0])
  );
  assign exp_div_prenorm            = (a_exp - b_exp) + 8'd127;
  assign zcount_div                 = lzc({8'b00000000, div_quotient_prenorm_out[23:0]}) - 4'd8;
  assign quotient_mantissa_div_norm = div_quotient_prenorm_out << zcount_div;
  assign exp_div_norm               = exp_div_prenorm - zcount_div;
  assign {result_sign_div, 
          result_exp_div, 
          result_mantissa_div[22:0]} = a_nan         ?  {a_sign, a_exp, a_mantissa[22:0]}    : // a
                                       b_nan         ?  {b_sign, b_exp, b_mantissa[22:0]}    : // b
                                       zero_inf      ?  {a_sign ^ b_sign, 8'h00, 23'h000000} : // zero
                                       inf_zero      ?  {1'b0, 8'hFF, 23'h400000}            : // NAN
                                       a_inf         ?  {a_sign ^ b_sign, 8'hFF, 23'h000000} : // inf
                                       b_inf         ?  {a_sign ^ b_sign, 8'h00, 23'h000000} : // zero
                                       zero_and_zero ?  {1'b0, 8'hFF, 23'h400000}            : // NAN
                                       a_zero        ?  {a_sign ^ b_sign, 8'h00, 23'h000000} : // zero
                                       b_zero        ?  {1'b0, 8'hFF, 23'h000000}            : // inf
                                       {a_sign ^ b_sign, exp_div_norm, quotient_mantissa_div_norm[22:0]};           

  // ---------------------------------------------------------------------------------------------------------------------------------------------------

  // LOGARITHM TO BASE 2
  // aliasing the floating point number as a new number such that (exponent-127) is the integral part, and mantissa is the fractional part
  // then adding a fractional error term gives the approximate log2 of the floating point.
  assign log2_prenorm = {a_operand[30:23] - 8'd127, a_operand[22:0]} + {8'b0, 23'b00001011000001000110011};
  assign log2_exp_prenorm = 8'd7;
  assign log2_abs = log2_prenorm[30] ? -log2_prenorm : log2_prenorm;
  assign log2_sign = log2_prenorm[30];
  assign log2_zcount = lzc({1'b0, log2_abs}) - 1;
  assign log2_norm = log2_abs << log2_zcount;
  assign log2_exp_norm = 8'(9'(log2_exp_prenorm) - 9'(log2_zcount)) + 8'd127;

  // ---------------------------------------------------------------------------------------------------------------------------------------------------

  // REGISTER LOADING
  always_ff @(posedge clk, posedge arst) begin
    if(arst) begin
      a_mantissa <= '0;
      a_exp      <= '0;
      a_sign     <= '0;
      b_mantissa <= '0;
      b_exp      <= '0;
      b_sign     <= '0;
    end   
    else begin
      if(next_state_arith_fsm == pa_fpu::arith_load_operands_st) begin
        a_mantissa <= {2'b00, 1'b1, a_operand[22:0]};
        a_exp      <= a_operand[30:23];
        a_sign     <= a_operand[31];
        b_mantissa <= {2'b00, 1'b1, b_operand[22:0]};
        b_exp      <= b_operand[30:23];
        b_sign     <= b_operand[31];
      end
      if(sqrt_a_xn_wrt) begin
        a_mantissa <= {2'b00, sqrt_xn_mantissa};
        a_exp      <= sqrt_xn_exp;
        a_sign     <= sqrt_xn_sign;
      end
      else if(sqrt_a_A_wrt) begin
        a_mantissa <= {2'b00, sqrt_A_mantissa};
        a_exp      <= sqrt_A_exp;
        a_sign     <= sqrt_A_sign;
      end
      if(sqrt_b_xn_wrt) begin
        b_mantissa <= {2'b00, sqrt_xn_mantissa};
        b_exp      <= sqrt_xn_exp;
        b_sign     <= sqrt_xn_sign;
      end
      else if(sqrt_b_div_wrt) begin
        b_mantissa <= {2'b00, 1'b1, result_mantissa_div};
        b_exp      <= result_exp_div;
        b_sign     <= result_sign_div;
      end
    end
  end

  // ---------------------------------------------------------------------------------------------------------------------------------------------------

  // SQRT DATAPATH
  always_ff @(posedge clk, posedge arst) begin
    if(arst) begin
      sqrt_xn_mantissa <= '0;
      sqrt_xn_exp      <= '0;
      sqrt_xn_sign     <= '0;
      sqrt_A_mantissa  <= '0;
      sqrt_A_exp       <= '0;
      sqrt_A_sign      <= '0;
      sqrt_counter     <= '0;
    end
    else begin
      if(next_state_sqrt_fsm == pa_fpu::sqrt_start_st) begin
        sqrt_counter <= 0;
      end
      else if(next_state_sqrt_fsm == pa_fpu::sqrt_mov_xn_a_dec_exp_st) begin
        sqrt_counter <= sqrt_counter + 4'd1;
      end
      if(sqrt_xn_A_wrt) begin
        sqrt_xn_mantissa <= sqrt_A_mantissa;
        sqrt_xn_exp      <= sqrt_A_exp;
        sqrt_xn_sign     <= 1'b0;
      end
      else if(sqrt_xn_a_approx_wrt) begin
        sqrt_xn_mantissa <= a_mantissa; 
        //sqrt_xn_exp      <= a_exp - 8'd1;
        // 9'b110000001 = -127 with 1 bit extended for signed arithmetic
        //sqrt_xn_exp      <= (({1'b0, a_exp} + 9'b110000001) >> 1) + 9'd127 ; // divide a_exp by 2. hence initial approx to A = m*2^E  is  m*e^(E/2) which is very close to its square root.
        // a_exp is biased. shifting it by 1 divides the bias 127 by 2 as well, hence add back 127/2 = 63
        sqrt_xn_exp      <= (a_exp >> 1) + 9'd63 ; // divide a_exp by 2. hence initial approx to A = m*2^E  is  m*e^(E/2) which is very close to its square root.
        sqrt_xn_sign     <= a_sign;
      end
      else if(sqrt_xn_a_wrt) begin
        sqrt_xn_mantissa <= a_mantissa;
        sqrt_xn_exp      <= a_exp;
        sqrt_xn_sign     <= a_sign;
      end
      else if(sqrt_xn_add_wrt) begin
        sqrt_xn_mantissa <= {1'b1, result_m_addsub[22:0]};
        sqrt_xn_exp      <= result_e_addsub - 8'd1;
        sqrt_xn_sign     <= result_s_addsub;
      end
      if(sqrt_A_a_wrt) begin
        sqrt_A_mantissa <= a_mantissa;
        sqrt_A_exp      <= a_exp;
        sqrt_A_sign     <= a_sign;
      end
    end
  end

  // ---------------------------------------------------------------------------------------------------------------------------------------------------

  // FLOAT2INT
  // if exponent < 0, return 0
  // else truncate the number 1.mantissa after #exponent places and that is the integer
  // example: 1.1101010 * 2^3 = 1110. 
  always_comb begin
    logic [8:0] shift;
    logic [31:0] intval;
    intval = '0;
    if(9'(a_exp) - 9'd127 < 0) result_float2int = 32'b0;
    else begin
      shift = 9'(a_exp) - 9'd127;
      for(int i = 0; i <= shift; i++) begin
        if(i > 23)
          intval[shift - i] = 1'b0; // if exponent larger than 23, then the 2^shift factor moves the decimal point beyond bit 0 of mantissa, hence fill with 0's
        else
          intval[shift - i] = a_mantissa[23 - i];
      end
      result_float2int = intval;
    end
  end

  // sin x
  // x - x^3/6 + x^5/120 - x^7/5040
  // 
  // 

  // ---------------------------------------------------------------------------------------------------------------------------------------------------

  // MAIN FSM
  // next state assignments
  always_comb begin
    next_state_main_fsm = curr_state_main_fsm;

    case(curr_state_main_fsm)
      pa_fpu::main_idle_st: 
        if(start) next_state_main_fsm = pa_fpu::main_wait_st;
      
      pa_fpu::main_wait_st: 
        if(operation_done_ar_fsm == 1'b1) next_state_main_fsm = pa_fpu::main_finish_st;

      pa_fpu::main_finish_st:
        if(operation_done_ar_fsm == 1'b0) next_state_main_fsm = pa_fpu::main_wait_start_low_st;

      pa_fpu::main_wait_start_low_st:
        if(start == 1'b0) next_state_main_fsm = pa_fpu::main_idle_st;

      default:
        next_state_main_fsm = pa_fpu::main_idle_st;
    endcase
  end

  // main fsm
  // output assignments
  always_ff @(posedge clk, posedge arst) begin
    if(arst) begin
      start_operation_ar_fsm <= 1'b0;
      cmd_end                <= 1'b0;             
      busy                   <= 1'b0;         
    end
    else begin
      case(next_state_main_fsm)
        pa_fpu::main_idle_st: begin
          start_operation_ar_fsm <= 1'b0;
          cmd_end                <= 1'b0;             
          busy                   <= 1'b0;         
        end
        pa_fpu::main_wait_st: begin
          start_operation_ar_fsm <= 1'b1;
          cmd_end                <= 1'b0;             
          busy                   <= 1'b1;         
        end
        pa_fpu::main_finish_st: begin
          start_operation_ar_fsm <= 1'b0;
          cmd_end                <= 1'b0;             
          busy                   <= 1'b1;         
        end
        pa_fpu::main_wait_start_low_st: begin
          start_operation_ar_fsm <= 1'b0;
          cmd_end                <= 1'b1;             
          busy                   <= 1'b1;         
        end
      endcase  
    end
  end

  // ---------------------------------------------------------------------------------------------------------------------------------------------------

  // ARITHMETIC FSM
  // next state assignments
  always_comb begin
    next_state_arith_fsm = curr_state_arith_fsm;

    case(curr_state_arith_fsm)
      pa_fpu::arith_idle_st: 
        if(start_operation_ar_fsm)
          next_state_arith_fsm = pa_fpu::arith_load_operands_st;

      pa_fpu::arith_load_operands_st:
        case(operation)
          pa_fpu::op_add:
            next_state_arith_fsm = pa_fpu::arith_add_st;
          pa_fpu::op_sub:
            next_state_arith_fsm = pa_fpu::arith_sub_st;
          pa_fpu::op_mul:
            next_state_arith_fsm = pa_fpu::arith_mul_st;
          pa_fpu::op_div:
            next_state_arith_fsm = pa_fpu::arith_div_st;
          pa_fpu::op_sqrt:
            next_state_arith_fsm = pa_fpu::arith_sqrt_st;
          pa_fpu::op_log2:
            next_state_arith_fsm = pa_fpu::arith_log2_st;
          pa_fpu::op_float_to_int:
            next_state_arith_fsm = pa_fpu::arith_float2int_st;
        endcase

      pa_fpu::arith_add_st:
        next_state_arith_fsm = pa_fpu::arith_result_valid_st;

      pa_fpu::arith_sub_st:
        next_state_arith_fsm = pa_fpu::arith_result_valid_st;

      pa_fpu::arith_mul_st:
        next_state_arith_fsm = pa_fpu::arith_result_valid_st;

      pa_fpu::arith_div_st:
        next_state_arith_fsm = pa_fpu::arith_result_valid_st;

      pa_fpu::arith_sqrt_st:
        if(operation_done_sqrt_fsm == 1'b1) next_state_arith_fsm = pa_fpu::arith_sqrt_done_st;
      pa_fpu::arith_sqrt_done_st:
        if(operation_done_sqrt_fsm == 1'b0) next_state_arith_fsm = pa_fpu::arith_result_valid_st;

      pa_fpu::arith_log2_st:
        next_state_arith_fsm = pa_fpu::arith_result_valid_st;

      pa_fpu::arith_float2int_st:
        next_state_arith_fsm = pa_fpu::arith_result_valid_st;

      pa_fpu::arith_result_valid_st:
        if(start_operation_ar_fsm == 1'b0) next_state_arith_fsm = pa_fpu::arith_idle_st;

      default:
        next_state_arith_fsm = pa_fpu::arith_idle_st;
    endcase
  end

  // ARITHMETIC FSM
  // output assignments
  always_ff @(posedge clk, posedge arst) begin
    if(arst) begin
      operation_done_ar_fsm <= 1'b0;
      start_operation_sqrt_fsm <= 1'b0;
    end
    else begin
      case(next_state_arith_fsm)
        pa_fpu::arith_idle_st: begin
          operation_done_ar_fsm <= 1'b0;
          start_operation_sqrt_fsm <= 1'b0;
        end
        pa_fpu::arith_load_operands_st: begin
          operation_done_ar_fsm <= 1'b0;
          start_operation_sqrt_fsm <= 1'b0;
        end
        pa_fpu::arith_add_st: begin
          operation_done_ar_fsm <= 1'b0;
          start_operation_sqrt_fsm <= 1'b0;
        end
        pa_fpu::arith_sub_st: begin
          operation_done_ar_fsm <= 1'b0;
          start_operation_sqrt_fsm <= 1'b0;
        end
        pa_fpu::arith_mul_st: begin
          operation_done_ar_fsm   <= 1'b0;
          start_operation_sqrt_fsm <= 1'b0;
        end
        pa_fpu::arith_div_st: begin
          operation_done_ar_fsm <= 1'b0;
          start_operation_sqrt_fsm <= 1'b0;
        end
        pa_fpu::arith_sqrt_st: begin
          operation_done_ar_fsm <= 1'b0;
          start_operation_sqrt_fsm <= 1'b1;
        end
        pa_fpu::arith_sqrt_done_st: begin
          operation_done_ar_fsm <= 1'b0;
          start_operation_sqrt_fsm <= 1'b0;
        end
        pa_fpu::arith_log2_st: begin
          operation_done_ar_fsm <= 1'b0;
          start_operation_sqrt_fsm <= 1'b0;
        end
        pa_fpu::arith_float2int_st: begin
          operation_done_ar_fsm <= 1'b0;
          start_operation_sqrt_fsm <= 1'b0;
        end
        pa_fpu::arith_result_valid_st: begin
          operation_done_ar_fsm <= 1'b1;
          start_operation_sqrt_fsm <= 1'b0;
        end
      endcase  
    end
  end

  // ---------------------------------------------------------------------------------------------------------------------------------------------------

  // SQRT FSM
  // next state assignments
  // xn = 0.5(xn + A/xn)
  always_comb begin
    next_state_sqrt_fsm = curr_state_sqrt_fsm;

    case(curr_state_sqrt_fsm)
      pa_fpu::sqrt_idle_st: 
        if(start_operation_sqrt_fsm) next_state_sqrt_fsm = pa_fpu::sqrt_check_exceptional_st;
      // check if 'a' is a special value
      pa_fpu::sqrt_check_exceptional_st:
        if(a_nan || a_inf || a_zero) next_state_sqrt_fsm = pa_fpu::sqrt_exceptional_st;
        else next_state_sqrt_fsm = pa_fpu::sqrt_start_st;
      // set A = a_mantissa (A = number whose sqrt is requested)
      // set xn to initial guess 
      // set counter for number of steps
      pa_fpu::sqrt_start_st: 
        next_state_sqrt_fsm = pa_fpu::sqrt_div_setup_st;
      // set a_mantissa = A, a_exp = A_exp
      // set b_mantissa = xn, b_exp = xn_exp
      pa_fpu::sqrt_div_setup_st: begin
        next_state_sqrt_fsm = pa_fpu::sqrt_addition_st;
      end
      // set a_mantissa <= xn, a_exp = xn_exp
      // set b_mantissa <= result_mantissa_div, b_exp = result_exp_div
      pa_fpu::sqrt_addition_st: begin
        next_state_sqrt_fsm = pa_fpu::sqrt_mov_xn_a_dec_exp_st;
      end
      // perform addition during this clock cycle
      // set xn = result_m_addsub, while decreasing xn_exp by 1
      // dec sqrt_counter when entering this state
      // check sqrt_counter == 4
      pa_fpu::sqrt_mov_xn_a_dec_exp_st: begin
        if(sqrt_counter == 4'd4) next_state_sqrt_fsm = pa_fpu::sqrt_result_valid_st;
        else next_state_sqrt_fsm = pa_fpu::sqrt_div_setup_st;
      end
      // if 'a' was a exceptional value then set final result to exceptionl value
      pa_fpu::sqrt_exceptional_st:
        next_state_sqrt_fsm = pa_fpu::sqrt_result_valid_st;
      pa_fpu::sqrt_result_valid_st:
        if(start_operation_sqrt_fsm == 1'b0) next_state_sqrt_fsm = pa_fpu::sqrt_idle_st;
      default:
        next_state_sqrt_fsm = pa_fpu::sqrt_idle_st;
    endcase
  end

  // SQRT FSM
  // output assignments
  always_ff @(posedge clk, posedge arst) begin
    if(arst) begin
      operation_done_sqrt_fsm <= 1'b0;
      sqrt_xn_A_wrt           <= 1'b0;
      sqrt_xn_a_approx_wrt    <= 1'b0;
      sqrt_xn_a_wrt           <= 1'b0;
      sqrt_xn_add_wrt         <= 1'b0;
      sqrt_A_a_wrt            <= 1'b0;
      sqrt_a_xn_wrt           <= 1'b0;
      sqrt_a_A_wrt            <= 1'b0;
      sqrt_b_xn_wrt           <= 1'b0;
      sqrt_b_div_wrt          <= 1'b0;
    end
    else begin
      case(next_state_sqrt_fsm)
        pa_fpu::sqrt_idle_st: begin
          operation_done_sqrt_fsm <= 1'b0;
          sqrt_xn_A_wrt           <= 1'b0;
          sqrt_xn_a_approx_wrt    <= 1'b0;
          sqrt_xn_a_wrt           <= 1'b0;
          sqrt_xn_add_wrt         <= 1'b0;
          sqrt_A_a_wrt            <= 1'b0;
          sqrt_a_xn_wrt           <= 1'b0;
          sqrt_a_A_wrt            <= 1'b0;
          sqrt_b_xn_wrt           <= 1'b0;
          sqrt_b_div_wrt          <= 1'b0;
        end
        pa_fpu::sqrt_check_exceptional_st: begin
          operation_done_sqrt_fsm <= 1'b0;
          sqrt_xn_A_wrt           <= 1'b0;
          sqrt_xn_a_wrt           <= 1'b0;
          sqrt_xn_a_approx_wrt    <= 1'b0;
          sqrt_xn_add_wrt         <= 1'b0;
          sqrt_A_a_wrt            <= 1'b0;
          sqrt_a_xn_wrt           <= 1'b0;
          sqrt_a_A_wrt            <= 1'b0;
          sqrt_b_xn_wrt           <= 1'b0;
          sqrt_b_div_wrt          <= 1'b0;
        end
        // set A = a_mantissa (A = number whose sqrt is requested)
        // set xn to initial guess
        // set counter for number of steps
        pa_fpu::sqrt_start_st: begin
          operation_done_sqrt_fsm <= 1'b0;
          sqrt_xn_A_wrt           <= 1'b0;
          sqrt_xn_a_wrt           <= 1'b0;
          sqrt_xn_a_approx_wrt    <= 1'b1;
          sqrt_xn_add_wrt         <= 1'b0;
          sqrt_A_a_wrt            <= 1'b1;
          sqrt_a_xn_wrt           <= 1'b0;
          sqrt_a_A_wrt            <= 1'b0;
          sqrt_b_xn_wrt           <= 1'b0;
          sqrt_b_div_wrt          <= 1'b0;
        end
        // set a_mantissa = A, a_exp = A_exp
        // set b_mantissa = xn, b_exp = xn_exp
        pa_fpu::sqrt_div_setup_st: begin
          operation_done_sqrt_fsm <= 1'b0;
          sqrt_xn_A_wrt           <= 1'b0;
          sqrt_xn_a_wrt           <= 1'b0;
          sqrt_xn_a_approx_wrt    <= 1'b0;
          sqrt_xn_add_wrt         <= 1'b0;
          sqrt_A_a_wrt            <= 1'b0;
          sqrt_a_xn_wrt           <= 1'b0;
          sqrt_a_A_wrt            <= 1'b1;
          sqrt_b_xn_wrt           <= 1'b1;
          sqrt_b_div_wrt          <= 1'b0;
        end
        // set a_mantissa <= xn, a_exp = xn_exp
        // set b_mantissa <= result_mantissa_div, b_exp = result_exp_div
        // perform addition during this clock cycle
        pa_fpu::sqrt_addition_st: begin
          operation_done_sqrt_fsm <= 1'b0;
          sqrt_xn_A_wrt           <= 1'b0;
          sqrt_xn_a_wrt           <= 1'b0;
          sqrt_xn_a_approx_wrt    <= 1'b0;
          sqrt_xn_add_wrt         <= 1'b0;
          sqrt_A_a_wrt            <= 1'b0;
          sqrt_a_xn_wrt           <= 1'b1;
          sqrt_a_A_wrt            <= 1'b0;
          sqrt_b_xn_wrt           <= 1'b0;
          sqrt_b_div_wrt          <= 1'b1;
        end
        // transfer addition result to xn, while decreasing xn_exp by 1
        // inc sqrt_counter
        pa_fpu::sqrt_mov_xn_a_dec_exp_st: begin
          operation_done_sqrt_fsm <= 1'b0;
          sqrt_xn_A_wrt           <= 1'b0;
          sqrt_xn_a_wrt           <= 1'b0;
          sqrt_xn_a_approx_wrt    <= 1'b0;
          sqrt_xn_add_wrt         <= 1'b1;
          sqrt_A_a_wrt            <= 1'b0;
          sqrt_a_xn_wrt           <= 1'b0;
          sqrt_a_A_wrt            <= 1'b0;
          sqrt_b_xn_wrt           <= 1'b0;
          sqrt_b_div_wrt          <= 1'b0;
        end
        pa_fpu::sqrt_exceptional_st: begin
          operation_done_sqrt_fsm <= 1'b0;
          sqrt_xn_A_wrt           <= 1'b0;
          sqrt_xn_a_wrt           <= 1'b0;
          sqrt_xn_a_approx_wrt    <= 1'b0;
          sqrt_xn_add_wrt         <= 1'b0;
          sqrt_A_a_wrt            <= 1'b0;
          sqrt_a_xn_wrt           <= 1'b0;
          sqrt_a_A_wrt            <= 1'b0;
          sqrt_b_xn_wrt           <= 1'b0;
          sqrt_b_div_wrt          <= 1'b0;
        end
        pa_fpu::sqrt_result_valid_st: begin
          operation_done_sqrt_fsm <= 1'b1;
          sqrt_xn_A_wrt           <= 1'b0;
          sqrt_xn_a_wrt           <= 1'b0;
          sqrt_xn_a_approx_wrt    <= 1'b0;
          sqrt_xn_add_wrt         <= 1'b0;
          sqrt_A_a_wrt            <= 1'b0;
          sqrt_a_xn_wrt           <= 1'b0;
          sqrt_a_A_wrt            <= 1'b0;
          sqrt_b_xn_wrt           <= 1'b0;
          sqrt_b_div_wrt          <= 1'b0;
        end
      endcase  
    end
  end

  // next state clocking
  always_ff @(posedge clk, posedge arst) begin
    if(arst) begin
      curr_state_main_fsm  <= pa_fpu::main_idle_st;
      curr_state_arith_fsm <= pa_fpu::arith_idle_st;
      curr_state_sqrt_fsm  <= pa_fpu::sqrt_idle_st;
    end
    else begin
      curr_state_main_fsm  <= next_state_main_fsm;
      curr_state_arith_fsm <= next_state_arith_fsm;
      curr_state_sqrt_fsm  <= next_state_sqrt_fsm;
    end
  end

endmodule
