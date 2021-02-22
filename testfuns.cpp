#include <math.h>
#include <assert.h>
#include "testfuns.h"
#include "blas.h"
#include "double.h"

bidouble Double2Bidouble(double x)
{
    static bidouble B={0., 0.};

    B.low = x;
    return B;
}

#define returnbd(x)     return Double2Bidouble(x)

bidouble Sphere(int D, const double X[])
{
    double z = 0.;
    for (int i=0; i<D; i++)
        z += X[i]*X[i];

    returnbd(z);
}

bidouble Axis(int D, const double X[])
{
    double z = 0.;
    for (int i=0; i<D; i++)
        z += (i+1)*X[i]*X[i];

    returnbd(z);
}

bidouble Schwefel(int D, const double X[])
{
    double u, v;
    int i, j;

    u = 0.;
    for (i=0; i<D; i++)
    {
        v = 0.;
        for (j=0; j<=i; j++)
            v += X[j];
        u += v*v;
    }

    returnbd(u);
}

bidouble Rosenbrock(int D, const double X[])
{
    double z = 0.;
    for (int i=0; i<D-1; i++)
        z += (X[i]-1)*(X[i]-1) + 100*(X[i+1]-X[i]*X[i])*(X[i+1]-X[i]*X[i]);

    returnbd(z);
}

bidouble Rastrigin(int D, const double X[])
{
    double z;

    z= 10.*D;
    for (int i=0; i<D; i++)
        z += X[i]*X[i]-10.*cos(2*PI*X[i]);

    returnbd(z);
}

bidouble Griewank(int D, const double X[])
{    
    double a, b;
    int i;

    a = 0.;
    for (i=0; i<D; i++)
        a += X[i]*X[i];

    b = 1.;
    for (i=0; i<D; i++)
        b *= cos(X[i]/sqrt(i+1.));

    returnbd(1+a/4000.-b);
}

bidouble Sumdiffpow(int D, const double X[])
{
    double z=0.;
    for (int i=0; i<D; i++)
        z += pow(fabs(X[i]), i+2);

    returnbd(z);
}

bidouble Ackley(int D, const double X[])
{  
    double a, b;
    int i;

    b = a =0;
    for (i=0; i<D; i++)
    {
        a += X[i]*X[i];
        b += cos(2*PI*X[i]);
    }

    returnbd(-20.*exp(-0.2*sqrt(a/D))-exp(b/D)+exp(1)+20.);
}

bidouble Beale(const double X[])
{
    double a, b, c;
    
    a = 1.5-X[0]+X[0]*X[1];
    b = 2.25-X[0]+X[0]*X[1]*X[1];
    c = 2.625-X[0]+X[0]*X[1]*X[1]*X[1];

    returnbd(a*a+b*b+c*c);
}

bidouble Colville(const double X[])
{
    double a,b,c,d,e,f;

    a = X[1]-X[0]*X[0];
    b = 1-X[0];
    c = X[3] - X[2]*X[2];
    d = 1-X[2];
    e = X[1]-1;
    f = X[3]-1;

    returnbd(100*a*a+b*b+90*c*c+d*d+10.1*(e*e+f*f)+19.8*e*f);
}


bidouble Easom(const double X[])
{  
    returnbd(-cos(X[0])*cos(X[1])*exp(-((X[0]-PI)*(X[0]-PI)+(X[1]-PI)*(X[1]-PI))));
}

bidouble Hartmann1(const double X[])
{  
    static double alpha[4]={1, 1.2, 3, 3.2};
    static double A[4][3] = {
        {3, 10, 30},
        {0.1, 10, 35},
        {3, 10, 30},
        {0.1, 10, 35}
    };
    static double P[4][3] = {
        {0.3689, 0.1170, 0.2673},
        {0.4699, 0.4387, 0.7470},
        {0.1091, 0.8732, 0.5547},
        {0.03815, 0.5743, 0.8828}
    };
    
    double u,v,w;
    int i,j;

    u = 0;
    for (i=0; i<4; i++)
    {
        v = 0;
        for (j=0; j<3; j++)
        {
            w = X[j]-P[i][j];
            v += A[i][j]*w*w;
        }
        u += alpha[i]*exp(-v);
    }

    returnbd(-u);
}

