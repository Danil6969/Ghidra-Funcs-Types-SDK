void * memcpy(void *, const void *, unsigned long long);
void * memset(void *, const int, unsigned long long);

#define CONVERT(x, t) (t)(x)

#define CAST(x, t) ({ \
  typeof(x) _tmp1 = (x); \
  *(t*)&_tmp1; })

#define COPY(x, s, a) memcpy(a, x, s)

#define TOARR(x, t, s) ({ \
  static byte _tmp1[s]; \
  typeof(x) _tmp2 = (x); \
  memcpy(_tmp1, &_tmp2, s); \
  _tmp1; })

//'N' postfix means new array
//'T' postfix means typed output

#define CONCAT(x, y, s1, s2, s3, a) ({ \
  byte* _tmp1 = y; \
  byte* _tmp2 = x; \
  byte* _tmp3 = a; \
  memcpy(_tmp3, _tmp1, s2); \
  memcpy(_tmp3 + s2, _tmp2, s1); \
  _tmp3; })

#define CONCATN(x, y, s1, s2, s3) ({ \
  static byte _tmp0[s3]; \
  CONCAT(x, y, s1, s2, s3, _tmp0); })

#define CONCATT(x, y, s1, s2, s3, t) ({ \
  *(t*)CONCATN(x, y, s1, s2, s3); })

#define SUB(x, n, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  memcpy(_tmp2, _tmp1 + n, s2); \
  _tmp2; })

#define SUBN(x, n, s1, s2) ({ \
  static byte _tmp0[s2]; \
  SUB(x, n, s1, s2, _tmp0); })

#define SUBT(x, n, s1, s2, t) ({ \
  *(t*)SUBN(x, n, s1, s2); })

#define ZEXT(x, s1, s2, a) ({ \
  byte* _tmp1 = x; \
  byte* _tmp2 = a; \
  memset(_tmp2, 0, s2); \
  memcpy(_tmp2, _tmp1, s1); \
  _tmp2; })
