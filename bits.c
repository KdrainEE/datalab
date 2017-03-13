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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
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
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
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
   <http://www.gnu.org/licenses/>.  */
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
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {///////////////////////////////////////////////////////////////done

	return ~(~x&~y);
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {//////////////////////////////////////////////////////////////done
  return !(x^y);
}
/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {////////////////////////////////////////////////////////////////////done
	int a = 0x55;
	int mask = (a<<24)|(a<<16)|(a<<8)|a;
  return !!(x&mask);
}
/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {//////////////////////////////////////////////////////////////////done
	int a = 0x55;
	int mask = (a<<24)|(a<<16)|(a<<8)|a;
	x = x&mask;
  return !(x^mask);
}
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateLeft(int x, int n) { //////////////////need to check
	int shift = 31-n;
	int a = x >> shift;
	x = (x >> n)&(~((1<<n)-1));
	return (a<<shift)&x;

}
/*
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x) { //////////////// need to check
  unsigned int a;
	a = x;
	a = a | a >> 1;
	a = a | a >> 2;
	a = a | a >> 4;
	a = a | a >> 8;
	a = a | a >> 16;
	a = a & ((~a >> 1)^(0x8 << 28));
	return a;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {//////////////////////////////////////////////////////////////done

  return !((~x^(x+1))|!(~x));
}
/*
 * leastBitPos - return a mask that marks the position of the
 *   least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x) {///////////////////////////////////////////////////////////done
  return x&(~x+1);
}
/*
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {///////////////////////need to check
  int subtraction, samesign samAsy, ret;
	subtraction = x+1+~y;
	samesign = x^y;
	sameAsy = ~(subtraction^y);
	ret = ~(samesign&sameAsy);
	return 1&(ret>>31);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {///////////////////////need to check
	int nX = x+1;
	int aY = nX+y;//this is negative is x>y
	int sign = (aY>>31)&1;
	//check boundary conditions
	int leftBitMask = 1<<31;
	int xLeftBit = leftBitMask&x;
	int yLeftBit = leftBitMask&y;
	int XORD = xLeftBit^yLeftBit;
	XORD = (XORD>>31)&1;

	return (XORD&(xLeftBit>>31))|(!sign&!XORD);

}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {/////////////////////////////need to test
    int xSign =(x>>31)&1;
		int timesTwo = x+x;
		int timesTwoSign = (timesTwo>>31)&1;
		int timesThree = timesTwo+x;
		int timesThreeSign = (timesThree>>31)&1;
		int overflow = (((xSign^timesTwoSign)|(timesTwoSign^timesThreeSign))<<31)>>31;
		int possibleOverflow = (~(x>>31))^(0x1<<31);
		return (overflow&possibleOverflow)|((~overflow)&timesThree);
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {/////////////////////////////////////////////////done
	int sign = (x>>31)&1;
    int bias = (sign<<n) + ~sign + 1;
    return (x + bias)>>n;
}
/*
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) { ///////////////////////////////done
	unsigned abs = uf&(~(1<<31));
	unsigned minNan = (0x7f8<<20)+1;
	if(abs >=minNan){
		return uf;
	}
	else{
  		return abs;
	}
}
/*
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {///////////////////////////need to checked
  int round, sign, EXP, maskEXP, maskSign, maskEM, maskSM, tmp;
	round = !((uf&3)^3);
	maskSign = 0x8<<28;
	maskEXP =(0x7f<<31)|(1<<23);
	maskM = (1<<23)-1;
	maskEM = (1<<31)-1;
	maskSM = (0x8<<28)|((1<<23)-1);
	EXP = uf&maskEXP;
	sign = uf&maskSign;
	//NAN or infinity
	if (EXP == maskEXP) return uf;
	//special case EXP = 1
	if (EXP ==(1<<23)){
		return sign|(round+((uf&maskEM)>>1));
	}
	//EXP=0 denormal
	if (EXP == 0x0){
		tmp = (uf&maskM)>>1;
		return sign | (tmp+round);
	}
	//normalized case if code gets to here
	return (((EXP>>23)-1)<<23)|(uf&maskSM);
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {//###*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#
	int tx = x;
	unsigned result = 0; //= x & (1<<31);
	//b will be the sign bit with 31 times left shifted.
	int b = x&(1<<31);
	int cc = 0x7f;
	int qtx;
	int lastbit;
	int mask;
	int f,f1,f2,g,h,i,rr,q,lbx;
	if(x==0) return 0; //special case 1 : x is 0.
	if(x == (1<<31)) { //special case 2 : x is tmin. we can't negate this value.
		return (0xcf<<24);
	}
	result = result | b; // mark sign bit.
	if(b) {
		tx = -x; // let's consider only positive value.
	}
	qtx = tx;
	while(qtx/=2) { // get E value.
		cc=cc+1;
	}
	//cc will be Exp value.
	lastbit = cc-0x7f; //last bit is E value.
	mask = (1<<lastbit) - 1;
	//get other bit under 'lastbit'.
	q = (mask & tx);
	lbx = 23-lastbit;
	if(lastbit<=23) {
		//less than 24 bits remain, then, M is just q<<lbx.
		result = result + (q<<lbx);
	} else {
		f = -lbx;
		f1 = f-1;
		f2 = 1<<f1;
		g = q & (f2-1);
		h = q & (1<<(f));
		i = q & (f2);
		rr = q >> (f);
		//rounding.
		//g : check under (lastbit-25) bit. if g is non-zero, there is a bit under the (lastbit-25) bit.
		//h : check (lastbit-23) bit. if h is non-zero, even-rounding is possible.
		//i : check (lastbit-24) bit. it's essential for round-up.
		rr = rr + (i && (g || h));
		result = result | rr;
	}
	//add Exp bits.
	result = result + (cc<<23);
return result;
}
