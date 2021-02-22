#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "xmalloc.h"

void *xmalloc(size_t sz)
{
    void *p=malloc(sz);
    
    if (p==NULL)
    {
        fprintf(stderr, "Insufficient memory, program exiting\n");
        exit(1);
    }

    return p;
}
