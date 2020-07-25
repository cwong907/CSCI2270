#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10

/*
PUBLIC METHODS:
*/

// Constructor definitions:
// Default:
BST::BST(){
    root = nullptr;
}

void BST::addNode(int data){
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

void BST::print2DUtil(int space)
{
    print2DUtilHelper(root, space);
}

/*
PRIVATE METHODS:
*/


//  TODO:
//  Write a function decrementLeaves that goes through a Binary Search Tree 
//  and subtracts 1 from each of the leaf nodes. Feel free to implement an 
//  additional helper function.

void traverseAndSubtract(Node *root)
{
    if(root != NULL)
    {
        traverseAndSubtract(root->left);
        traverseAndSubtract(root->right);
        
        if(root->parent != NULL && root->left == NULL && root->right == NULL)
        {
            root->key--;   
            if((root->parent->right == root) && (root->key < root->parent->key))
            {
                delete root;
                root->parent->right = NULL;
            }         
        }

        //so this is post-order traversal of the BST and the recursive calls the left and right children until it hits NULL which is the sign to pop back (the big outer if statement checks this)
        //the second if statement checks to make sure only leaf nodes get subtracted by one
        //the third if statement checks to see if that node we're at is the right child and not the left child and makes sure that the value of the right child is less than the parent node's value
        //then it deletes the node and reassigns the parent pointer to NULL to avoid garbage values
    }
}
void BST::decrement()
{
    traverseAndSubtract(root);
    //since decrement is a member function, it has access to root which we need to pass to our helper so we can go through every leaf node
}  


//   This function will add the data in the tree rooted at currNode.
//   Call this function from insert().


Node* BST:: addNodeHelper(Node* currNode, int data){
    if(currNode == nullptr){
       return createNode(data);      
    }
    else if(currNode->key <= data){
        currNode->right = addNodeHelper(currNode->right,data);
        currNode->right->parent = currNode;
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
        currNode->left->parent = currNode;
    }
    return currNode;
}


// Create a new node, setting key value to  input data
// and all pointers to null.
Node* BST:: createNode(int data){
    Node* newNode = new Node;
    newNode->key = data;
    newNode->parent = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* BST::getRoot(){
    return root;
}


/*
   Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space){
    // Base case
    if (currNode == nullptr)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}





