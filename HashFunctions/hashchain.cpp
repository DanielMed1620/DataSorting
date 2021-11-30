#include<iostream>
#include<string>
#include"hashchain.hpp"
using namespace std;

HashTable::HashTable(int bsize) //default constructor creates an array of buckets
{
    this->tableSize = bsize;
    this->table = new node*[tableSize];
    for(int x = 0; x<tableSize; x++)
    {
        table[x] = new node;
        table[x]->key = x;
        table[x]->next = nullptr;
    }
}

unsigned int HashTable::hashFunction(int key)
{
    return key % tableSize; //given hash function
}

bool HashTable::insertItem(int key)
{
    int index = hashFunction(key); //gets index from hash function
    node* temp = table[index];
    node* newNode = new node;
    newNode->key = key;
    while(temp->next != nullptr) //finds empty space in correct bucket
    {
        temp = temp->next;
        numOfcolision++;
    }
    temp->next = newNode; //inserts item in correct space
}

void HashTable::printTable()
{
    node* temp;
    for(int x = 0; x<tableSize; x++)
    {
        temp = table[x];
        while(temp->next != nullptr) //prints bucket then nodes within
        {
            cout << temp->key << "->";
            temp = temp->next;
        }
        cout << temp->key << endl;
    }
}

int HashTable::getNumOfCollision()
{
    return numOfcolision;
}

node* HashTable::searchItem(int key)
{
    int index = hashFunction(key); //uses hash function to find index
    node* temp = table[index];
    while(temp->next != nullptr) //goes throught the bucket looking for desired node
    {
        numOfcolision++;
        if(temp->key == key) //returns the node when found
        {
            return temp;
        }
        temp = temp->next;
    }
    if(temp->key == key)
    {
        return temp;
    }
    cout << "node not found" << endl;
}