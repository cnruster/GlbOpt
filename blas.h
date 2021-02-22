#pragma once

#define ABS(x)          (((x) < 0)? -(x) : (x))
#define SIGN(x)         (((x) < 0)? -1 : 1)
#define SIGN0(x)        (((x) == 0)? 0 : SIGN(x))
#define SIGN2(x,y)      (((y) < 0)? -(x) : (x))
#define MAX(x,y)        (((x) > (y))? (x) : (y))
#define MIN(x,y)        (((x) < (y))? (x) : (y))
#define MAX3(x,y,z)     (((x) > MAX(y,z))? (x) : MAX(y,z))
#define MIN3(x,y,z)     (((x) < MIN(y,z))? (x) : MIN(y,z))
#define ISNAN(x)        ((x) < (x))
#define ABSLT(x, a)     (((x) > -(a)) && ((x) < (a)))


#define DSYFIL(uplo, n, A, lda)     DSYCPY(uplo, n, A, lda, A, lda)

typedef unsigned int UINT;


#ifdef __cplusplus
extern "C" {
#endif

void ILASEED(UINT sid);
UINT ILARAN();
UINT ILABIT();
double DLARAN();
double DLARNG();


int LSAME(char ca, char cb);
double DLAMCH(char cmach);
void DSWAP(int n, double DX[], int incx, double DY[], int incy);
void DSWAP1(double *X, double *Y);
void DCOPY(int n, const double DX[], int incx, double DY[], int incy);
void DSYCPY(char uplo, int n, double A[], int lda, double B[], int ldb);
void DLACPY(char uplo, int m, int n, const double A[], int lda, double B[], int ldb);
void IDAMAX(int n, const double DX[], int incx, int ibase, int *Imax, double *Dmax);
int IDMAX(int n, const double DX[], int incx, double *Dmax);
int IDMIN(int n, const double DX[], int incx, double *Dmin);
void DSCAL(int n, double da, double DX[], int incx);
void DLASCL(char uplo, int m, int n, double alpha, double A[], int lda);
double DASUM(int n, const double DX[], int incx);
void DAXEY(int n, double DA, const double DX[], int incx, double DY[], int incy);
void DAXPY(int n, double DA, const double DX[], int incx, double DY[], int incy);
void DXPAY(int n, const double DX[], int incx, double da, double DY[], int incy);
double DDOT(int n, const double DX[], int incx, const double DY[], int incy);
double DSYDOT(char uplo, int n, const double A[], int lda, 
           const double X[], const double Y[]);
double DLAPY2(double x, double y);
void DLASUM(int n, const double X[], int incx, double *ScaleP, double *SsumP, 
            double *ScaleN, double *SsumN);
void DLASSQ(int n, const double X[], int incx, double *Scale, double *Ssq);
double DMEAN(int n, const double X[], int incx);
double DNRM2(int n, const double X[], int incx);
double DRMS(int n, const double X[], int incx);
double DLANGE(char norm, int m, int n, const double A[], int lda);
double DLANSY(char norm, char uplo, int n, const double A[], int lda);

void DLASWP(int n, double A[], int lda, const int IPIV[], int k1, int k2);
void DGER(int m, int n, double alpha, const double X[], int incx, 
          const double Y[], int incy, double A[], int lda);

void DSYR(char uplo, int n, double alpha, const double X[], int incx, 
          double A[], int lda);
void DSYR2(char uplo, int n, double alpha, const double X[], int incx, 
           const double Y[], int incy, double A[], int lda);
void DGEMV(char trans, int m, int n, double alpha, const double A[], int lda, 
           const double X[], int incx, double beta, double Y[], int incy);
void DSYMV(char uplo, int n, double alpha, const double A[], int lda, 
           const double X[], int incx, double beta, double Y[], int incy);

void DGEMM(char transa, char transb, int m, int n, int k, double alpha,
           const double A[], int lda, const double B[], int ldb, double beta, 
           double C[], int ldc);
void DSYMM(char side, char uplo, int m, int n, double alpha, const double A[],
           int lda, const double B[], int ldb, double beta, double C[], int ldc);
void DTRSM(char uplo, char diag, int n, int nrhs, const double A[], int lda, 
           double B[], int ldb);
void DLARFG(int n, double *Alpha, double X[], int incx, double *Tau);

void DGETRF(int n, double A[], int lda, int IPIV[], int *Info);
void DSYTRF(char uplo, int n, double A[], int lda, int IPIV[], int *Info);
void DSTTRF(int n, double D[], double E[], double F[], int *Info);
void DSYTDF(char uplo, int n, double A[], int lda, double TAU[]);

void DSYTRS(char uplo, int n, int nrhs, const double A[], int lda, const int IPIV[], 
            double B[], int ldb);
void DSTTRS(int n, int nrhs, const double D[], const double E[], const double F[], 
            double B[], int ldb);



#ifdef __cplusplus
}
#endif
