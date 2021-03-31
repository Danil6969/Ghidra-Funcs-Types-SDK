typedef unsigned char   undefined; //size = 1

typedef unsigned char    byte; //size = 1
typedef unsigned char    dwfenc; //size = 1
typedef unsigned short    word; //size = 2
typedef unsigned int    dword; //size = 4
typedef long long    longlong; //size = 8
typedef unsigned long long    qword; //size = 8
typedef unsigned short    ushort; //size = 2
typedef unsigned int    uint; //size = 4
typedef unsigned long    ulong; //size = 4
typedef unsigned long long    ulonglong; //size = 8

typedef long double float10;

// use these structs as return values instead of arrays
// i.e. you must get rid of "warning: address of stack memory associated with local variable 'abVar1' returned [-Wreturn-stack-address]"
// or you will get UB especially at -O1 and higher

typedef struct { undefined arr[1]; } undefined1; //size = 1
typedef struct { undefined arr[2]; } undefined2; //size = 2
typedef struct { undefined arr[4]; } undefined4; //size = 4
typedef struct { undefined arr[6]; } undefined6; //size = 6
typedef struct { undefined arr[8]; } undefined8; //size = 8

typedef struct { byte arr[16]; } arr16;
typedef struct { uint arr[16]; } arr64;
