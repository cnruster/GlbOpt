#pragma once

#include "bidouble.h"

#define DEF_DX_FUN(func) \
bidouble func(int d, const double X[]);

#define DEF_X_FUN(func) \
bidouble func(const double X[]);


DEF_DX_FUN(Sphere)
DEF_DX_FUN(Axis)
DEF_DX_FUN(Rosenbrock)
DEF_DX_FUN(Rastrigin)
DEF_DX_FUN(Perm)
DEF_DX_FUN(Michalewicz)
DEF_X_FUN(Beale)
DEF_X_FUN(Booth)
DEF_X_FUN(Schaffer)
DEF_X_FUN(Bukin)
DEF_DX_FUN(Griewank)
DEF_DX_FUN(Ackley)
DEF_X_FUN(Easom)
DEF_X_FUN(Damavandi)
DEF_X_FUN(Eggholder)
DEF_DX_FUN(Schwefel)
DEF_DX_FUN(Sumdiffpow)
DEF_X_FUN(Colville)
DEF_X_FUN(Hartmann1)
DEF_X_FUN(Hartmann2)
DEF_X_FUN(Sixhump)
DEF_DX_FUN(Levy)
DEF_X_FUN(Matyas)
DEF_DX_FUN(Zakharov)
DEF_X_FUN(Branin)
DEF_DX_FUN(Schwefel22)
DEF_DX_FUN(Schwefel21)
DEF_DX_FUN(Step)
DEF_DX_FUN(Quartic)
DEF_X_FUN(Kowalik)
DEF_DX_FUN(Shekel)
DEF_X_FUN(Tripod)
DEF_DX_FUN(Dejong)
DEF_DX_FUN(Alpine)
DEF_X_FUN(Schaffer6)
DEF_DX_FUN(Pathological)
DEF_DX_FUN(Invcosine)
DEF_X_FUN(Crosslegtable)
DEF_X_FUN(Crossintray)
DEF_DX_FUN(Sineenvelope)
DEF_X_FUN(Aluffi)
DEF_X_FUN(Becker)
DEF_DX_FUN(Oddsquare)
DEF_X_FUN(Pricemodel)
DEF_X_FUN(Bohachevsky1)
DEF_X_FUN(Bohachevsky2)
DEF_X_FUN(Camelback3)
DEF_X_FUN(Dekkers)
DEF_DX_FUN(Exponential)
DEF_X_FUN(Goldstein)
DEF_X_FUN(Gulf)
DEF_X_FUN(Helical)
DEF_X_FUN(Hosaki)
DEF_DX_FUN(Montalvo)
DEF_X_FUN(Mccormick)
DEF_X_FUN(Miele)
DEF_X_FUN(Multigaussian)
DEF_DX_FUN(Neumaier2)
DEF_X_FUN(Paviani)
DEF_X_FUN(Periodic)
DEF_X_FUN(Powell)
DEF_DX_FUN(Salomon)
DEF_X_FUN(Schaffer2)
DEF_X_FUN(Wood)



#define PI      3.14159265358979323846264338327950288419716939937510

