void * memcpy(void *, const void *, unsigned long long);
void * memset(void *, const int, unsigned long long);

#define CONVERT(x, t) (t)(x)

#define CAST(x, t) ({ \
  typeof(x) _tmp1 = (x); \
  *(t*)&_tmp1; })

#define CASTARR(x, t) ({ \
  *(t*)(x); })

#define COPY(a, x, s) memcpy(a, x, s)

// using struct for thread safety

#define NEWARR(size, macro) (({ \
  struct { byte arr[size]; } _tmp0; \
  macro; \
  _tmp0; }).arr)

#define TOARR(x, t, s) NEWARR(s, ({ \
  t _tmp1 = (t)(x); \
  memcpy(_tmp0.arr, &_tmp1, s); }))

//'T' postfix means typed output

#define PARTIAL(x, n) ({ \
  byte* _tmp1 = x; \
  _tmp1 + n; })

#define PARTIALT(x, n, t) (*(t*)PARTIAL(x, n))

//'N' postfix means new array

#define SUB(x, n, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  typeof(n) _tmp3 = n;\
  memcpy(_tmp2, _tmp1 + _tmp3, s2); })

#define SUBN(x, n, s1, s2) NEWARR(s2,SUB(x, n, s1, s2, _tmp0.arr))

#define SUBT(x, n, s1, s2, t) (*(t*)SUBN(x, n, s1, s2))

#define CONCAT(x, y, s1, s2, s3, a) ({ \
  byte* _tmp1 = y; \
  byte* _tmp2 = x; \
  byte* _tmp3 = a; \
  memcpy(_tmp3, _tmp1, s2); \
  memcpy(_tmp3 + s2, _tmp2, s1); })

#define CONCATN(x, y, s1, s2, s3) NEWARR(s3,CONCAT(x, y, s1, s2, s3, _tmp0.arr))

#define CONCATT(x, y, s1, s2, s3, t) (*(t*)CONCATN(x, y, s1, s2, s3))

#define ZEXT(x, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  memset(_tmp2, 0, s2); \
  memcpy(_tmp2, _tmp1, s1); })

#define ZEXTN(x, s1, s2) NEWARR(s2, ZEXT(x, s1, s2, _tmp0.arr))

#define ZEXTT(x, s1, s2, t) (*(t*)ZEXTN(x, s1, s2))

#define SEXT(x, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  memset(_tmp2, 0xff * ((_tmp1[s1 - 1]) >> 7), s2); \
  memcpy(_tmp2, _tmp1, s1); })

#define SEXTN(x, s1, s2) NEWARR(s2, SEXT(x, s1, s2, _tmp0.arr))

#define SEXTT(x, s1, s2, t) (*(t*)SEXTN(x, s1, s2))

// variable indexed extraction
#define EXTRACTIND(x, n, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  typeof(n) _tmp3 = n; \
  memcpy(_tmp2, _tmp1 + _tmp3, s2); })

#define EXTRACTINDN(x, n, s1, s2) NEWARR(s2, EXTRACTIND(x, n, s1, s2, _tmp0.arr))

#define EXTRACTINDT(x, n, s1, s2, t) (*(t*)EXTRACTINDN(x, n, s1, s2))

// variable indexed insertion
#define INSERTIND(x, y, n, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = y; \
  byte* _tmp3 = a; \
  typeof(n) _tmp4 = n; \
  memcpy(_tmp3, _tmp1, s1); \
  memcpy(_tmp3 + _tmp4, _tmp2, s2); })

#define INSERTINDN(x, y, n, s1, s2) NEWARR(s1, INSERTIND(x, y, n, s1, s2, _tmp0.arr))

#define INSERTINDT(x, y, n, s1, s2, t) (*(t*)INSERTINDN(x, y, n, s1, s2))
