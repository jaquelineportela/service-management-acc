#ifndef SERVICETREE_H_INCLUDED
#define SERVICETREE_H_INCLUDED
#include "Heap.h"

typedef struct TreeNode {
    Service service;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
} ServiceTree;

ServiceTree* createServiceTree();
void destroyTree(ServiceTree* tree);
void insertTree(ServiceTree* tree, Service newService);
void printTree(ServiceTree* tree);

#endif
