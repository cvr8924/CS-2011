/*
 * CS:APP Data Lab
 *
 * Jonathan Lopez
 * jrlopez@wpi.edu
 * CS 2011 - B term '21
 * Data Lab
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
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //ECE major here
  //NAND gates are universal gates can be used to create all other gates like XOR. ECE 3829, ECE 2029
  //Another puzzle you could use for this class is the same but only use NOR gates (~ and | only)
  return ~(~(~(x & y) & x) & ~(~(x & y) & y));
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  //left shift by 31
  //100000...
  //Done in Lab
  return 1 << 31;
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
  //max 2's comp is 01111... for as many bits as our machines (it's 32)
  //we could use overflow... if it is Tmax...
  // but we need to check negative MSB
  int negHa = !(1 + x);
  //overflow part
  int overflowHa = (x + 2) + x;
  //use and gate
  return !overflowHa & !negHa;
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
  //can't have bigger then 0xFF so we need to shift over to create a mask
  //0xAA is the largest we can have
  int mask = (0xAA << 24) + (0xAA << 16) + (0xAA << 8) + 0xAA; //bit shift into mask
  int x_and_mask = x & mask; // finding all  odds bits need AND gate
  //now need logical not and or gate to get the desire output of 1. NOR gate
  return !(x_and_mask ^ mask);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //in class notes
  return ~x + 0x01;
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
  //define bounds first
  //0x30 <= x <= 0x39
  //need to get sign bit right shift of x
  int signShift = 1 << 31;
  //define our bounds now with ~ sign (binary ones comp)
  int lwrB = ~0x30;//lower will be added to x later
  int uprB = ~(signShift | 0x39); //upper will be added to x later to see if it's in range.
  //now the "make shift if statements" to check sign bit
  lwrB = signShift & (lwrB + 1 + x) >> 31; //offset for 0-9
  uprB = signShift & (uprB + x) >> 31;
  //OR gate them
  return !(lwrB | uprB);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //short hand if else
  //need x in a 1 or 0 form
  x = !!x; //double excamation poinbt makes this an int
  x = ~x + 1;//negate /invert
  //AND them, then OR gate 
  return (~x & z) | (x & y);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //first we need a way to deal with negative numbers
  //check x sign shift over sign bit and check with AND
  int negHaX = (x >> 31) & 1;
  // now do the same with y
  int negHaY = (y >> 31) & 1;
  //we can calc y - x and check to see if it's either x is a neagtive number or the difference below is positive
  //use negate puzzle here -x +y
  int ysubtractx =  (~x + 0x01) + y;
  //check sign bit to see if it's difference of the above operation is positive AND gate it with 1 to check to see if it's 1
  int ysubtractxSign = (ysubtractx >> 31) & 1;
  //using demorgans laws to get the desired output
  //opposite sign y and AND it with x
  // also we want an  not an XOR for the sign x and sign Y  to see if x is less than or the difference is positive
  //last or gate these two
  return ((!negHaY) & negHaX) | (!(negHaY ^ negHaX) & (!ysubtractxSign));
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
  //1 in sign bit if neg AND with 1 if it is
  //check sign bit and shift check 2's comp
  //0 comps -1 
  //~ flips 
  //check sign bit and AND it with 1 to check if it's the same
  //we canc compact into 1 line
  return (((~x) & (~(~x + 1))) >> 31 ) & 1;
  //error missing parens
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
  //done in lab
  int pos;
  int zc;
  int sign = x >> 31;
  x = ((sign & (~x)) | (~sign & (x)));
  zc = !(x^0);
  pos = !!(x >> 16) << 4;
  pos |= !!(x >> (8 + pos)) << 3;
  pos |= !!(x >> (4 + pos)) << 2;
  pos |= !!(x >> (2 + pos)) << 1;
  pos |= !!(x >> (1 + pos)); //shift by zero
  return pos + 2 + (~zc + 1);
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
  //done in lab
  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF; //exponent
  //mantissa
  unsigned frac =  uf & 0x7FFFFF;
  if (exp == 0){
    frac *= 2;
    if (frac > 0x7FFFFF){
      exp = 1;
      frac = frac & 0x7FFFFF;
    } 
  } else if (exp < 0xFF){
      exp++;
      if (exp == 0xFF){
        frac = 0;
      }
  }
  return (sign << 31) | (exp << 23) | frac;
  //error here
  //whoops used 6 F's in in 0xFFFFFF when it's supoosed to be 5.
  //can't count smh
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
  //disassemble the 32 bit fp number
  //sign then exp then frac
  unsigned signOfFloat = uf >> 31;
  //need 8 bits so we mask it
  unsigned expPart = (uf >> 23) & 0xFF; //shift 23 over from the mantissa start
  //the rest is the frac or mantissa
  unsigned fracPart = uf & 0x7FFFFF;
  //from class we need the bias
  unsigned biasFloat = 0x7F;
  
  //might need
  unsigned sol = 0;

  //now that we've taken care of these parts we can create the unsigned int to put together the solution
  sol = fracPart; // copy old frac part we'll be needing later to assemble the unsigned int
  //we need to becareful of the Not a Number condition
  //this case return 0x80000000u as said above
  //two case can be overflow not a number and infinity
  if (expPart == 0xFF){
    return 0x80000000u;
  }
  //from class we talked about normailzed and denormalized cases if less than the bias return 0
  //in the normal it will return the exp part - bias
  if (expPart < biasFloat){
    return 0;
  }
  expPart = expPart - biasFloat;
  //now check if greater than 31
  //cant do this before the line above
  if (expPart >= 31){
    return 0x80000000u;
  }
  
  if (expPart > 22){ //if exp is greater then 22 slots shift over how many spot the exp part minus the mantissa
    sol = fracPart << (expPart - 23); 
  }else{ //same as above but if it fails its shifted the other way and 23 - exp part; rounding
    sol = fracPart >> (23 - expPart); 
  }
  //we must add 1 for the normal case and then add the sign back in that we got at the very start
  sol = sol + (1 << expPart);
  if (signOfFloat == 1){
    sol = -sol;
  }
  return sol;
}
/* #include "floatPower2.c" commented by Weinstock request by MCV 20210929-1619 */
/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
  //exponent bits shifted by 23 because of the mantissa
  unsigned exp = 0xFF << 23;
  // we alse want the sign bit which is the 31 bits deep XOR them to check the value
  unsigned signHa = uf ^ 0x80000000;
  //we have to becareful if it turns out to be not a number (NAN)
  //using an if and a AND we can check to see if the frac have 1 bit and exp bits have 1's its then a NAN
  //check if the exp and sign are the same as exp. if yes then it 1 case for being not a number
  //check the mantissa lower 23 bits with bit flipped 0 and ANDing it with the uf number input. 
  //This check if any bits that are high in the lower 23
  if (((exp & signHa) ==  exp) && (((1 << 23) + (~0)) & uf)){
    return uf;
  } 
  //error here
  //whyyyyy
  //return wrong answer
  return signHa;
}