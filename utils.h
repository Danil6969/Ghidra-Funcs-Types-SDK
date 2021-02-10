#include "core.h"

// DO NOT use "_tmp" vars anywhere else in your code!

// also add "static" for anything you return by address in your functions, like:
// static byte abVar1 [16];
// ...
// return abVar1;
// i.e. you must get rid of "warning: address of stack memory associated with local variable 'abVar1' returned [-Wreturn-stack-address]"
// or you will get UB especially at -O1 and higher

#define COPY16(x, a) COPY(x, 16, a)

#define TOARR1(x, t) TOARR(x, t, 1)
#define TOARR2(x, t) TOARR(x, t, 2)
#define TOARR4(x, t) TOARR(x, t, 4)
#define TOARR8(x, t) TOARR(x, t, 8)
#define TOARR10(x, t) TOARR(x, t, 10)

//'A' postfix means an assignment to existing byte array, i.e. arr = CONCATn_m(x, y) gets converted to CONCATn_m(x, y, arr)
//'T' postfix means typed assignment to number variable, i.e. num = CONCATn_m(x, y, t) gets converted to num = CONCATn_mT(x, y, t)
//'n_m' interfix means two numbers representing sizes of input operands
#define CONCAT1_1A(x, y, a) CONCAT(x, y, 1, 1, 2, a)
#define CONCAT1_15A(x, y, a) CONCAT(x, y, 1, 15, 16, a)
#define CONCAT2_2T(x, y, t) CONCATT(x, y, 2, 2, 4, t)
#define CONCAT2_8T(x, y, t) CONCATT(x, y, 2, 8, 10, t)
#define CONCAT8_8(x, y) CONCATN(x, y, 8, 8, 16)
#define CONCAT8_8A(x, y, a) CONCAT(x, y, 8, 8, 16, a)

#define SUB10_2T(x, n, t) SUBT(x, n, 10, 2, t)
#define SUB16_1T(x, n, t) SUBT(x, n, 16, 1, t)
#define SUB16_4T(x, n, t) SUBT(x, n, 16, 4, t)
#define SUB16_15(x, n) SUBN(x, n, 16, 15)

#define ZEXT4_16A(x, a) ZEXT(x, 4, 16, a)
#define ZEXT15_16A(x, a) ZEXT(x, 15, 16, a)
