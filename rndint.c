#include <assert.h>
#include "blas.h"
#include "rndint.h"


// the range of IND[*] at output is 0..m-1
// the length of IND[] is n
// n must be not greater than m
void RndTuple(int m, int n, int IND[])
{
    int d, r, t, i;

    assert(n>0);
    assert(m>=n);

    r = 0;
    d = m-n;

LOOP:
    d++;
    IND[r] = i = ILARAN() % d;
    for (t=0; t<r; t++)
        IND[t] = (i+1 + IND[t]) % d;

    if (++r<n)
        goto LOOP;
}


// the range of IND[*] at output is 0..m-1, and must not equal c
// the length of IND[] is n
// n must be smaller than m
void RndTupleC(int m, int c, int n, int IND[])
{
    int t;

    assert(c>=0 && c<m);

    RndTuple(m-1, n, IND);
    for (t=0; t<n; t++)
        IND[t] = (c+1 + IND[t])%m;
}