bidouble Hartmann2(const double X[])
{  
    static double alpha[4]={1, 1.2, 3, 3.2};
    static double B[4][6] = {
        {10, 3, 17, 3.05, 1.7, 8},
        {0.05, 10, 17, 0.1, 8, 14},
        {3, 3.5, 1.7, 10, 17, 8},
        {17, 8, 0.05, 10, 0.1, 14}
    };
    static double Q[4][6] = {
        {0.1312, 0.1696, 0.5569, 0.0124, 0.8283, 0.5886},
        {0.2329, 0.4135, 0.8307, 0.3736, 0.1004, 0.9991},
        {0.2348, 0.1451, 0.3522, 0.2883, 0.3047, 0.6650},
        {0.4047, 0.8828, 0.8732, 0.5743, 0.1091, 0.0381}
    };
    
    double u,v,w;
    int i,j;

    u = 0;
    for (i=0; i<4; i++)
    {
        v = 0;
        for (j=0; j<6; j++)
        {
            w = X[j]-Q[i][j];
            v += B[i][j]*w*w;
        }
        u += alpha[i]*exp(-v);
    }

    returnbd(-u);
}

bidouble Sixhump(const double X[])
{
    double a = X[0]*X[0];
    double b = X[1]*X[1];
    returnbd(4*a -2.1*a*a +a/3*a*a +X[0]*X[1] -4*b + 4*b*b);
}

bidouble Levy(int D, const double X[])
{
    double z, a, b, c, d, e;
    int i;

    z = 0;
    for (i=0; i<D-1; i++)
    {
        a = X[i]-1;
        b = sin(3*PI*X[i+1]);
        z += (1+b*b)*a*a;
    }

    c = sin(3*PI*X[0]);
    d = sin(2*PI*X[D-1]);
    e = X[D-1]-1;
    
    returnbd(c*c +z +e*e*(1+d*d));
}

bidouble Matyas(const double X[])
{
    returnbd(0.26*(X[0]*X[0]+X[1]*X[1])-0.48*X[0]*X[1]);
}

bidouble Perm(int D, const double X[])
{
    double z, tmp;
    int i, k;

    z = 0;
    for (k=1; k<=D; k++)
        for (i=1; i<=D; i++)
        {
            tmp = (pow(i,k)+0.5)*(pow(X[i-1]/i, k)-1);
            z += tmp*tmp;
        }

    returnbd(z);
}


bidouble Michalewicz(int D, const double X[])
{
    double z;
    int i;

    z = 0;
    for (i=0; i<D; i++)
        z += sin(X[i])*pow(sin((i+1)*X[i]*X[i]/PI),20);

    returnbd(-z);
}

bidouble Zakharov(int D, const double X[])
{
    double a, b;
    int i;

    b = a = 0;
    for (i=0; i<D; i++)
    {
        a += X[i]*X[i];
        b = 0.5*(i+1)*X[i];
    }

    returnbd( a +b*b +b*b*b*b);
}

bidouble Branin(const double X[])
{
    double a,b,c,d,e,f,g;

    a = 1;
    b = 5.1/4/PI/PI;
    c = 5/PI;
    d = 6;
    e = 10;
    f = 0.125/PI;
    g = X[1]-b*X[0]*X[0]+c*X[0]-d;

    returnbd(a*g*g + e*(1-f)*cos(X[0])+e);
}

bidouble Schwefel22(int D, const double X[])
{
    double a, b;
    int i;

    a = 0;
    b = 1;

    for (i=0; i<D; i++)
    {
        a += fabs(X[i]);
        b *= fabs(X[i]);
    }

    returnbd(a+b);
}


