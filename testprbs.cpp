#include "myopt.h"
#include "testfuns.h"
#include "testprbs.h"
#include <stdio.h>

MYOPT opt;
const int DMAX=300;
double X[DMAX];
bidouble yval;
int s;

void BoundaryTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Sphere);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, 0);
        opt.SetUB(s, 5.12);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}


void SphereTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Sphere);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -5.12);
        opt.SetUB(s, 5.12);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void AxisTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Axis);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -5.12);
        opt.SetUB(s, 5.12);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void SchwefelTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Schwefel);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -65);
        opt.SetUB(s, 65);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void RosenbrockTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Rosenbrock);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -2);
        opt.SetUB(s, 2);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void RastriginTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Rastrigin);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -5.12);
        opt.SetUB(s, 5.12);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void GriewankTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Griewank);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -600);
        opt.SetUB(s, 600);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void SumdiffpowTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Sumdiffpow);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -1);
        opt.SetUB(s, 1);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void AckleyTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Ackley);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -32);
        opt.SetUB(s, 32);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void BealeTest()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Beale);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -4.5);
        opt.SetUB(s, 4.5);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void ColvilleTest()
{
    static double fmin=0;
    opt.Init(4, NP);
    opt.SetFunX(Colville);

    for (s=0; s<4; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void EasomTest()
{
    static double fmin=-1;
    opt.Init(2, NP);
    opt.SetFunX(Easom);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -100);
        opt.SetUB(s, 100);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Hartmann1Test()
{
    static double fmin=-3.8627821478207558;
    opt.Init(4, NP);
    opt.SetFunX(Hartmann1);

    for (s=0; s<4; s++)
    {
        opt.SetLB(s, 0);
        opt.SetUB(s, 1);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Hartmann2Test()
{
    static double fmin=-3.3353921529552482;
    opt.Init(6, NP);
    opt.SetFunX(Hartmann2);

    for (s=0; s<6; s++)
    {
        opt.SetLB(s, 0);
        opt.SetUB(s, 1);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void SixhumpTest()
{
    static double fmin=-1.0316284534898776;
    opt.Init(2, NP);
    opt.SetFunX(Sixhump);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -5);
        opt.SetUB(s, 5);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void LevyTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Levy);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void MatyasTest()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Matyas);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void PermTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Perm);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -D);
        opt.SetUB(s, D);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void MichalewiczTest()
{
    static double fmin=-9.6601517156413497;
    static int D=10;
    opt.Init(D, NP);
    opt.SetFunDX(Michalewicz);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, 0);
        opt.SetUB(s, PI);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void ZakharovTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Zakharov);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -5);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void BraninTest()
{
    static double fmin=0.39788735772973816;
    opt.Init(2, NP);
    opt.SetFunX(Branin);

    opt.SetLB(0, -5);
    opt.SetUB(0, 10);
    opt.SetLB(1, 0);
    opt.SetUB(1, 15);

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Schwefel22Test(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Schwefel22);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Schwefel21Test(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Schwefel21);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -100);
        opt.SetUB(s, 100);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void StepTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Step);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -100);
        opt.SetUB(s, 100);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void QuarticTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Quartic);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -1.28);
        opt.SetUB(s, 1.28);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void KowalikTest()
{
    static double fmin=0.00030748598780560438;
    opt.Init(4, NP);
    opt.SetFunX(Kowalik);

    for (s=0; s<4; s++)
    {
        opt.SetLB(s, -5);
        opt.SetUB(s, 5);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Shekel5Test()
{
    static double fmin=-10.153199679058231;
    opt.Init(5, NP);
    opt.SetFunDX(Shekel);

    for (s=0; s<5; s++)
    {
        opt.SetLB(s, 0);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Shekel7Test()
{
    static double fmin=-10.402940566818666;
    opt.Init(7, NP);
    opt.SetFunDX(Shekel);

    for (s=0; s<7; s++)
    {
        opt.SetLB(s, 0);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Shekel10Test()
{
    static double fmin=-10.536409816692050;
    opt.Init(10, NP);
    opt.SetFunDX(Shekel);

    for (s=0; s<10; s++)
    {
        opt.SetLB(s, 0);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void TripodTest()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Tripod);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -100);
        opt.SetUB(s, 100);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void DejongTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Dejong);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -1.28);
        opt.SetUB(s, 1.28);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void AlpineTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Alpine);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Schaffer6Test()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Schaffer6);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void PathologicalTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Pathological);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -100);
        opt.SetUB(s, 100);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void InvcosineTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Invcosine);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -5);
        opt.SetUB(s, 5);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void DamavandiTest()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Damavandi);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, 0);
        opt.SetUB(s, 14);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void EggholderTest()
{
    static double fmin=-959.64066272085097;
    opt.Init(2, NP);
    opt.SetFunX(Eggholder);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -512);
        opt.SetUB(s, 512);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void BukinTest()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Bukin);

    opt.SetLB(0, -15);
    opt.SetUB(0, -5);
    opt.SetLB(1, -3);
    opt.SetUB(1, 3);

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void CrosslegtableTest()
{
    static double fmin=-1;
    opt.Init(2, NP);
    opt.SetFunX(Crosslegtable);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void CrossintrayTest()
{
    static double fmin=-2.0626118708227397;
    opt.Init(2, NP);
    opt.SetFunX(Crossintray);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -15);
        opt.SetUB(s, 15);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void SineenvelopeTest()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunDX(Sineenvelope);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -100);
        opt.SetUB(s, 100);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void AluffiTest()
{
    static double fmin=-0.35238607380003645;
    opt.Init(2, NP);
    opt.SetFunX(Aluffi);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void BeckerTest()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Becker);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void OddsquareTest(int D)
{
    static double fmin=-1.0459494859811793;
    opt.Init(D, NP);
    opt.SetFunDX(Oddsquare);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -15);
        opt.SetUB(s, 15);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void PricemodelTest()
{
    static double fmin=7.5730646901217133e-29;
    opt.Init(9, NP);
    opt.SetFunX(Pricemodel);

    for (s=0; s<9; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Bohachevsky1Test()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Bohachevsky1);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -50);
        opt.SetUB(s, 50);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Bohachevsky2Test()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Bohachevsky2);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -50);
        opt.SetUB(s, 50);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Camelback3Test()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Camelback3);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -5);
        opt.SetUB(s, 5);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void DekkersTest()
{
    static double fmin=-24776.518342317693;
    opt.Init(2, NP);
    opt.SetFunX(Dekkers);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -20);
        opt.SetUB(s, 20);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void ExponentialTest(int D)
{
    static double fmin=1;
    opt.Init(D, NP);
    opt.SetFunDX(Exponential);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -1);
        opt.SetUB(s, 1);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void GoldsteinTest()
{
    static double fmin=3;
    opt.Init(2, NP);
    opt.SetFunX(Goldstein);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -2);
        opt.SetUB(s, 2);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void GulfTest()
{
    static double fmin=0;
    opt.Init(3, NP);
    opt.SetFunX(Gulf);

    opt.SetLB(0, 0.1);
    opt.SetUB(0, 100);
    opt.SetLB(1, 0);
    opt.SetUB(1, 25.6);
    opt.SetLB(2, 0);
    opt.SetUB(2, 5);

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void HelicalTest()
{
    static double fmin=0;
    opt.Init(3, NP);
    opt.SetFunX(Helical);

    for (s=0; s<3; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void HosakiTest()
{
    static double fmin=-2.3458115761013079;
    opt.Init(2, NP);
    opt.SetFunX(Hosaki);

    opt.SetLB(0, 0);
    opt.SetUB(0, 5);
    opt.SetLB(1, 0);
    opt.SetUB(1, 6);

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void MontalvoTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Montalvo);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void MccormickTest()
{
    static double fmin=-1.9132229549810367;
    opt.Init(2, NP);
    opt.SetFunX(Mccormick);

    opt.SetLB(0, -1.5);
    opt.SetUB(0, 4);
    opt.SetLB(1, -3);
    opt.SetUB(1, 3);

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void MieleTest()
{
    static double fmin=0;
    opt.Init(4, NP);
    opt.SetFunX(Miele);

    for (s=0; s<4; s++)
    {
        opt.SetLB(s, -1);
        opt.SetUB(s, 1);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void MultigaussianTest()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Multigaussian);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -2);
        opt.SetUB(s, 2);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Neumaier2Test()
{
    static double fmin=0;
    opt.Init(4, NP);
    opt.SetFunDX(Neumaier2);

    for (s=0; s<4; s++)
    {
        opt.SetLB(s, 0);
        opt.SetUB(s, 4);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}


void PavianiTest()
{
    static double fmin=-45.778469707446312;
    opt.Init(10, NP);
    opt.SetFunX(Paviani);

    for (s=0; s<10; s++)
    {
        opt.SetLB(s, 2);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void PeriodicTest()
{
    static double fmin=0.9;
    opt.Init(2, NP);
    opt.SetFunX(Periodic);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void PowellTest()
{
    static double fmin=0;
    opt.Init(4, NP);
    opt.SetFunX(Powell);

    for (s=0; s<4; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void SalomonTest(int D)
{
    static double fmin=0;
    opt.Init(D, NP);
    opt.SetFunDX(Salomon);

    for (s=0; s<D; s++)
    {
        opt.SetLB(s, -100);
        opt.SetUB(s, 100);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void Schaffer2Test()
{
    static double fmin=0;
    opt.Init(2, NP);
    opt.SetFunX(Schaffer2);

    for (s=0; s<2; s++)
    {
        opt.SetLB(s, -100);
        opt.SetUB(s, 100);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}

void WoodTest()
{
    static double fmin=0;
    opt.Init(4, NP);
    opt.SetFunX(Wood);

    for (s=0; s<4; s++)
    {
        opt.SetLB(s, -10);
        opt.SetUB(s, 10);
    }

    opt.SetVTR(fmin+TOL);
    opt.Solve(X, yval);
}
