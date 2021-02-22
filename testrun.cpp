#include "testprbs.h"
#include "myopt.h"
#include "optutil.h"
#include "blas.h"
#include <stdio.h>
#include <time.h>


typedef struct 
{
    char name[64];
    int dim;
    PRB_WITH_DIM *dtestfun;
    PRB_NO_DIM *ndtestfun;
} EXPERIMENT;


EXPERIMENT EXPR_LIST[];


int NP=100;
double TOL=1E-8;
UINT MAX_NFE = 1000000;
const int MAX_RUN = 50;
UINT NFE_RECORD[MAX_RUN];
int run;
FILE *fp;

void DoExperiment(int i)
{
    EXPERIMENT *pexpr = &EXPR_LIST[i];
    int D = pexpr->dim;
    int sum, k, succ;

    assert( (pexpr->dtestfun && !pexpr->ndtestfun) 
        || (!pexpr->dtestfun && pexpr->ndtestfun));

    printf("\n%s D=%d NP=%d TOL=%E\n",  pexpr->name, D, NP, TOL);
    fprintf(fp, "\n%s D=%d NP=%d TOL=%E\n",  pexpr->name, D, NP, TOL);

    if (pexpr->dtestfun)
    {
        for (run=0; run<MAX_RUN; run++)
        {
            ILASEED(run);
            pexpr->dtestfun(D);
        }
    }
    else
    {
        for (run=0; run<MAX_RUN; run++)
        {
            ILASEED(run);
            pexpr->ndtestfun();
        }
    }

    sum = 0;
    succ = 0;
    for (k=0; k<MAX_RUN; k++)
    {
        if (NFE_RECORD[k]<=MAX_NFE)
        {
            sum += NFE_RECORD[k];
            succ++;
        }
    }

    fprintf(fp, "Success rate = %f\n", (double)succ/(double)MAX_RUN);
    if (succ)
        fprintf(fp, "Average NFE = %d\n", sum/succ);

    fflush(fp);
}


int MYOPT::Interfun()
{
    int imin, s;

    if (NFE > MAX_NFE)
    {
        printf("failed\n");        
        NFE_RECORD[run] = NFE;
        return 1;
    }

    imin = FindMin_BD(NP, Y);
        
    if (Y[imin].low <= VTR)
    {
        printf("\n");
        for (s=0; s<D; s++)
            printf("X[%d]= %f\n", s+1, POP[imin*D+s]);
    
        printf("\nfmin= %.16e\n", Y[imin]);
        printf("%d\n", NFE);
        NFE_RECORD[run] = NFE;
        return 1;
    }


    // Display results every 100 iterations
    if (Iter%100==0)
    {
        //printf("\n");
        //for (i=0; i<NP; i++)
        //for (s=0; s<D; s++)
        //    printf("X[%d,%d]= %f\n", i+1, s+1, POP[i*D+s]);

        printf("\nfmin= %.16e\n", Y[imin]);
        printf("nfeval= %d\n", NFE);
    }

    return 0;
}

