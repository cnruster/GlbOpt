#pragma once

typedef unsigned int UINT;

typedef struct
{
    UINT mantissa_low;
    UINT mhes;
} DOUBLE_IEEE754;

typedef union
{
    DOUBLE_IEEE754 i;
    double d;
} DOUBLE;


#define DGET_MANTISSA_HIGH(mhes)  ((mhes & 0x000FFFFF))
#define DGET_EXPONENT(mhes)       ((mhes & 0x7FF00000)>>20)
#define DGET_SIGN(mhes)           ((mhes & 0x80000000)>>31)

#define DMHES(mantissa_high, exponent, sign)  ((mantissa_high) | (exponent)<<20 | (sign)<<31)

#define LODWORD(x)   (*(UINT *)&x)
#define HIDWORD(x)   (*((UINT *)&x + 1))


#ifdef __cplusplus
extern "C" {
#endif

int DNonFinite(double x);
double DScale(double x);
double NextDouble(double x);
double PrevDouble(double x);
double RandDouble();
double RandDoubleEx();
void DispDouble(double x);
void DispDoubleLn(double x);

extern const DOUBLE _depsilon;
extern const DOUBLE _dtiny;
extern const DOUBLE _dhuge;
extern const DOUBLE _dinf;
extern const DOUBLE _dninf;
extern const DOUBLE _dnan;


#ifdef __cplusplus
}
#endif

#define DEPSILON    _depsilon.d
#define DTINY       _dtiny.d
#define DHUGE       _dhuge.d
#define DINF        _dinf.d
#define DNINF       _dninf.d
#define DNAN        _dnan.d