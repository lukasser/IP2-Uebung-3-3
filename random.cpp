/*
 *  random.cpp
 *  Uebung3_3
 *
 *  Created by Stefan Lukasser on 4/19/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>
#include "random.h"


/* init_rand: Initialize the random number generator
 * 
 * Arguments: None
 * Returns: Nothing
 * from http://eternallyconfuzzled.com/arts/jsw_art_rand.aspx
 */
void
init_rand(void)
{
    time_t now = time(NULL);
    unsigned char *p = (unsigned char *)&now;
    unsigned seed = 0;
    size_t i;
    
    for (i=0; i<sizeof now; i++)
        seed = seed * (UCHAR_MAX + 2U) + p[i];
    
    srand(seed);
}

/* get_rand: Return new random number
 *
 * Arguments: None
 * Returns: random number
 */
long
get_rand(int upper)
{
    return rand() % upper;
}