#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* newNode(int key) {
    struct Node* node =
      (struct Node*) malloc(sizeof(struct Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) + 1;

    x->height = max(height(x->left),
                    height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) + 1;

    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;

    return height(N->left) - height(N->right);
}

struct Node *minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if(key > root->key)
        root->right = deleteNode(root->right, key);

    else {

        if((root->left == NULL) ||
           (root->right == NULL)) {

            struct Node *temp = root->left ?
                                root->left :
                                root->right;

            if(temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else {

            struct Node* temp =
                minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(struct Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    root = newNode(30);
    root->left = newNode(20);
    root->right = newNode(40);

    root = deleteNode(root, 20);

    printf("Preorder traversal:\n");
    preorder(root);

    return 0;
}