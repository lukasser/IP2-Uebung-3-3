/*
 *  timing.cpp
 *  Uebung3_3
 *
 *  Created by Stefan Lukasser on 4/19/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#include "timing.h"
#include <Windows.h>

/* get_time: set variable to current time in s
 * 
 * Args: None
 * Returns: current tickcount time in ms
 */
double
get_time(void)
{
    return GetTickCount();
}