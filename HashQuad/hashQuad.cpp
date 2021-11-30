#include<iostream>
#include<string>
#include"hashQuad.hpp"
using namespace std;

HashTableQuad::HashTableQuad(int bsize) //default constructor creates an array of garbage node values
{
    this->tableSize = bsize;
    this->table = new nodeQuad*[tableSize]; //creates array according to the size parameter
    for(int x = 0; x<tableSize; x++)
    {
        table[x] = new nodeQuad;
        table[x]->key = -1;
    }
}

unsigned int HashTableQuad::hashFunction(int key)
{
    return key % tableSize;
}

bool HashTableQuad::Insert(int key)
{
    int num = 1; //multiplier number used for quadratic traverse
    int index = hashFunction(key); //finds index using hash function
    nodeQuad* newNode = new nodeQuad;
    newNode->key = key;
    while(table[index]->key != -1) //while loop traverses array quadraticly to find an open space
    {
        numOfcolision++;
        if(index + (num*num - (num-1)*(num-1)) > tableSize-1) //wrap around to avoid seg fault
        {
            index = (index + (num*num - (num-1)*(num-1)))-(tableSize);
        }
        else
        {
            index += (num*num - (num-1)*(num-1)); //changes the index quadraticly
        }
        num++;
    }
    table[index] = newNode; //inserts new node
}

void HashTableQuad::printTable()
{
    for(int x = 0; x<tableSize; x++)
    {
        cout << x << " -> " << table[x]->key << endl;
    }
}

int HashTableQuad::getNumOfCollision()
{
    return numOfcolision;
}

nodeQuad* HashTableQuad::Search(int key)
{
    int num = 1; //multiplier number used for quadratic traverse
    int index = hashFunction(key); //finds index using hash function
    while(table[index]->key != key || table[index]->key == -1) //while loop traverses array quadraticly to find desired node
    {
        numOfcolision++;
        if(index + (num*num - (num-1)*(num-1)) > tableSize-1) //wrap around to avoid seg fault
        {
            index = (index + (num*num - (num-1)*(num-1)))-(tableSize);
        }
        else
        {
            index += (num*num - (num-1)*(num-1));
        }
        num++;
    }
    if(table[index]->key == -1) //node not found case
    {
        cout << "node not found" << endl;
    }
    else
    {
        return table[index];
    }
}