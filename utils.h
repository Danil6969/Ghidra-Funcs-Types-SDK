// define "BIGENDIANMACROS" if the language of the decompiled binary was big endian
#ifndef BIGENDIANMACROS
#include "coreLE.h"
#else
#include "coreBE.h"
#endif

// DO NOT use "_tmp" vars anywhere else in your code!

// also add "static" for anything you return by address in your functions, like:
// static byte abVar1 [16];
// ...
// return abVar1;
// i.e. you must get rid of "warning: address of stack memory associated with local variable 'abVar1' returned [-Wreturn-stack-address]"
// or you will get UB especially at -O1 and higher

#define COPY10(a, x) COPY(a, x, 10)
#define COPY12(a, x) COPY(a, x, 12)
#define COPY14(a, x) COPY(a, x, 14)
#define COPY16(a, x) COPY(a, x, 16)
#define COPY64(a, x) COPY(a, x, 64)

#define TOARR1( x, t) TOARR(x, t,  1)
#define TOARR2( x, t) TOARR(x, t,  2)
#define TOARR4( x, t) TOARR(x, t,  4)
#define TOARR6( x, t) TOARR(x, t,  6)
#define TOARR8( x, t) TOARR(x, t,  8)
#define TOARR16(x, t) TOARR(x, t, 16)
#define TOARR64(x, t) TOARR(x, t, 64)

//'T' postfix means typed assignment to number variable
//'n_m' interfix means two numbers representing sizes of input operands
#define CONCAT8_2( x, y) CONCATN(x, y,  8, 2, 10)
#define CONCAT8_4( x, y) CONCATN(x, y,  8, 4, 12)
#define CONCAT10_2(x, y) CONCATN(x, y, 10, 2, 12)
#define CONCAT12_2(x, y) CONCATN(x, y, 12, 2, 14)
#define CONCAT12_4(x, y) CONCATN(x, y, 12, 4, 16)
#define CONCAT14_2(x, y) CONCATN(x, y, 14, 2, 16)

#define CONCAT2_2T(x, y, t) CONCATT(x, y, 2, 2,  4, t)
#define CONCAT4_2T(x, y, t) CONCATT(x, y, 4, 2,  6, t)
#define CONCAT4_4T(x, y, t) CONCATT(x, y, 4, 4,  8, t)
#define CONCAT6_2T(x, y, t) CONCATT(x, y, 6, 2,  8, t)

#define SUB16_15(x, n) SUBN(x, n, 16, 15)
#define SUB64_4( x, n) SUBN(x, n, 64,  4)

#define SUB8_4T( x, n, t) SUBT(x, n,  8, 4, t)
#define SUB10_2T(x, n, t) SUBT(x, n, 10, 2, t)
#define SUB16_1T(x, n, t) SUBT(x, n, 16, 1, t)
#define SUB16_4T(x, n, t) SUBT(x, n, 16, 4, t)

#define ZEXT4_16(x) ZEXTN(x, 4, 16)

#define SEXT4_16(x) SEXTN(x, 4, 16)

#define EXTRACTIND16_1T(x, n, t) EXTRACTINDT(x, n, 16, 1, t)
#define EXTRACTIND64_4T(x, n, t) EXTRACTINDT(x, n, 64, 4, t)

#define INSERTIND16_1(x, y, n) INSERTINDN(x, y, n, 16, 1)
#define INSERTIND64_4(x, y, n) INSERTINDN(x, y, n, 64, 4)
