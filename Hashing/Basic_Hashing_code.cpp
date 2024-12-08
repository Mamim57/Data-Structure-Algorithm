#include <bits/stdc++.h>
using namespace std;

const int HASH_TABLE_SIZE = 10; // Size of the hash table
int hashTable[HASH_TABLE_SIZE]; // Hash table array
bool occupied[HASH_TABLE_SIZE]; // To track filled slots

// Hash function (Simple modulo operation)
int hashFunction(int key)
{
    return key % HASH_TABLE_SIZE;
}

// Insert a key into the hash table
void insert(int key)
{
    int index = hashFunction(key);
    if (!occupied[index])   // Check if the slot is free
    {
        hashTable[index] = key;
        occupied[index] = true;
        cout << "Inserted key " << key << " at index " << index << endl;
    }
    else
    {
        cout << "Collision occurred for key " << key << " at index " << index << endl;
    }
}

// Search for a key in the hash table
bool search(int key)
{
    int index = hashFunction(key);
    if (occupied[index] && hashTable[index] == key)
    {
        return true; // Key found
    }
    return false; // Key not found
}

// Display the hash table
void displayHashTable()
{
    cout << "Hash Table:" << endl;
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        if (occupied[i])
        {
            cout << i << " -> " << hashTable[i] << endl;
        }
        else
        {
            cout << i << " -> Empty" << endl;
        }
    }
}

int main()
{
    memset(occupied, false, sizeof(occupied)); // Initialize hash table as empty

    cout << "Inserting keys into hash table..." << endl;
    insert(15); // 15 % 10 = 5
    insert(25); // 25 % 10 = 5 (collision)
    insert(35); // 35 % 10 = 5 (collision)
    insert(7);  // 7 % 10 = 7

    cout << "\nHash Table after insertion:" << endl;
    displayHashTable();

    int key;
    cout << "\nEnter a key to search: ";
    cin >> key;

    if (search(key))
    {
        cout << "Key " << key << " found in the hash table." << endl;
    }
    else
    {
        cout << "Key " << key << " not found in the hash table." << endl;
    }

    return 0;
}

