// IDMAX finds the index of element having max. value.

#include <assert.h>
#include "double.h"

int IDMAX(int n, const double DX[], int incx, double *Dmax)
{
    double dmax, dtemp;
    int i, ix, imax;

    assert(incx > 0);
    assert(n > 0);

    dmax = DNINF;

    if (incx == 1)
    // code for increment equal to 1
    {
        for (i=0; i<n; i++)
        {
            if (dmax < (dtemp = DX[i]))
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
            if (dmax < (dtemp = DX[ix]))
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
