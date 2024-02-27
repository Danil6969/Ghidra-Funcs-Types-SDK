#include "coreCommon.h"

//'N' postfix means new array

#define SUB(x, n, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  __typeof(n) _tmp3 = n;\
  memcpy(_tmp2, _tmp1 + _tmp3, s2); })

#define SUBN(x, n, s1, s2) NEWARR(s2,SUB(x, n, s1, s2, _tmp0.arr))

#define SUBT(x, n, s1, s2, t) CASTARR(SUBN(x, n, s1, s2), t, s2)

#define CONCAT(x, y, s1, s2, s3, a) ({ \
  byte *_tmp1 = (byte *)y; \
  byte *_tmp2 = (byte *)x; \
  byte *_tmp3 = a; \
  memcpy(_tmp3, _tmp1, s2); \
  memcpy(_tmp3 + s2, _tmp2, s1); })

#define CONCATN(x, y, s1, s2, s3) NEWARR(s3,CONCAT(x, y, s1, s2, s3, _tmp0.arr))

#define CONCATT(x, y, s1, s2, s3, t) CASTARR(CONCATN(x, y, s1, s2, s3), t, s3)

#define ZEXT(x, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  memset(_tmp2, 0, s2); \
  memcpy(_tmp2, _tmp1, s1); })

#define ZEXTN(x, s1, s2) NEWARR(s2, ZEXT(x, s1, s2, _tmp0.arr))

#define ZEXTT(x, s1, s2, t) CASTARR(ZEXTN(x, s1, s2), t, s2)

#define SEXT(x, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  memset(_tmp2, 0xff * ((_tmp1[s1 - 1]) >> 7), s2); \
  memcpy(_tmp2, _tmp1, s1); })

#define SEXTN(x, s1, s2) NEWARR(s2, SEXT(x, s1, s2, _tmp0.arr))

#define SEXTT(x, s1, s2, t) CASTARR(SEXTN(x, s1, s2), t, s2)

// variable indexed extraction
#define EXTRACTIND(x, n, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  __typeof(n) _tmp3 = n; \
  memcpy(_tmp2, _tmp1 + _tmp3, s2); })

#define EXTRACTINDN(x, n, s1, s2) NEWARR(s2, EXTRACTIND(x, n, s1, s2, _tmp0.arr))

#define EXTRACTINDT(x, n, s1, s2, t) CASTARR(EXTRACTINDN(x, n, s1, s2), t, s2)

// variable indexed insertion
#define INSERTIND(x, y, n, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = y; \
  byte* _tmp3 = a; \
  __typeof(n) _tmp4 = n; \
  memcpy(_tmp3, _tmp1, s1); \
  memcpy(_tmp3 + _tmp4, _tmp2, s2); })

#define INSERTINDN(x, y, n, s1, s2) NEWARR(s1, INSERTIND(x, y, n, s1, s2, _tmp0.arr))

#define INSERTINDT(x, y, n, s1, s2, t) CASTARR(INSERTINDN(x, y, n, s1, s2), t, s1)
