#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left,*right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insertNode(struct node *root, int data) {
    struct node *newnode = createNode(data);
    if (root == NULL) {
        return newnode;
    }

    struct node *curr = root;
    struct node *par = NULL;

    while (curr != NULL) {
        par = curr;

        if (data < curr->data) {
            curr = curr->left;
        } 
        else if (data > curr->data) {
            curr = curr->right;
        } 
        else {
            return root;
        }
    }

    if (data < par->data) {
        par->left = newnode;
    } 
    else {
        par->right = newnode;
    }

    return root;
}

struct node* findMin(struct node* node) {
    struct node* temp = node;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

struct node* findMax(struct node* node) {
    struct node* temp = node;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

struct node *deleteNodeLeft(struct node *root, int data) {
    if (root == NULL)
        return NULL;

    struct node *curr = root;
    struct node *par = NULL;

    while (curr != NULL && curr->data != data) {
        par = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL)
        return root;

    if (curr->left == NULL || curr->right == NULL) {
        struct node *temp = (curr->left) ? curr->left : curr->right;

        if (par == NULL)
            root = temp;
        else if (par->left == curr)
            par->left = temp;
        else
            par->right = temp;

        free(curr);
    }
    else {
        struct node *temp = findMin(curr->right);
        curr->data = temp->data;
        curr->right = deleteNodeLeft(curr->right, temp->data);
    }

    return root;
}

struct node *deleteNodeRight(struct node *root, int data) {
    if (root == NULL)
        return NULL;

    struct node *curr = root;
    struct node *par = NULL;

    while (curr != NULL && curr->data != data) {
        par = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL)
        return root;

    if (curr->left == NULL || curr->right == NULL) {
        struct node *temp = (curr->left) ? curr->left : curr->right;

        if (par == NULL)
            root = temp;
        else if (par->left == curr)
            par->left = temp;
        else
            par->right = temp;

        free(curr);
    }
    else {
        struct node *temp = findMax(curr->left);
        curr->data = temp->data;
        curr->left = deleteNodeRight(curr->left, temp->data);
    }

    return root;
}

void inorder(struct node* root) {
    if (root == NULL) return;

    struct node* stack[100];
    int top = -1;
    struct node* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder(struct node* root) {
    if (root == NULL) return;

    struct node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

void postorder(struct node* root) {
    if (root == NULL) return;

    struct node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct node* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 >= 0)
        printf("%d ", stack2[top2--]->data);
}

int main() {
    struct node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
    root = insertNode(root, 70);

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    root = deleteNodeRight(root, 20);
    printf("Inorder after deleting 20: ");
    inorder(root);
    printf("\n");

    root = deleteNodeLeft(root, 60);
    printf("Inorder after deleting 60: ");
    inorder(root);
    printf("\n");

    return 0;
}
