#pragma once

#include <assert.h>
#include <stddef.h>
#include "blas.h"
#include "bidouble.h"

typedef unsigned int UINT;
typedef bidouble FUN_X(const double X[]);
typedef bidouble FUN_DX(int D, const double X[]);


class GLB_OPT
{
protected:
    static int EMemSize(int d, int np);         // required memory size
    int D;          // dimension
    int NP;         // population size
    double *LB;     // lower bounds
    double *UB;     // upper bounds
    double *POP;    // population
    bidouble *Y;    // function values of individuals
    UINT NFE;       // number of function evaluations
    UINT Iter;      // iteration index
    FUN_X *FunX;            // function to minimize without dimension
    FUN_DX *FunDX;          // function to minimize with dimension
    virtual bidouble Fun(const double X[]); // the true function to minimize
    virtual int Interfun()=0;               // inter-iteration function

public:
    GLB_OPT();
    ~GLB_OPT();
    void Init(int d, int np);
    void SetFunX(FUN_X *funx);
    void SetFunDX(FUN_DX *fundx);
    void SetLB(int s, double lb);
    void SetUB(int s, double ub);
    int Solve(double X[], bidouble& yval);
};


inline void GLB_OPT::SetFunX(FUN_X *funx)
{
    assert(funx);
    FunX = funx;
}

inline void GLB_OPT::SetFunDX(FUN_DX *fundx)
{
    assert(fundx);
    FunX = NULL;
    FunDX = fundx;
}

inline void GLB_OPT::SetLB(int s, double lb)
{
    assert(0<=s && s<D);
    LB[s] = lb;
}

inline void GLB_OPT::SetUB(int s, double ub)
{
    assert(0<=s && s<D);
    UB[s] = ub;
}

inline int GLB_OPT::EMemSize(int d, int np)
{
    return (4+np)*d*sizeof(double) + np*(sizeof(bidouble)+sizeof(int));
}