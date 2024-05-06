#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define PRIME 7
typedef struct {
    int key;
    char value[20];
} Data;

typedef struct {
    Data data;
    int status; // 0 = empty, 1 = occupied, -1 = deleted
} Entry;

Entry table[SIZE];

int hash(int key) {
    return key % SIZE;
}

int hash2(int key) {
	return (PRIME - (key % PRIME));
    //return 1 + (key % (SIZE - 1));
}

void init_table() {
	int i;
    for (i = 0; i < SIZE; i++) {
        table[i].status = 0;
    }
}

void insert(int key, char *value) {
    Data data;
    data.key = key;
    strncpy(data.value, value, 20);

    int index = hash(key);
    int i = 0;
    int offset = hash2(key);

    while (table[index].status == 1) {
        i++;
        index = (index + offset * i) % SIZE;
    }

    table[index].data = data;
    table[index].status = 1;

    printf("Inserted %d:%s at index %d\n", key, value, index);
}

void delete(int key) {
    int index = hash(key);
    int i = 0;
    int offset = hash2(key);

    while (table[index].status != 0) {
        if (table[index].status == 1 && table[index].data.key == key) {
            table[index].status = -1;
            printf("Deleted key %d\n", key);
            return;
        }

        i++;
        index = (index + offset * i) % SIZE;
    }

    printf("Key %d not found\n", key);
}

void search(int key) {
    int index = hash(key);
    int i = 0;
    int offset = hash2(key);

    while (table[index].status != 0) {
        if (table[index].status == 1 && table[index].data.key == key) {
            printf("Found key %d:%s at index %d\n", key, table[index].data.value, index);
            return;
        }

        i++;
        index = (index + offset * i) % SIZE;
    }

    printf("Key %d not found\n", key);
}

int main() {
    init_table();

    insert(1, "Jansi");
    insert(2, "Mahi");
    insert(11, "Barathi");
    insert(4, "Aparna");

    search(1);
    search(11);
    search(3);

    delete(2);

    search(2);

    return 0;
}

