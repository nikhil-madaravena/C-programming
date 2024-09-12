#include <stdio.h>
#include <stdlib.h>

// AVL tree node structure
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

typedef struct Node Node;

// Function to get the height of a node
int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new AVL tree node
struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Function to right rotate a subtree rooted with y
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate a subtree rooted with x
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a key into the AVL tree
struct Node *insert(struct Node *node, int key) {
    // Perform the normal BST insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->key)


        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed
        return node;

    // Update height of current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No rotation needed
    return node;
}

// Function to print the AVL tree in-order
void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}


struct Node *findMinNode(Node *node){
	Node *current=node;
	while(current->left!=NULL)
		current=current->left;
	return current;
}

struct Node *deleteNode(Node *root,int key){
	if(root==NULL)
		return root;
		
	if(key<root->key)
		root->left=deleteNode(root->left,key);
		
	else if(key>root->key)
		root->right=deleteNode(root->right,key);	
	else{
		
		if((root->left==NULL)||(root->right==NULL)){
			Node *temp=root->left?root->left:root->right;
			
			if(temp==NULL){
				temp==root;
				root=NULL;
			}
			else
				*root=*temp;
			free(temp);
		}
		else{
			
			Node *temp=findMinNode(root->right);
			root->key=temp->key;
			root->right=deleteNode(root->right,temp->key);
			
		}
	}
	
	if(root==NULL)
		return root;
		
	root->height=1+max(height(root->left),height(root->right));
	
	int balance=getBalance(root);
	
	if(balance>1 && getBalance(root->left)>=0)
		return rightRotate(root);
		
	if(balance>1 && getBalance(root->left)<0){
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	
	if(balance<-1 && getBalance(root->right)<=0)
		return leftRotate(root);
		
	if(balance<-1 && getBalance(root->right)>0){
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}

int main() {
    struct Node *root = NULL;

    // Insert elements into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Print the AVL tree in-order
    printf("In-order traversal of AVL tree: ");
    inOrder(root);

	deleteNode(root, 30);
	
	printf("Traversal after : ");
	inOrder(root);
	
    return 0;
}
