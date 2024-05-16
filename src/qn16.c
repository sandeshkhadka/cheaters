//16. Write a program to implement the hashing techniques.
#include <stdio.h>

#define TABLE_SIZE 10 // Size of the hash table

int hash(int key) { return key % TABLE_SIZE; }

void insert(int data[], int key, int value) {
  int index = hash(key);
  if (data[index] == -1) {
    data[index] = value;
    printf("Inserted key %d with value %d at index %d\n", key, value, index);
  } else {
    printf("Collision occurred at index %d. Key %d cannot be inserted.\n",
           index, key);
  }
}

void search(int data[], int key) {
  int index = hash(key);
  if (data[index] != -1) {
    printf("Key %d found with value %d\n", key, data[index]);
  } else {
    printf("Key %d not found in the hash table.\n", key);
  }
}

int main() {
  int data[TABLE_SIZE];

  // Initialize all hash table elements to -1 (empty)
  for (int i = 0; i < TABLE_SIZE; i++) {
    data[i] = -1;
  }

  // Insert some key-value pairs
  insert(data, 1, 50);
  insert(data, 5, 60);
  insert(data, 12, 70); // Collision will occur here

  // Search for some keys
  search(data, 1);
  search(data, 5);
  search(data, 12);
  search(data, 13);

  return 0;
}
