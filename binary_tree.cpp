/*
 *  binary_tree.cpp
 *  Uebung3_3
 *
 *  Created by Stefan Lukasser on 4/19/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#include "binary_tree.h"
#include "random.h"
#include <iostream>

/* Creation Functions */

/* make_node: Create a new node with data
 *
 * Arguments: Data for node
 * Returns: Pointer to new node
 */
node*
make_node(int number)
{
    node *it = new node;
    
    it->number = number;
    it->link[0] = NULL;
    it->link[1] = NULL;
    
    return it;  
}

/* Insertion Functions */

/* insert: Insert number into tree
 *
 * Arguments: Pointer to root node, number to insert
 * Returns: Nothing
 */
void
insert(tree *t, int number)
{
    if (t->root == NULL) {
        t->root = make_node(number);
    } else {
        node *it = t->root;
        int dir;
        
        for (;;) {
            dir = it->number < number;
            if (it->link[dir] == NULL)
                break;
            it = it->link[dir];
        }
        
        it->link[dir] = make_node(number);
    }
    
}

/* insert_rands: Insert N random numbers into tree
 *
 * Arguments: Pointer to tree, number of elems to insert
 * Returns: Nothing
 */
void
insert_rands(tree *tree, int num)
{
    int random_num;
    init_rand();
    
    for (int i=0; i<num; i++) {
        random_num = get_rand(num); // get new random number [0..num)
        insert(tree, random_num);
    }
}

/* Traversal Functions */

/* flatten: Traverse tree in-order
 *
 * Arguments: Pointer to root node, pointer to array for number storage
 * Returns: Nothing
 */
void
flatten(node *root, int arr[], int *i)
{    
    if (root != NULL) {
        flatten(root->link[0], arr, i);
        arr[*i] = root->number;
        *i = *i + 1;
        flatten(root->link[1], arr, i);
    }
}

/* Deletion Functions */

/* destroy: Destruction of tree
 *
 * Arguments: Pointer to tree
 * Returns: Nothing
 */
void
destroy(tree *tree)
{
    node *it = tree->root;
    node *save;
    
    while (it != NULL) {
        if (it->link[0] != NULL) {
            // right rotation
            save = it->link[0];
            it->link[0] = save->link[1];
            save->link[1] = it;
        } else {
            save = it->link[1];
            delete it;
        }
        
        it = save;
    }    
}	