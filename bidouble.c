#include "bidouble.h"

int BidblCmp(bidouble a, bidouble b)
{
    if (a.high < b.high)
        return -1;

    if (a.high > b.high)
        return 1;

    if (a.low < b.low)
        return -1;

    if (a.low > b.low)
        return 1;

    return 0;
}