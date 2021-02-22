#include <assert.h>
#include "blas.h"
#include "double.h"
#include "bidouble.h"
#include "optutil.h"


double DGen(double l, double u, int i, int N)
{
    assert(i>=0 && i<N);
    return l + (0.5+(double)i)/(double)N*(u-l);
}


double RGen(double l, double u)
{
    return l + (u-l)*DLARAN();
}


double Bound(double x, double l, double u)
{
    assert(l <= u);
    return (x<l)? l : ((x>u)? u: x);
}


double QOPZ(double x, double l, double u)
{
    double c = 0.5*(l+u);
    return c + (c-x)*DLARAN();
}


int FindMin(int n, const double Y[])
{
    double ymin;
    return IDMIN(n, Y, 1, &ymin);
}


int FindMax(int n, const double Y[])
{
    double ymax;
    return IDMAX(n, Y, 1, &ymax);
}

int FindMin_BD(int n, const bidouble Y[])
{
    bidouble ymin;
    return IDMIN_BD(n, Y, &ymin);
}