bidouble Schwefel21(int D, const double X[])
{
    double a, b;
    int i;

    a = 0;
    for (i=0; i<D; i++)
    {
        b = fabs(X[i]); 
        if (b>a)
            a=b;
    }

    returnbd(a);
}


double trunc(double x)
{
    int t;
    
    t = (int)x;
    if (t>x)
        t--;
    
    return ((double)t);
}


bidouble Step(int D, const double X[])
{
    double a, b;
    int i;

    a = 0;
    for (i=0; i<D; i++)
    {
        b = trunc(X[i]+0.5);
        a += b*b;
    }

    returnbd(a);
}


bidouble Quartic(int D, const double X[])
{
    double a, b;
    int i;

    a = 0;
    for (i=0; i<D; i++)
    {
        b = X[i]*X[i];
        a += (i+1)*b*b;
    }

    returnbd(a+DLARAN());
}

bidouble Booth(const double X[])
{
    double a, b;
    
    a = X[0] + 2.*X[1] -7;
    b = 2.*X[0] + X[1] -5.;

    returnbd(a*a+b*b);
}

bidouble Schaffer(const double X[])
{
    double a, b;
    
    a = sin(X[0]*X[0]-X[1]*X[1]);
    b = 1.+0.001*(X[0]*X[0]+X[1]*X[1]);

    returnbd(0.5+(a*a-0.5)/b/b);
}


// D = 4
// Domain: | x_i | < 5.0
// Global minimum is 0.0 at x_i = 0.00
bidouble Kowalik(const double X[])
{
    static double a[] = {
    0.1957, 0.1947, 0.1735, 0.1600, 0.0844,
    0.0627, 0.0456, 0.0342, 0.0323, 0.0235,
    0.0246 };
    static double b[] = {
    4.0, 2.0, 1.0, 1/2.0,1/4.0,1/6.0,1/8.0,
    1/10.0,1/12.0,1/14.0, 1/16.0 };
    int i;
    double sum, bb, t;
    sum = 0.0;
    for (i= 0; i < 11; i++) 
    {
        bb = b[i] * b[i];
        t = a[i]-(X[0]*(bb+b[i]*X[1])/(bb+b[i]*X[2]+X[3]));
        sum += t * t;
    }

    returnbd(sum);
}


static double afox4[10][4]={ 
    {4,4,4,4 },
    {1,1,1,1 },
    {8,8,8,8 },
    {6,6,6,6 },
    {3,7,3,7 },
    {2,9,2,9 },
    {5,5,3,3 },
    {8,1,8,1 },
    {6,2,6,2 },
    {7,3.6,7,3.6}};

static double cfox4[10]= 
{.1,.2,.2,.4,.4,.6,.3,.7,.5,.5};

bidouble Shekel(int D, const double X[])
{
    double R, S;
    int i,j;

    assert(D<=10);

    R = 0;
    for(i=0; i<D; i++) 
    {
        S=0;
        for (j=0;j<4;j++) 
            S+=pow(X[j]-afox4[i][j],2);
        R -= 1/(S+cfox4[i]);
    }

    returnbd(R);
}

double step(double x)
{
    return (x>=0)? 1: 0;
}

bidouble Tripod(const double X[])
{
    returnbd(step(X[1])*(1+step(X[0]))+fabs(X[0] + 50*step(X[1])*(1-2*step(X[0])))+ fabs(X[1]+50*(1-2*step(X[1]))));
}


bidouble Dejong(int D, const double X[])
{
    double z;
    int i;

    z = 0;
    for (i=0; i<D; i++)
        z += (i+1)*X[i]*X[i]*X[i]*X[i];

    returnbd(z);
}

bidouble Alpine(int D, const double X[])
{
    double z;
    int i;

    z = 0;
    for (i=0; i<D; i++)
        z += fabs(X[i]*(sin(X[i])+0.1));

    returnbd(z);
}


// Global minimum 0 at (0)
bidouble Schaffer6(const double X[])
{
    double a,b,c;
    
    a = X[0]*X[0]+X[1]*X[1];
    b = sin(sqrt(a));
    c = 1+0.001*a;
    returnbd(0.5 + (b*b - 0.5)/c/c);
}


