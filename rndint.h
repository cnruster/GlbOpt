#pragma once

#include "blas.h"

#define RndInt(m)       (ILARAN()%(m));
#define RndIntC(m, i)   (((i)+1 + ILARAN()%((m)-1))%(m))

#ifdef __cplusplus
extern "C" {
#endif

void RndTuple(int m, int n, int IND[]);
void RndTupleC(int m, int c, int n, int IND[]);


#ifdef __cplusplus
}
#endif
