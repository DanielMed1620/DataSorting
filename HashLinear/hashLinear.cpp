#include<iostream>
#include<string>
#include"hashLinear.hpp"
using namespace std;

HashTableLinear::HashTableLinear(int bsize) //default constructor creates an array of useless node values
{
    this->tableSize = bsize;
    this->table = new nnodeLine*[tableSize]; //creates array according to the size parameter
    for(int x = 0; x<tableSize; x++)
    {
        table[x] = new nodeLine;
        table[x]->key = -1;
    }
}

unsigned int HashTableLinear::hashFunction(int key)
{
    return key % tableSize; //given hash function
}

bool HashTableLinear::insertItem(int key)
{
    int index = hashFunction(key); //finds index using hash function
    nodeLine* newNode = new nodeLine;
    newNode->key = key;
    while(table[index]->key != -1) //while loop traverses array linearly to find an open space
    {
        numOfcolision++;
        if(index == tableSize-1) //wrap around to avoid out of bounds error
        {
            index = 0;
        }
        else
        {
            index++;
        }
    }
    table[index] = newNode;
}

void HashTableLinear::printTable()
{
    for(int x = 0; x<tableSize; x++)
    {
        cout << table[x]->key << endl;
    }
}

int HashTableLinear::getNumOfCollision()
{
    return numOfcolision;
}

nodeLine* HashTableLinear::searchItem(int key)
{
    int index = hashFunction(key);
    while(table[index]->key != key) //while loop traverses array linearly until node is found
    {
        numOfcolision++;
        if(index == tableSize-1) //array wrap around
        {
            index = 0;
        }
        else
        {
            index++;
        }
    }
    return table[index];
}