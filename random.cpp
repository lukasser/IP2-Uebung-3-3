/*
 *  random.cpp
 *  Uebung3_3
 *
 *  Created by Stefan Lukasser on 4/19/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#include <stdlib.h>
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
    arc4random_stir();
}

/* get_rand: Return new random number
 *
 * Arguments: None
 * Returns: random number
 */
int
get_rand(int upper)
{
    return arc4random() % ((unsigned)upper + 1);
}