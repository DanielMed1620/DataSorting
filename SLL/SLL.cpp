#include <iostream>
#include "SLL.hpp"
using namespace std;

LinkList::LinkList() //sets the head of the link list to be null
{
    head = nullptr;
}

void LinkList::insertNode(Node* previous, int num) //this is where we insert a new node by looking for the last not of the list and placing it after the last node and making its next node pointer null
{
    if (head == nullptr) //if the head of the list is a null, enter the number here
    {
        Node* newNode = new Node;
        newNode -> key = num; //sets a new node's key to to be the number that is inserted
        head = newNode; //the value for the head node is now the new node
        head -> next = nullptr; //the next node after the head is now null
    }
    else
    {
        Node* newNode = new Node;
        newNode -> key = num;
        previous -> next = newNode; //find the last node of the list is and then make the next pointer of it the new node that is going to be entered
        newNode -> next = nullptr; //the nodes next pointer is now null
    }
}

Node* LinkList::lastNode() //this function returns the last node in the link list
{
    Node* crawler = head; //head node
    if (head == nullptr) //if the head is null then return the crawler node with its key value
    {
        return crawler;
    }
    while (crawler -> next != nullptr) //while the next node of the crawler doesn't equal null, the crawler node then becomes the next node in the list and repeates until statement is true
    {
        crawler = crawler -> next;
    }
    return crawler;
}

Node* LinkList::searchNode(int num) //this is the search function when we are looking for a specific number in the link list then returns the node that has the number in it.
{
    Node* crawler = head;
    int i = 1;
    while (crawler != nullptr && crawler -> key != num)
    {
        crawler = crawler -> next;
        i++;
    }
    return crawler;
}


void LinkList::displayNode() //displays the node
{
  Node* crawler = head;
  while (crawler != NULL)
  {
    cout << crawler -> key << "->";
    crawler = crawler -> next;
  }
  cout << "NULL" << endl;
}