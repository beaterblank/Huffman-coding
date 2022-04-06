#include "heap.c"
#include <stdlib.h>
//structure for huffmanTree
typedef struct Hnode
{
   countC c;
   struct Hnode* left;
   struct Hnode* right;
}Hnode;

//initiate a Hnode with countC
Hnode* initHnode(countC c){
    Hnode* node = (Hnode*)malloc(sizeof(Hnode));
    node->c = c;
    return node;
}


//construct a huffman tree
Hnode* huffmanTree(countC* MinHeap){
    Hnode* croot=initHnode(getMin(MinHeap));
    while (SIZE>0)
    {
        Hnode* left = initHnode(getMin(MinHeap));
        Hnode* parent = initHnode(initCountC(-1,left->c.count+croot->c.count));
        parent->left = left;
        parent->right = croot;
        croot = parent;
    }
    return croot;
}

#define COUNT 10
void print2DUtil(Hnode *root, int space)
{
    
    if (root == NULL)
        return;
 
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->c.count);
 
    // Process left child
    print2DUtil(root->left, space);
}