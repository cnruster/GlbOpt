/* -------------------------------------------------------------------------
    WELL Algorithm

    Matsumoto (co-creator of the Mersenne Twister), L'Ecuyer (a major RNG 
    researcher), and Panneton introduced another class of TGFSR PRNGs in 
    2006 [Panneton06]. These algorithms produce numbers with better 
    equidistribution than MT19937 and improve upon ¡°bit-mixing¡± properties. 
    WELL stands for ¡°Well Equidistributed Long-period Linear¡±and they 
    seem to be better choices for anywhere MT19937 is currently used. They 
    are fast, come in many sizes, and produce higher quality random numbers.
    WELL period sizes are presented for period 2^n for n = 512, 521, 607, 
    800, 1024, 19937, 21701, 23209, and 44497, with corresponding state 
    sizes. This allows a user to trade period length for state size. All run 
    at similar speed. 2^512 is about 10^154, and it is unlikely any video 
    game will ever need that many random numbers, since it is far larger then
    the number of particles in the universe. The larger periods ones aren't 
    really needed except for computation like weather modeling or earth 
    simulations. A standard PC needs over a googol7 of years to count to 2^512.

    A significant place the WELL PRNGs perform better than MT19937 is in 
    escaping states with a large number of zeros. If MT19937 is seeded with many 
    zeros, or somehow falls into such a state, then the generated numbers have 
    heavy bias towards zeros for a many iterations. The WELL algorithms behave much 
    better, escaping zero bias states quickly.

    The only downside is that they are slightly slower than MT19937, but not much. 
    The upside is the numbers are considered to be higher quality, and the code is 
    significantly simpler. Here is WELL512 C code written by Chris Loment and 
    placed in the public domain. It is about 40% faster than the code presented on 
    L'Ecuyer's site, and is about 40% faster than MT19937 on Matsumoto's site
  ------------------------------------------------------------------------- */
 
#include "blas.h"
#include "double.h"
#include <assert.h>

// initialize state to random bits
static UINT state[16] = 
{
    0xED441570, 0x2BBB76C8, 0x73276792, 0x66739C9C,
    0x6189D44A, 0x2C1BAC00, 0x9DEC31E8, 0xB0100E59,
    0xCDDF7074, 0x42C707D0, 0x6AAE869C, 0x2F159D0D,
    0x24AA6EEB, 0x3786C1C7, 0xB705D8A4, 0xC89578C0
};

// init should also reset this to 0
static int index = 0;

void ILASEED(UINT sid)
{
    UINT *ptr = state;
    int i;

    for (i=1; i<9; i++)
    {
        ptr[0] = sid*i;
        ptr[1] = ~ptr[0];

        ptr += 2;
    }

    index = 0;
}


// return 32 bit random inter
UINT ILARAN()
{
    UINT a, b, c, d;

    a = state[index];
    c = state[(index+13)&15];
    b = a^c^(a<<16)^(c<<15);
    c = state[(index+9)&15];
    c ^= (c>>11);
    a = state[index] = b^c;
    d = a^((a<<5)&0xDA442D24U);
    index = (index + 15)&15;
    a = state[index];

    return state[index] = a^b^d^(a<<2)^(b<<18)^(c<<28);
}


// get random uint either zero or with one 1-bit whose position
// is not fixed. we can only check if it is zero
UINT ILABIT()
{
    static UINT bitmask = 0;
    static UINT ranint;
    UINT bit;

    if (!bitmask)
    {
        ranint = ILARAN();
        bitmask = 1;
    }

    bit = ranint & bitmask;
    bitmask <<= 1;

    return bit;
}


// return random double precision number
double DLARAN()
{
    DOUBLE dnum;

    dnum.i.mantissa_low = ILARAN();
    dnum.i.mhes = DMHES(ILARAN() & 0x000FFFFF, 1023, 0);

    return dnum.d - 1.;
}