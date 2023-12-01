#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ServiceTree.h"
#include "heap.h"

TreeNode* createTreeNode(Service newService) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->service = newService;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

ServiceTree* createServiceTree() {
    ServiceTree* tree = (ServiceTree*)malloc(sizeof(ServiceTree));
    tree->root = NULL;
    return tree;
}

void destroyTreeRecursive(TreeNode* node) {
    if (node != NULL) {
        destroyTreeRecursive(node->left);
        destroyTreeRecursive(node->right);
        free(node);
    }
}

void destroyTree(ServiceTree* tree) {
    destroyTreeRecursive(tree->root);
    free(tree);
}

TreeNode* insertTreeRecursive(TreeNode* node, Service newService) {
    if (node == NULL) {
        return createTreeNode(newService);
    }

    if (strcmp(newService.priority, node->service.priority) < 0) {
        node->left = insertTreeRecursive(node->left, newService);
    } else {
        node->right = insertTreeRecursive(node->right, newService);
    }

    return node;
}

void insertTree(ServiceTree* tree, Service newService) {
    tree->root = insertTreeRecursive(tree->root, newService);
}

void printTreeRecursive(TreeNode* node) {
    if (node != NULL) {
        printTreeRecursive(node->left);
        printf("OS: %d\nDescricao: %s\nPrioridade: %s\nStatus: %s\n\n",
               node->service.os, node->service.description, node->service.priority, node->service.status);
        printTreeRecursive(node->right);
    }
}

void printTree(ServiceTree* tree) {
    printTreeRecursive(tree->root);
}
