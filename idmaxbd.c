// IDMAX finds the index of element having max. value.

#include <assert.h>
#include "double.h"
#include "bidouble.h"

int IDMAX(int n, const bidouble DX[], int incx, bidouble *Dmax)
{
    bidouble dmax, dtemp;
    int i, ix, imax;

    assert(incx > 0);
    assert(n > 0);

    dmax.low = DNINF;
    dmax.high = DNINF;

    if (incx == 1)
    // code for increment equal to 1
    {
        for (i=0; i<n; i++)
        {
            if (BidblCmp(dmax, dtemp = DX[i]) < 0)
            {
                imax = i;
                dmax = dtemp;
            }
        }
    }
    else
    // code for increment not equal to 1
    {
        ix = i = 0;
        while (i < n)
        {
            if (BidblCmp(dmax, dtemp = DX[ix]) < 0)
            {
                imax = i;
                dmax = dtemp;
            }
            i++;
            ix += incx;
        }
    }

    *Dmax = dmax;
    return imax;
}
