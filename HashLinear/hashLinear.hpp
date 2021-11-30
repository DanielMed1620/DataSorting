#ifndef HASHLINEAR_HPP
#define HASHLINEAR_HPP

#include <string>


using namespace std;

struct nodeLine
{
    int key;
};

class HashTableLinear
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    nodeLine* *table;
    int numOfcolision =0;
    nodeLine* createNode(int key, nodeLine* next);
public:
    HashTableLinear(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    nodeLine* searchItem(int key);
};

#endif