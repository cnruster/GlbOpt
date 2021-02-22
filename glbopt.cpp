#include <assert.h>
#include <limits.h>
#include "glbopt.h"
#include "optutil.h"
#include "rndint.h"
#include "xmalloc.h"


// the true function to minimize
bidouble GLB_OPT::Fun(const double X[])
{
    if (FunX)
        return FunX(X);
    else
        return FunDX(D, X);
}

GLB_OPT::GLB_OPT()
{
    LB = NULL;
}

GLB_OPT::~GLB_OPT()
{
    if (LB)
        free(LB);
}

// initialize the object
void GLB_OPT::Init(int d, int np)
{
    if (LB)
        free(LB);

    D = d;
    NP = np;
    LB = (double *)xmalloc(EMemSize(d, np));
    UB = &LB[2*d];
    POP = &UB[2*d];
    Y = (bidouble *)&POP[np*d];

    FunX = NULL;
    FunDX = NULL;
}

int GLB_OPT::Solve(double X[], bidouble& yval)
{
    bidouble y;
    double beta, gamma, delta, *DLB, *DUB, *X1, *X2, *X3, *X4;
    int np2, k, i, IR[3], imin, local, s, smute, improved, retcode, *IND;

    np2 = NP*2;
    DLB = &LB[D];
    DUB = &UB[D];
    IND = (int*)&Y[NP]; 

    // population initialization
    for (s=0; s<D; s++)
    {
        RndTuple(NP, NP, IND);
        for (i=0; i<NP; i++)
            POP[i*D+s] = DGen(LB[s], UB[s], IND[i], NP);
    }

    for (i=0; i<NP; i++)
        Y[i] = Fun(&POP[i*D]);


    NFE = NP;
    Iter = 0;
    local = 0;

BEGIN_ITER:

    if (local)
    {
        for (s=0; s<D; s++)
        {
            IDMIN(NP, &POP[s], D, &DLB[s]);
            IDMAX(NP, &POP[s], D, &DUB[s]);
        }
    }

    RndTuple(NP, NP, IND);
    improved = 0;

    for (k=0; k<NP; k++)
    {
        i = IND[k];
        RndTupleC(np2, i, 3, IR);

        X1 = &POP[i*D];
        X2 = (IR[0]<NP)? &POP[IR[0]*D] : &POP[(IR[0]-NP)*D];
        X3 = (IR[1]<NP)? &POP[IR[1]*D] : &POP[(IR[1]-NP)*D];
        X4 = (IR[2]<NP)? &POP[IR[2]*D] : &POP[(IR[2]-NP)*D];

        // mutation and crossover
        if (local)
        {
            for (s=0; s<D; s++)
            {
                beta = (IR[0]<NP)? X2[s] : OPZ(X2[s], DLB[s], DUB[s]);
                gamma = (IR[1]<NP)? X3[s] : OPZ(X3[s], DLB[s], DUB[s]);
                delta = (IR[2]<NP)? X4[s] : OPZ(X4[s], DLB[s], DUB[s]);
                X[s] = Bound(beta +0.5*(gamma-delta), LB[s], UB[s]);
            }
        }
        else
        {
            smute = RndInt(D);
            for (s=0; s<D; s++)
            {
                if (smute!=s && ILABIT())
                    X[s] = X1[s];
                else
                {
                    beta = (IR[0]<NP)? X2[s] : QOPZ(X2[s], LB[s], UB[s]);
                    gamma = (IR[1]<NP)? X3[s] : QOPZ(X3[s], LB[s], UB[s]);
                    delta = (IR[2]<NP)? X4[s] : QOPZ(X4[s], LB[s], UB[s]);
                    X[s] = Bound(beta +0.5*(gamma-delta), LB[s], UB[s]);
                }
            }
        }

        // selection
        if (BidblCmp(Y[i], y=Fun(X)) > 0)
        {
            Y[i] = y;
            DCOPY(D, X, 1, X1, 1);
            improved = 1;
        }
    }

    NFE+=NP;
    Iter++;
    if (!(retcode = Interfun()))
    {
        if (!improved)
            local = !local;

        goto BEGIN_ITER;
    }
        
    imin = IDMIN_BD(NP, Y, &yval);
    DCOPY(D, &POP[imin*D], 1, X, 1);

    return retcode;
}
