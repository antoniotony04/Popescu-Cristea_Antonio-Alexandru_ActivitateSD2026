#include <stdio.h>
#include <stdlib.h>

typedef struct Nod {
    int val;
    struct Nod* left;
    struct Nod* right;
} Nod;

Nod* creare(int val) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->val = val;
    nou->left = nou->right = NULL;
    return nou;
}

void inorder(Nod* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}