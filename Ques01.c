// Implement insertion using binary search tree

#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node 
{
    int data;
    struct Node* right;      
    struct Node* left;
};

// node creation
struct Node* newnode (int value)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = value;                                             
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode ;
}

// node insertion
struct Node* insert(struct Node* root , int value)
{
    if (root == NULL)
       return newnode(value);   

    if (value < root -> data)
       root -> left = insert(root -> left , value);

    else if (value > root -> data)
       root -> right = insert(root -> right , value);
    
    return root ;   
}

// inorder traversal
