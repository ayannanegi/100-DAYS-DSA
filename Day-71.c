//Problem Statement
//Implement a hash table using quadratic probing with formula:
//h(k, i) = (h(k) + i*i) % m
#include <stdio.h>

#define SIZE 10

int table[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;  // -1 means empty
    }
}

// Basic hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using quadratic probing
void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;

        if (table[index] == -1) {
            table[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
    }

    printf("Hash table is full! Cannot insert %d\n", key);
}

// Search using quadratic probing
void search(int key) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;

        if (table[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }

        if (table[index] == -1) {
            break; // stop early if empty slot
        }
    }

    printf("Key %d not found\n", key);
}

// Display table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("[%d] -> EMPTY\n", i);
        else
            printf("[%d] -> %d\n", i, table[i]);
    }
}

// Main
int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    display();

    search(25);
    search(99);

    return 0;
}
