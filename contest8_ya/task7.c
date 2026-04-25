#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* buildNode(){
    int value;
    if (scanf("%d", &value) != 1) {
        return NULL;
    }
    if (value == 0) {
        return NULL;
    }
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->data = 1;
    node->left = buildNode();
    node->right = buildNode();
    return node;
}


int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

int getHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + (leftHeight >= rightHeight ? leftHeight : rightHeight);
}

int countLeftChildren(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    if (root->left != NULL) {
        count++;
    }
    return count + countLeftChildren(root->left) + countLeftChildren(root->right);
}

void freeTree(struct Node *tree){
    if (!tree) return;
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

int main(){
    struct Node* root = buildNode();
    printf("%d\n", countNodes(root));
    printf("%d\n", countLeaves(root));
    printf("%d\n", getHeight(root));
    printf("%d\n", countLeftChildren(root));

    freeTree(root);
    return 0;
}

