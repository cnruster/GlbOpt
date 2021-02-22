#pragma once

typedef struct
{
    double low;
    double high;
} bidouble;

#ifdef __cplusplus
extern "C" {
#endif

int BidblCmp(bidouble a, bidouble b);
int IDMAX_BD(int n, const bidouble DX[], bidouble *Dmax);
int IDMIN_BD(int n, const bidouble DX[], bidouble *Dmin);


#ifdef __cplusplus
}
#endif
