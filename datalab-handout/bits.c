/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~((~(~x&y)) & (~(~y&x))); // combine several NANDs
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31; //tmin32 is simply 0x80000000
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int t = x + 1;              // tmax32 is 0x7FFFFFFF. After added 1 we get 0x80000000
  return !!t & !(~(t ^ x));   // !(~(t ^ x)) should give 1 if x is tmax32. Also we need to check 0xFFFFFFFF case and that is !!t
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = 0xAA << 24 | 0xAA << 16 | 0xAA << 8 | 0xAA;  // generate a mask 10101010 10101010 10101010 10101010
  return !((x & mask) ^ mask);                            // and check with AND and XOR that all bits are on their positions
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1; // get 2^32 complement
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // First check if x matches template 0x30. If so x >= 30.
  // Then check if 4'th bit is zero. If so x <= 37.
  // Else x >= 38, and we should check that 2'd and 3'd bits are zero to ensure x <= 39
  int t0 = x >> 4;
  int t1 = t0 & 0x3;
  return !(t1 ^ 0x3) & !(t1 ^ t0) & (!(x & 0x8) | !(x & 0x6));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // if x != 0 mask = 0 else mask = -1
  int mask = (~(!(x ^ 0)) + 1);
  return (~mask & y) | (mask & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int xs = (x >> 31) & 1;                                   // get sign of x (0 or 1)
  int ys = (y >> 31) & 1;                                   // get sign of y (0 or 1)
  int diff = x + (~y + 1);                                  // get x - y
  int greater = !xs & ys;                                   // compare signs. if x >= 0 AND y < 0 then x is greater
  int less = !greater & ((xs & !ys) | ((diff >> 31) & 1));  // is (x < 0 AND y > 0) OR diff < 0 then x is less y
  int equal = !(diff);                                      // if diff == 0 then x equals y  
  return less | equal;                                      // combine those conditions together and get final result
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int sx = x >> 31;             // if x < 0 sx = -1 else sx = 0, so (sx + 1) gives 0 for negative numbers and 1 for zero
  int sy = ((x + (~0)) >> 31);  // sy = 0 for positive numbers, so (sy & 1) gives 1 for zero and negative and 0 for positive numbers
  return (sx + 1) & (sy & 1);   // combining both we get correct result
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // the task is to find the highest position of sign bit (1 for negative number and 0 for positive) + 1 for sign
  // due to howManyBits(x) == howManyBits(~x) we get x1 = x if x < 0 or ~x if x >= 0 and can do work only for 1s
  // we do a kind of binary search, checking if high half has all bits set to 1. If yes the next candidate will be low half, else high half itself
  // until there is only one bit stay. 
  int n;  
  int x1 = x ^ (~(x >> 31));
  int mask = (0xFF << 8) | 0xFF;
  int hi = (x1 >> 16) & mask;
  int lo = x1 & mask;
  int nextLow = (!(hi ^ mask) << 31) >> 31;  
  
  x1 = (hi & ~nextLow) | (lo & nextLow);
  n = 16 & nextLow;
  
  mask = 0xFF;
  hi = (x1 >> 8) & mask;
  lo = x1 & mask;
  nextLow = (!(hi ^ mask) << 31) >> 31;  
  
  x1 = (hi & ~nextLow) | (lo & nextLow);
  n += 8 & nextLow;

  mask = 0xF;
  hi = (x1 >> 4) & mask;
  lo = x1 & mask;
  nextLow = (!(hi ^ mask) << 31) >> 31;
  
  x1 = (hi & ~nextLow) | (lo & nextLow);
  n += 4 & nextLow;

  mask = 0x3;
  hi = (x1 >> 2) & mask;
  lo = x1 & mask;
  nextLow = (!(hi ^ mask) << 31) >> 31;
  
  x1 = (hi & ~nextLow) | (lo & nextLow);
  n += 2 & nextLow;
  mask = 0x1;
  hi = (x1 >> 1) & mask;
  lo = x1 & mask;
  nextLow = (!(hi ^ mask) << 31) >> 31;
  n += (1 & nextLow);
  n += nextLow & !(hi ^ lo);  
  
  return (33 + (~n + 1));
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned sign = uf & 0x80000000;
  unsigned mant = uf & 0x7FFFFF;

  if (exp == 0xFF)
    return uf;

  // denormalized case: shift uf right by 1. 
  // if mantissa equals 0x800000 it becomes 0 and exp becomes 1 and uf turns into normalized 
  if (exp == 0)
    return sign | (uf << 1);
  
  // normalized case: add 1 to exp
  return sign | (((exp + 1) & 0xFF) << 23) | mant;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int exp = ((uf >> 23) & 0xFF) - 0x7F;
  int sign = uf & 0x80000000;
  int mant = uf & 0x7FFFFF;
  int result;

  if (exp > 30)
    return 0x80000000u;

  if (exp < 0)
    return 0;
  
  result = (mant >> (30 - exp)) | (1 << exp);
  if (sign)
    result = ~result + 1;
  return result;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {  
  if (x > 127)
    return 0x7f800000;
  
  if (x < -126)
    return 0;
  
  return (0x7F + x) << 23;
}