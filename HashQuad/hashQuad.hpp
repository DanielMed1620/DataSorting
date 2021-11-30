#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP
#include <string>


using namespace std;

struct nodeQuad
{
    int key;
};

class HashTableQuad
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    nodeQuad* table;
    int numOfcolision =0;
    nodeQuad* createNode(int key, nodeQuad* next);
public:
    HashTableQuad(int bsize);  // Constructor

    // inserts a key into hash table
    bool Insert(int key);
    // hash function to map values to key
    unsigned int hashFunction(int key);
    void printTable();
    int getNumOfCollision();
    nodeQuad* Search(int key);
};

#endif
