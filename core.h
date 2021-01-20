//DO NOT use "_tmp" vars anywhere else in your code!

#define CONVERT(x, t) (t)(x)

#define CAST(x, t) ({ \
  typeof(x) _tmp1 = (x); \
  *(t*)&_tmp1; })

#define COPY(x, s, a) ({ \
  uint _tmp1 = 0; \
  byte* _tmp2 = x; \
  byte* _tmp3 = a; \
  while (_tmp1 < s) { \
    _tmp3[_tmp1] = _tmp2[_tmp1]; \
    _tmp1++; \
  } \
  _tmp3; })

#define TOARR(x, t, s) ({ \
  t _tmp1 = x; \
  byte _tmp2[s]; \
  *(t *) _tmp2 = x; \
  _tmp2; })

//'N' postfix means new array
//'T' postfix means typed output

#define CONCAT(x, y, s1, s2, s3, a) ({ \
  uint _tmp1 = 0; \
  byte* _tmp2 = y; \
  byte* _tmp3 = x; \
  byte* _tmp4 = a; \
  while (_tmp1 < s2) { \
    _tmp4[_tmp1] = _tmp2[_tmp1]; \
    _tmp1++; \
  } \
  _tmp1 = 0; \
  while (_tmp1 < s1) { \
    _tmp4[s2 + _tmp1] = _tmp3[_tmp1]; \
    _tmp1++; \
  } \
  _tmp4; })

#define CONCATN(x, y, s1, s2, s3) ({ \
  byte _tmp0[s3]; \
  CONCAT(x, y, s1, s2, s3, _tmp0); })

#define CONCATT(x, y, s1, s2, s3, t) ({ \
  *(t*)CONCATN(x, y, s1, s2, s3); })

#define SUB(x, n, s1, s2, a) ({ \
  uint _tmp1 = 0; \
  byte* _tmp2 = x; \
  byte* _tmp3 = a; \
  while (_tmp1 < s2) { \
    _tmp3[_tmp1] = _tmp2[n + _tmp1]; \
    _tmp1++; \
  } \
  _tmp3; })

#define SUBN(x, n, s1, s2) ({ \
  byte _tmp0[s2]; \
  SUB(x, n, s1, s2, _tmp0); })

#define SUBT(x, n, s1, s2, t) ({ \
  *(t*)SUBN(x, n, s1, s2); })

#define ZEXT(x, s1, s2, a) ({ \
  uint _tmp1 = 0; \
  byte* _tmp2 = x; \
  byte* _tmp3 = a; \
  while (_tmp1 < s1) { \
    _tmp3[_tmp1] = _tmp2[_tmp1]; \
    _tmp1++; \
  } \
  while (_tmp1 < s2) { \
    _tmp3[_tmp1] = 0; \
    _tmp1++; \
  } \
  _tmp3; })
