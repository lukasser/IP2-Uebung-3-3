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
#include <stdlib.h>

/* Creation Functions */

/* make_node: Create a new node with data
 *
 * Arguments: Data for node
 * Returns: Pointer to new node
 */
node*
make_node(long number)
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
 * Arguments: Pointer to tree, number to insert
 * Returns: Nothing
 */
void
insert(tree *tree, long number)
{
    if (tree->root == NULL)
        tree->root = make_node(number);
    else {
        node *it = tree->root; 
        int dir;
        
        for (;;) {
            dir = it->number < number; // which direction?
            
            if (it->link[dir] == NULL) // we've reached a leaf
                break;

            it = it->link[dir]; // link to the node we want to insert the data
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
        random_num = get_rand()%num; // get new random number and cast out num
        insert(tree, random_num);
    }
}

/* Traversal Functions */

/* inorder: Traverse tree in-order
 *
 * Arguments: Pointer to root node, pointer to array for number storage
 * Returns: Nothing
 */
void
inorder(node *root, long *arr)
{
    if (root != NULL) {
        inorder(root->link[0], arr);
        *arr = root->number;
        arr++;
        inorder(root->link[1], arr);
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