bidouble Pathological(int D, const double X[])
{
    double z, a, b;
    int i;

    z = 0;
    for (i=0; i<D-1; i++)
    {
        a = sin(sqrt(100*X[i]*X[i]+X[i+1]*X[i+1]));
        b = X[i]-X[i+1];
        b = b*b;
        b = b*b;
        z += 0.5+ (a*a-0.5)/(1+0.001*b);
    }

    returnbd(z);
}


bidouble Invcosine(int D, const double X[])
{
    double z, a;
    int i;

    z = 0;
    for (i=0; i<D-1; i++)
    {
        a = X[i]*X[i]+X[i+1]*X[i+1]+0.5*X[i]*X[i+1];
        z += exp(-0.125*a)*cos(4*sqrt(a));
    }

    returnbd(D-1-z);
}


bidouble Damavandi(const double X[])
{  
    double a, b, c, d, e, f;

    a = PI*(X[0]-2);
    b = PI*(X[1]-2);
    c = sin(a)/a*sin(b)/b;
    d = X[0]-7;
    e = X[1]-7;

    c = fabs(c);
    f = c*c;
    f = f*f;
    f = f*c;

    returnbd((1-f)*(2+d*d+e*e));
}

bidouble Eggholder(const double X[])
{  
    double a = X[1]+47.;

    returnbd(-a*sin(sqrt(fabs(0.5*X[0]+a)))-X[0]*sin(sqrt(fabs(X[0]-a))));
}


bidouble Bukin(const double X[])
{
    returnbd(100.*sqrt(fabs(X[1]-0.01*X[0]*X[0]))+0.01*fabs(X[0]+10.));
}

bidouble Crosslegtable(const double X[])
{
    double a,b;

    a = fabs(100-sqrt(X[0]*X[0]+X[1]*X[1])/PI);
    b = fabs(exp(a)*sin(X[0])*sin(X[1]));

    returnbd( -pow(b+1, -0.1));
}

bidouble Crossintray(const double X[])
{
    double a,b;

    a = fabs(100-sqrt(X[0]*X[0]+X[1]*X[1])/PI);
    b = fabs(exp(a)*sin(X[0])*sin(X[1]));

    returnbd(-0.0001*pow(b+1, 0.1));
}

bidouble Sineenvelope(int D, const double X[])
{
    double z,a,b,c;
    int i;

    z = 0;
    for (i=0; i<D-1; i++)
    {
        a = X[i]*X[i]+X[i+1]*X[i+1];
        b = sin(sqrt(a)-0.5);
        c = 0.001*a+1;
        z += b*b/c/c +0.5;
    }

    returnbd(-z);
}

bidouble Aluffi(const double X[])
{
    double a;

    a = X[0]*X[0];
    returnbd(0.25*a*a - 0.5*a +0.1*X[0] +0.5*X[1]*X[1]);
}

bidouble Becker(const double X[])
{
    double a, b;

    a = fabs(X[0])-5;
    b = fabs(X[1])-5;
    returnbd(a*a+b*b);
}

bidouble Oddsquare(int D, const double X[])
{
    assert(D<=20);
    static double B[20]={1, 1.3, 0.8, -0.4, -1.3,
        1.6, -2, -6, 0.5, 1.4,
        1, 1.3, 0.8, -4, -1.3,
        1.6, -0.2, -0.6, 0.5, 1.4};
    double z, w, v, a;
    int i;

    z = 0;
    w = 0;
    for (i=0; i<D; i++)
    {
        a = X[i]-B[i];
        z += a*a;
        
        v = fabs(a);
        if (v > w)
            w = v;
    }

    z = sqrt(z);
    w = w*sqrt(D);
    returnbd(-(1+ 0.2*z/(w+0.1))*cos(w*PI)*exp(-w/(2*PI)));
}

