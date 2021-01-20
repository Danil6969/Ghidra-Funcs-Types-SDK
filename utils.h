#include "core.h"

#define COPY16(x, a) COPY(x, 16, a)

#define TOARR1(x, t) TOARR(x, t, 1)
#define TOARR4(x, t) TOARR(x, t, 4)
#define TOARR10(x, t) TOARR(x, t, 10)

//'A' postfix means an assignment to existing byte array, i.e. arr = CONCATn_m(x, y) gets converted to CONCATn_m(x, y, arr)
//'T' postfix means typed assignment to number variable, i.e. num = CONCATn_m(x, y, t) gets converted to num = CONCATn_mT(x, y, t)
//'n_m' interfix means two numbers representing sizes of input operands
#define CONCAT1_1A(x, y, a) CONCAT(x, y, 1, 1, 2, a)
#define CONCAT1_15A(x, y, a) CONCAT(x, y, 1, 15, 2, a)
#define CONCAT2_2T(x, y, t) CONCATT(x, y, 2, 2, 4, t)

#define SUB10_2T(x, n, t) SUBT(x, n, 10, 2, t)
#define SUB16_1T(x, n, t) SUBT(x, n, 16, 1, t)
#define SUB16_4T(x, n, t) SUBT(x, n, 16, 4, t)
#define SUB16_15(x, n) SUBN(x, n, 16, 15)

#define ZEXT4_16A(x, a) ZEXT(x, 4, 16, a)
#define ZEXT15_16A(x, a) ZEXT(x, 15, 16, a)
