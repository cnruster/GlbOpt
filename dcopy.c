// COPIES A VECTOR, X, TO A VECTOR, Y.                  
// USES UNROLLED LOOPS FOR INCREMENTS EQUAL TO ONE.     
// JACK DONGARRA, LINPACK, 3/11/78.

#include <assert.h>                   
                                                          
void DCOPY(int n, const double DX[], int incx, double DY[], int incy)                  
{                                                          
    int i, ix, iy, m;

    assert(n >= 0); 
    
    if (incx == 1 && incy == 1)
    // code for both increments equal to 1
    { 
        // clean-up loop
        m = n % 7;
        if (m != 0)
        {
            for (i=0; i<m; i++)
               DY[i] = DX[i];
            
            if (n < 7)
                return;
        }   

        for (i = m; i < n; i+=7)
        {
            DY[i] = DX[i];
            DY[i+1] = DX[i+1];
            DY[i+2] = DX[i+2];
            DY[i+3] = DX[i+3];
            DY[i+4] = DX[i+4];
            DY[i+5] = DX[i+5];
            DY[i+6] = DX[i+6];
        }
    }
    else
    // code for unequal increments or equal increments  
    // not equal to 1
    {
        ix = (incx < 0)? (1-n)*incx : 0;
        iy = (incy < 0)? (1-n)*incy : 0;

        for (i=0; i<n; i++)
        {
            DY[iy] = DX[ix];
            ix += incx;
            iy += incy;
        }
    }
}