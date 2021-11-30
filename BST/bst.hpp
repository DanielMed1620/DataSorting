#include <iostream>
using namespace std;
#define COUNT 10

/*
Each node in the BST has this structure
*/
struct Node
{
  int key;
  Node *left;
  Node *right;
};


class BST
{
  private:
  Node *root;
  public:
    BST();
    void addNode(int key);
    Node* searchNode(int num);
};