bidouble Pricemodel(const double X[])
{
    static double G[5][4]={
        {0.485, 0.752, 0.869, 0.982},
        {0.369, 1.254, 0.703, 1.455},
        {5.2095, 10.0677, 22.9274, 20.2153},
        {23.3037, 101.779, 111.461, 191.267},
        {28.5132, 111.8467, 134.3884, 211.4823}};

    double ALPHA[4], BETA[4];
    double z, a, b, c, d;
    int k;

    z = 0;
    for (k=0; k<4; k++)
    {
        a = G[0][k]-0.001*G[2][k]*X[6]-0.001*G[4][k]*X[7];
        b = G[0][k]-G[1][k]-0.001*G[2][k]*X[6]+0.001*G[3][k]*X[8];
        c = 1-X[0]*X[1];
        ALPHA[k] = c*X[2]*(exp(X[4]*a)-1)-G[4][k]+G[3][k]*X[1];
        BETA[k] =  c*X[3]*(exp(X[5]*b)-1)-G[4][k]*X[0]+G[3][k];

        z += ALPHA[k]*ALPHA[k] + BETA[k]*BETA[k];
    }

    d = X[0]*X[2]-X[1]*X[3];
    returnbd(z + d*d);
}

bidouble Bohachevsky1(const double X[])
{
    returnbd(X[0]*X[0] + 2*X[1]*X[1] -0.3*cos(3*PI*X[0]) -0.4*cos(4*PI*X[1]) +0.7);
}

bidouble Bohachevsky2(const double X[])
{
    returnbd(X[0]*X[0] + 2*X[1]*X[1] -0.3*cos(3*PI*X[0])*cos(4*PI*X[1]) +0.3);
}

bidouble Camelback3(const double X[])
{
    double a=X[0]*X[0];
    returnbd(2*a -1.05*a*a +1./6.*a*a*a + X[0]*X[1] + X[1]*X[1]);
}

bidouble Dekkers(const double X[])
{
    double a,b,c,d;
    
    a = X[0]*X[0];
    b = X[1]*X[1];
    c = a+b;
    d = c*c;
    returnbd(1E5*a +b -d + 1E-5*d*d);
}

bidouble Exponential(int D, const double X[])
{
    double z = 0.;
    int i;

    for (i=0; i<D; i++)
        z += X[i]*X[i];

    returnbd(exp(0.5*z));
}

bidouble Goldstein(const double X[])
{
    double a, b, c, d;

    a = X[0]+X[1]+1;
    b = 19 -14*X[0] +3*X[0]*X[0] -14*X[1] +6*X[0]*X[1] +3*X[1]*X[1];
    c = 2*X[0]-3*X[1];
    d = 18 -32*X[0] +12*X[0]*X[0] +48*X[1] -36*X[0]*X[1] +27*X[1]*X[1];

    returnbd((1+a*a*b)*(30+c*c*d));
}

bidouble Gulf(const double X[])
{
    double z, a, b;
    int i;

    z = 0;
    for (i=1; i<=99; i++)
    {   
        a = 25 +pow(-50*log(0.01*i), 1./1.5);
        b = exp(-pow(a-X[1], X[2])/X[0]) - 0.01*i;
        z += b*b;
    }

    returnbd(z);
}

bidouble Helical(const double X[])
{
    double a, b, c, d;

   
    a = (X[1]==0)? 0 : X[1]/X[0];
    if (a>DHUGE)
        a = DHUGE;
    if (a<-DHUGE)
        a = -DHUGE;

    b = atan(a)/(2*PI);
    if (X[0] < 0)
        b += 0.5;

    c = X[1] - 10*b;
    d = sqrt(X[0]*X[0]+X[1]*X[1])-1;
    returnbd(100*(c*c+d*d) + X[2]*X[2]);
}

bidouble Hosaki(const double X[])
{
    double a, a2, a3, a4;

    a = X[0];
    a2 = a*a;
    a3 = a2*a;
    a4 = a3*a;

    returnbd((1-8*a+7*a2-7./3.*a3+0.25*a4)*X[1]*X[1]*exp(-X[1]));
}

