#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};

struct node *createNode(int data){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

struct node *insertNode(struct node *root, int data){
    struct node *newnode = createNode(data);
    if(root == NULL){
        root = newnode;
        return root;
    }
    if(root->data > data){
        root->left = insertNode(root->left,data);
    }
    else if(root->data < data){
        root->right = insertNode(root->right,data);
    }
}

struct node* findMin(struct node* node) {
    struct node* temp = node;

    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

struct node *deleteNodeRight(struct node *root, int key){
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNodeRight(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNodeRight(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNodeRight(root->right, temp->data);
    }
    return root;
}

struct node* findMax(struct node* node) {
    struct node* temp = node;

    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}


struct node *deleteNodeLeft(struct node *root, int key){
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNodeLeft(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNodeLeft(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMax(root->left);

        root->data = temp->data;

        root->left = deleteNodeLeft(root->left, temp->data);
    }
    return root;
}

//recursive
void preorder(struct node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void inorder(struct node *root){
    if(root != NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    }
    return;
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
    return;
}

int main(){
    struct node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
    root = insertNode(root, 70);

    printf("preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("postorder: ");
    postorder(root);
    printf("\n");

    root = deleteNodeRight(root, 20);
    printf("After deletion: ");
    inorder(root);
    printf("\n");

    root = deleteNodeLeft(root, 60);
    printf("After deletion : ");
    inorder(root);
    printf("\n");
}
