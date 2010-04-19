/*
 *  timing.cpp
 *  Uebung3_3
 *
 *  Created by Stefan Lukasser on 4/19/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#include "timing.h"
#include <sys/time.h>

/* get_time: set variable to current time in s
 * 
 * Args: None
 * Returns: current UNIX time in s
 */
double
get_time(void)
{
    timeval now;
    gettimeofday(&now, NULL);
    return now.tv_sec + now.tv_usec/1000000.0;
}