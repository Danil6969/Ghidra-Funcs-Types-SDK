#include "types.h"
#include <cstring>
#include <cstdio>

#define CONVERT(x, t) (t)(x)

// Can't cast if sizes don't match
#define CAST(x, t) ({ \
  auto _tmp1 = (x); \
  t _tmp2; \
  static_assert(sizeof(_tmp1) == sizeof(_tmp2)); \
  memcpy(&_tmp2, &_tmp1, sizeof(t)); \
  _tmp2; })

// Can't cast if sizes don't match
#define CASTARR(x, t, s) ({ \
  static_assert(sizeof(t) == s); \
  t _tmp1; \
  memcpy(&_tmp1, x, s); \
  _tmp1; })

// allocates struct, executes macro expression and returns bytes buffer
#define NEWARR(size, macro) (({ \
  struct { unsigned char arr[size]; } _tmp0; \
  macro; \
  _tmp0; }).arr)

#define TOARR(x, t, s) NEWARR(s, ({ \
  static_assert(sizeof(t) == s); \
  t _tmp1 = (t)(x); \
  memcpy(_tmp0.arr, &_tmp1, s); }))

#define COPY(a, x, s) NEWARR(s, ({ \
  memcpy(_tmp0.arr, x, s); \
  memcpy(a, _tmp0.arr, s); }))

//'T' postfix means typed output

#define PARTIAL(x, n) ({ \
  unsigned char* _tmp1 = x; \
  _tmp1 + n; })

#define PARTIALT(x, n, t) CASTARR(PARTIAL(x, n), t, sizeof(t))

#define ADJ(x, y) ({ \
  unsigned long long _tmp1 = (unsigned long long) x; \
  auto _tmp2 = (decltype(x)) (_tmp1 - y); \
  _tmp2; })

#define LZCOUNT(x) ({ \
  decltype(x) _tmp0; \
  signed char _tmp1 = sizeof(x) * 8 - 1; \
  unsigned char _tmp2 = 0; \
  while (_tmp1 >= 0) { \
    _tmp0 = (x >> _tmp1) & 1; \
    if (_tmp0) break; \
    _tmp2++; \
    _tmp1--; \
  } \
  _tmp2; \
})
