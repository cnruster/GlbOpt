#pragma once

#include "bidouble.h"

#define OPZ(x,l,u)    ((u)-(x)+(l))

#ifdef __cplusplus
extern "C" {
#endif
    
double DGen(double l, double u, int i, int N);
double RGen(double l, double u);
double Bound(double x, double l, double u);
double QOPZ(double x, double l, double u);
int FindMin(int n, const double Y[]);
int FindMax(int n, const double Y[]);
int FindMin_BD(int n, const bidouble Y[]);
int FindMax_BD(int n, const bidouble Y[]);

#ifdef __cplusplus
}
#endif