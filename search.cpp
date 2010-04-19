/*
 *  search.cpp
 *  Uebung3_3
 *
 *  Created by Stefan Lukasser on 4/19/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "search.h"
#include <iostream>
using namespace std;

/* seq_search: sequential search for number in array
 *
 * Arguments: Pointer to array, number to search, upper bound of array
 * Returns: Position of number in array if found, -1 if not.
 */
int
seq_search(int arr[], int num, int upper)
{
    for (int i=0; i<upper; i++) {
        if (num == arr[i]) {
            return i;
        }
    }
    return -1; // not found
}

/* bin_search: Binary search for number in array
 *
 * Arguments: Pointer to array, number to search, upper bound of array
 * Returns: Position of number in array if found, -1 if not.
 */
int
bin_search(int arr[], int num, int upper)
{
    int left, right, x;
    left = 0, right = upper;

    while (right >= left) {
        x = (left+right)/2;
        if (num < arr[x]) {
            right = x-1;
        } else {
            left = x+1;
        }
        
        if (num == arr[x]) 
            return x; // found it at x
        
    }
    
    return -1; // not found
}