EXPERIMENT EXPR_LIST[] = 
{
    {"f1, Sphere",      30, SphereTest, NULL},
    {"f2, Axis",        30, AxisTest, NULL},
    {"f3, Schwefel",    20, SchwefelTest, NULL},
    {"f4, Rosenbrock",  30, RosenbrockTest, NULL},
    {"f5, Rastrigin",   10, RastriginTest, NULL},
    {"f6, Griewank",    30, GriewankTest, NULL},
    {"f7, Sumdiffpow",  30, SumdiffpowTest, NULL},
    {"f8, Ackley",      30, AckleyTest, NULL},
    {"f9, Beale",       2, NULL, BealeTest},
    {"f10, Colville",    4, NULL, ColvilleTest},
    {"f11, Easom",       2, NULL, EasomTest},
    {"f12, Hartmann1",   3, NULL, Hartmann1Test},
    {"f13, Hartmann2",   6, NULL, Hartmann2Test},
    {"f14, Sixhump",     2, NULL, SixhumpTest},
    {"f15, Levy",        30, LevyTest, NULL}, 
    {"f16, Matyas",      100, NULL, MatyasTest},
    {"f17, Perm",        4, PermTest, NULL},
    {"f18, Michalewicz", 10, NULL, MichalewiczTest},
    {"f19, Zakharov",    30, ZakharovTest, NULL},
    {"f20, Branin",      2, NULL, BraninTest},
    {"f21, Schwefel22",  30, Schwefel22Test, NULL},
    {"f22, Schwefel21",  30, Schwefel21Test, NULL},
    {"f23, Step",        30, StepTest, NULL},
    {"f24, Quartic",     30, QuarticTest, NULL}, 
    {"f25, Kowalik",     4, NULL, KowalikTest},
    {"f26, Shekel5",     4, NULL, Shekel5Test},
    {"f27, Shekel7",     4, NULL, Shekel7Test},
    {"f28, Shekel10",    4, NULL, Shekel10Test},
    {"f29, Tripod",      2, NULL, TripodTest},
    {"f30, Dejong",      2, DejongTest, NULL},
    {"f31, Alpine",      30, AlpineTest, NULL},
    {"f32, Schaffer6",   2, NULL, Schaffer6Test},
    {"f33, Pathological",5, PathologicalTest, NULL}, 
    {"f34, Invcosine",   5, InvcosineTest, NULL},
    {"f35, Aluffi",      2, NULL, AluffiTest},
    {"f36, Becker",      2, NULL, BeckerTest},
    {"f37, Bohachevsky1",2, NULL, Bohachevsky1Test},
    {"f38, Bohachevsky2",2, NULL, Bohachevsky2Test},
    {"f39, Camelback3",  2, NULL, Camelback3Test},
    {"f40, Dekkers",     2, NULL, DekkersTest},
    {"f41, Exponential", 10, ExponentialTest, NULL},
    {"f42, Goldstein", 2, NULL, GoldsteinTest},
    {"f43, Gulf", 3, NULL, GulfTest},
    {"f44, Helical", 3, NULL, HelicalTest},
    {"f45, Hosaki", 2, NULL, HosakiTest},
    {"f46, Montalvo", 3, MontalvoTest, NULL},
    {"f47, Mccormick", 2, NULL, MccormickTest},
    {"f48, Miele", 4, NULL, MieleTest},
    {"f49, Multigaussian", 2, NULL, MultigaussianTest},
    {"f50, Neumaier2", 4, NULL, Neumaier2Test},
    {"f51, Oddsquare", 10, OddsquareTest, NULL},
    {"f52, Paviani", 10, NULL, PavianiTest},
    {"f53, Periodic", 2, NULL, PeriodicTest},
    {"f54, Powell", 4, NULL, PowellTest},
    {"f55, Pricemodel", 9, NULL, PricemodelTest},
    {"f56, Salomon", 10, SalomonTest, NULL},
    {"f57, Schaffer2", 2, NULL, Schaffer2Test},
    {"f58, Wood", 4, NULL, WoodTest},
};    


#define EXPRS   main

int NUM_EXPR = sizeof(EXPR_LIST)/sizeof(EXPR_LIST[0]);

void EXPRS()
{
    int i;

    fp = fopen("record.txt", "wt");

    for (i=0; i<NUM_EXPR; i++)
        DoExperiment(i);

    fclose(fp);
}


void TESTS()
{
    //UINT seed = (UINT)time(NULL);
    //seed=1443112876;
    //ILASEED(seed);

    fp = fopen("record.txt", "wt");
    //fprintf(fp, "seed=%d\n", seed);


    //DoExperiment(3);

    SphereTest(100);
    //AxisTest(30);
    //SchwefelTest(20);
    //MAX_NFE = 200000000;
    //RosenbrockTest(30);
    //RastriginTest(30);
    //GriewankTest(30);
    //SumdiffpowTest(30);
    //AckleyTest(30);
    //BealeTest();
    //ColvilleTest();
    //EasomTest();
    //Hartmann1Test();
    //Hartmann2Test();
    //SixhumpTest();
    //LevyTest(30);
    //MatyasTest();
    //PermTest(4);
    //MichalewiczTest();
    //ZakharovTest(15);
    //BraninTest();
    //Schwefel22Test(60);
    //Schwefel21Test(60);
    //StepTest(30);
    //QuarticTest(30);
    //KowalikTest();
    //Shekel5Test();
    //Shekel7Test();
    //Shekel10Test();
    //TripodTest();
    //DejongTest(256);
    //AlpineTest(30);
    //Schaffer6Test();
    //PathologicalTest(5);
    //InvcosineTest(5);
    //EggholderTest();
    //CrosslegtableTest();
    //BukinTest();
    //CrossintrayTest();
    //SineenvelopeTest();

    //AluffiTest();  //f35
    //BeckerTest(); //f36
    //Bohachevsky1Test(); // f37
    //Bohachevsky2Test(); //f38
    //Camelback3Test(); //f39
    //DekkersTest(); //f40
    //ExponentialTest(20); //f41
    //GoldsteinTest(); //f42
    //GulfTest(); // f43
    //HelicalTest(); //f44
    //HosakiTest(); //f45
    //MontalvoTest(3); // f46
    //MccormickTest(); //f47
    //MieleTest(); //f48
    //MultigaussianTest(); //f49
    //Neumaier2Test(); // f50
    //OddsquareTest(10); // f51
    //PavianiTest(); //f52
    //PeriodicTest(); // f53
    //PowellTest(); // f54
    //PricemodelTest(); //f55 failed
    //SalomonTest(30); // f56 worse
    //Schaffer2Test();   //f57
    //WoodTest(); // f58

    /*NP=20;
    TOL=1E-20;
    MAX_NFE = 200000000;
    AckleyTest(20);
    RastriginTest(20);
    RosenbrockTest(20);*/
    //SphereTest(30);
    //EasomTest();
    //SchwefelTest(20);

    fclose(fp);
}
