#include <iostream>
#include "bst.hpp"

BST::BST() //the root of the BST is set to nullptr
{
    root = nullptr;
}

void addNodeHelper(Node* &t, Node* newNode) //this function helps add a new node
{
    if (newNode -> key >= t -> key)
    {
        if (t -> right == nullptr)
        {
            t -> right = newNode;
            t -> left = nullptr;
            t -> right = nullptr;
        }
        else
        {
            addNodeHelper(t->right, newNode);
        }
        
        
    }
    if (newNode -> key < t-> key)
    {
        if (t -> left == nullptr)
        {
            t -> left = newNode;
            t -> left = nullptr;
            t -> right = nullptr;
        }
        else
        {
            addNodeHelper(t->left, newNode);
        }
        
        
    }
}
void BST::addNode(int key) //adds a new node to the BST
{
    Node* newNode = new Node;
    newNode -> key = key;
    if(root == nullptr)
    {
        root = newNode;
        root -> left = nullptr;
        root -> right = nullptr;
    }
    else
    {
        addNodeHelper(root, newNode);
    }
}

Node* searchNodeHelper(Node* ptr, int num)
{
  if(ptr == nullptr)
  {
    return nullptr;
  }
  if(ptr->key == num)
  {
    return ptr;
  }
  if(searchNodeHelper(ptr->left, num) != nullptr)
  {
    return searchNodeHelper(ptr->left, num);
  }
  else
  {
    return searchNodeHelper(ptr->right, num);
  }
}

Node* BST::searchNode(int num) //search function the finds the node we are looking for that has the corrisponding number that we want
{
    Node* newNode = new Node;
  
    return searchNodeHelper(root, num);
}

