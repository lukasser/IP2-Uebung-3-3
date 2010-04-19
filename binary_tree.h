/*
 *  binary_tree.h
 *  Uebung3_3
 *
 *  Created by Stefan Lukasser on 4/19/10.
 *  Copyright 2010. All rights reserved.
 *
 */

/* ---- STRUCTS ---- */

struct node {
    int number;    // random number to store on each node
    node *link[2];  // links
};

struct tree {
    node *root;
};

/* ---- API ---- */

// Creation Functions
node* make_node(int);       // Creates a new node

// Insertion Functions
void insert_rands(tree*, int); // Inserts N random numbers into tree
void insert(tree*, int);    // Inserts number into tree

// Traversal Functions
void flatten(node*, int[], int*);  // Inorder traversal

// Deletion Functions
void destroy(tree*);        // Destruction of tree

