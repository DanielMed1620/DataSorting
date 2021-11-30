#include <iostream>
struct Node
{
      int key;
      Node *next;
};

class LinkList
{
    private:
        // pointer to head of linked list of cities
        Node* head;
    public:
        LinkList();
        void insertNode(Node* previous, int num);
        Node* lastNode();
        Node* searchNode(int num);
        void displayNode();
};