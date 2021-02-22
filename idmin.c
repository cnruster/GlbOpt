// IDMIN finds the index of element having min. value.

#include <assert.h>
#include "double.h"

int IDMIN(int n, const double DX[], int incx, double *Dmin)
{
    double dmin, dtemp;
    int i, ix, imin;

    assert(incx > 0);
    assert(n > 0);

    dmin = DINF;

    if (incx == 1)
    // code for increment equal to 1
    {
        for (i=0; i<n; i++)
        {
            if (dmin > (dtemp = DX[i]))
            {
                imin = i;
                dmin = dtemp;
            }
        }
    }
    else
    // code for increment not equal to 1
    {
        ix = i = 0;
        while (i < n)
        {
            if (dmin > (dtemp = DX[ix]))
            {
                imin = i;
                dmin = dtemp;
            }
            i++;
            ix += incx;
        }
    }

    *Dmin = dmin;
    return imin;
}
