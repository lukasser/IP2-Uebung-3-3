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
    long number;    // random number to store on each node
    node *link[2];  // links
};

struct tree {
    node *root;
};

/* ---- API ---- */

// Creation Functions
node* make_node(long);       // Creates a new node

// Insertion Functions
void insert_rands(tree*, int); // Inserts N random numbers into tree
void insert(tree*, long);    // Inserts number into tree

// Traversal Functions
void inorder(node*, long*);  // Inorder traversal

// Deletion Functions
void destroy(tree*);        // Destruction of tree

