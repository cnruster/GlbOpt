// DEPSILON: the machine epsilon for double precision
// DTINY: the smallest nonzero number
// DHUGE: the largest noninfinite number

#include "double.h"

const DOUBLE _depsilon = {0, DMHES(0, 1023-52, 0)};
const DOUBLE _dtiny = {0, DMHES(0, 1, 0)};
const DOUBLE _dhuge = {0xffffffff, DMHES(0xfffff, 2046, 0)};
const DOUBLE _dinf = {0, DMHES(0, 2047, 0)};
const DOUBLE _dninf = {0, DMHES(0, 2047, 1)};
const DOUBLE _dnan = {0, DMHES(0x80000, 2047, 0)};


// check if the number is a NaN or an infinity
int DNonFinite(double x)
{
    return ((HIDWORD(x) & 0x7FF00000) == 0x7FF00000);
}