#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_LEVEL 6 // Maximum level for the skip list

// Node structure for the skip list
typedef struct Node {
    int value;
    struct Node** forward; // Array of forward pointers
} Node;

// Skip list structure
typedef struct SkipList {
    int level;
    Node* header;
} SkipList;

// Create a new node with specified value and level
Node* createNode(int value, int level) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->forward = (Node**)malloc((level + 1) * sizeof(Node*));
    return newNode;
}

// Initialize a skip list with a header node
SkipList* initSkipList() {
    SkipList* skipList = (SkipList*)malloc(sizeof(SkipList));
    skipList->level = 0;
    skipList->header = createNode(INT_MIN, MAX_LEVEL);
    
    // Initialize forward pointers of header node to NULL
    for (int i = 0; i <= MAX_LEVEL; i++) {
        skipList->header->forward[i] = NULL;
    }

    return skipList;
}

// Generate a random level for a new node
int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// Insert a value into the skip list
void insert(SkipList* skipList, int value) {
    Node* current = skipList->header;
    Node* update[MAX_LEVEL + 1];
    
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];
    
    if (current == NULL || current->value != value) {
        int newLevel = randomLevel();
        
        if (newLevel > skipList->level) {
            for (int i = skipList->level + 1; i <= newLevel; i++) {
                update[i] = skipList->header;
            }
            skipList->level = newLevel;
        }

        Node* newNode = createNode(value, newLevel);
        
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

// Search for a value in the skip list
bool search(SkipList* skipList, int value) {
    Node* current = skipList->header;
    
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
    }

    current = current->forward[0];
    
    return (current != NULL && current->value == value);
}

// Display the skip list
void display(SkipList* skipList) {
    printf("Skip List:\n");
    for (int level = skipList->level; level >= 0; level--) {
        printf("Level %d: ", level);
        Node* current = skipList->header->forward[level];
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->forward[level];
        }
        printf("\n");
    }
}

// Main function to test skip list operations
int main() {
    // Initialize skip list
    SkipList* skipList = initSkipList();

    // Insert elements
    insert(skipList, 3);
    insert(skipList, 6);
    insert(skipList, 9);
    insert(skipList, 2);
    insert(skipList, 5);
    insert(skipList, 8);

    // Display skip list
    display(skipList);

    // Search for elements
    int searchValue = 5;
    printf("\nSearching for %d: %s\n", searchValue, search(skipList, searchValue) ? "Found" : "Not Found");

    // Clean up memory
    // Additional code for freeing memory should be added

    return 0;
}
