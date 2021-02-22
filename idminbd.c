// IDMIN finds the index of element having min. value.

#include <assert.h>
#include "double.h"
#include "bidouble.h"

int IDMIN_BD(int n, const bidouble DX[], bidouble *Dmin)
{
    bidouble dmin, dtemp;
    int i, imin;

    assert(n > 0);

    dmin.low = DINF;
    dmin.high = DINF;

    for (i=0; i<n; i++)
    {
        if (BidblCmp(dmin, dtemp = DX[i]) > 0)
        {
            imin = i;
            dmin = dtemp;
        }
    }

    *Dmin = dmin;
    return imin;
}
