#include <stdio.h>
#include <stdlib.h>

// AVL tree node structure
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

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

// Function to left rotate a subtree rooted with y
struct Node *leftRotate(struct Node *y) {
    struct Node *x = y->right;
    struct Node *T2 = x->left;

    // Perform rotation
    x->left = y;
    y->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return x;
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

void preorder(struct Node *root){
    if(root != NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void inorder(struct Node *root){
    if(root != NULL){
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
    }
    return;
}

void postorder(struct Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
    return;
}

struct Node *findMinNode(struct Node *node){
	struct Node *current=node;
	while(current->left!=NULL)
		current=current->left;
	return current;
}

struct Node *deleteNode(struct Node *root,int key){
	if(root==NULL)
		return root;
		
	if(key<root->key)
		root->left=deleteNode(root->left,key);
		
	else if(key>root->key)
		root->right=deleteNode(root->right,key);	
	else{
		
		if((root->left==NULL)||(root->right==NULL)){
			struct Node *temp=root->left?root->left:root->right;
			
			if(temp==NULL){
				temp==root;
				root=NULL;
			}
			else
				*root=*temp;
			free(temp);
		}
		else{
			
			struct Node *temp=findMinNode(root->right);
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

void searchNode(struct Node* root, int data) {
    struct Node* curr = root;
    
    while (curr != NULL) {
        if (data == curr->key) {
            printf("Key found! \n");
            return;
        }
        else if (data < curr->key) {
            curr = curr->left; 
        } else {
            curr = curr->right;
        }
    }
    
    printf("key not found! ");
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

    printf("preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("postorder: ");
    postorder(root);
    printf("\n");

	deleteNode(root, 30);
	
	printf("Traversal after deletion : ");
	inorder(root);
    printf("\n");

    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);
    searchNode(root,key);
	
    return 0;
}