bidouble Montalvo(int D, const double X[])
{
    double z, a, b, c, d, e;
    int i;

    z = 0;
    a = 1 +0.25*(X[0]+1);
    d = sin(PI*a);
    for (i=0; i<D-1; i++)
    {
        b = 1+0.25*(X[i+1]+1);
        c = sin(PI*b);
        z += (a-1)*(a-1)*(1+10*c*c);
        a = b;
    }

    e = b-1;

    returnbd((PI/D)*(10*d*d +z +e*e));
}

bidouble Mccormick(const double X[])
{
    double a = X[0]-X[1];
    returnbd(sin(X[0]+X[1])+a*a -1.5*X[0] +2.5*X[1] +1);
}

bidouble Miele(const double X[])
{
    double a, b, c, d;

    a = exp(X[0])-X[1];
    a = a*a;
    a = a*a;

    b = X[1]-X[2];
    b = b*b;
    b = b*b*b;

    c = tan(X[2]-X[3]);
    c = c*c;
    c = c*c;

    d = X[0];
    d = d*d;
    d = d*d;
    d = d*d;

    returnbd(a + 100*b +c +d);
}

bidouble Multigaussian(const double X[])
{
    double A[5]={0.5, 1.2, 1., 1., 1.2};
    double B[5]={0, 1.0, 0, -0.5, 0};
    double C[5]={0, 0, -0.5, 0, 1};
    double E[5] = {0.1, 0.5, 0.5, 0.5, 0.5};
    double z, u, v;
    int i;

    z=0;
    for (i=0; i<5; i++)
    {
        u = X[0]-B[i];
        v = X[1]-C[i];
        z += A[i]*exp(-(u*u+v*v)/E[i]/E[i]);
    }

    returnbd(z);
}

bidouble Neumaier2(int D, const double X[])
{
    double B[4]={8, 18, 44, 114};
    double z, w, d;
    int k, i;

    assert(D==4);
    z = 0;
    for (k=1; k<=D; k++)
    {
        w = 0;
        for (i=0; i<D; i++)
            w += pow(X[i], k);
        
        d = B[k-1] - w;

        z += d*d;
    }

    returnbd(z);
}

bidouble Paviani(const double X[])
{
    double z, w, a, b;
    int i;

    z = 0;
    for (i=0; i<10; i++)
    {
        a = log(X[i]-2);
        b = log(10-X[i]);
        z += a*a + b*b;
    }

    w = 1;
    for (i=0; i<10; i++)
        w *= X[i];

    returnbd(z - pow(w, 0.2));
}

bidouble Periodic(const double X[])
{
    double a, b;

    a = sin(X[0]);
    b = sin(X[1]);

    returnbd(1+a*a+b*b -0.1*exp(-X[0]*X[0]-X[1]*X[1]));
}

bidouble Powell(const double X[])
{
    double a, b, c, d;
    
    a = X[0] + 10*X[1];
    b = X[2] - X[3];
    c = X[1] - 2*X[2];
    c = c*c;
    d = X[0] - X[3];
    d = d*d;

    returnbd(a*a +5*b*b +c*c + 10*d*d);
}

bidouble Salomon(int D, const double X[])
{
    double z = 0.;
    for (int i=0; i<D; i++)
        z += X[i]*X[i];

    z = sqrt(z);

    returnbd(1-cos(2*PI*z) + 0.1*z);
}

bidouble Schaffer2(const double X[])
{
    double a, b;

    a = X[0]*X[0]+X[1]*X[1];
    b = sin(50*pow(a, 0.1));

    returnbd(pow(a, 0.25)*(b*b+1));
}

bidouble Wood(const double X[])
{
    double a, b, c, d, e, f;

    a = X[1]-X[0]*X[0];
    b = 1-X[0];
    c = X[3]-X[2]*X[2];
    d = 1-X[2];
    e = X[1]-1;
    f = X[3]-1;

    returnbd(100*a*a +b*b +90*c*c + d*d + 10.1*(e*e+f*f)+19.8*e*f);
}