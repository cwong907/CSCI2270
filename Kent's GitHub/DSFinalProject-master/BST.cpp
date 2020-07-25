#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BST.hpp"

using namespace std;



Tree::Tree()
{
    root = NULL;
}

TreeNode * addNodeHelper(TreeNode * currNode, int data)
{
    if(currNode == NULL)             //if you reach a null put create a tree node
    {
        TreeNode * newTreeNode = new TreeNode;
        newTreeNode->key = data;
        newTreeNode->left = newTreeNode->right = NULL;
        return newTreeNode;
    }
    else if(currNode->key < data)
    {
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key >= data)
    {
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}

void Tree::addNode(int data)
{
    root = addNodeHelper(root,data);
    //cout << data << " has been added" << endl;
}

void printTreeHelper(TreeNode * currNode)
{
    if(currNode != NULL)
    {
        printTreeHelper(currNode->left);
        cout << currNode->key << ", ";
        printTreeHelper(currNode->right);
    }
}

void Tree::printTree()
{
    printTreeHelper(root);
}


TreeNode * searchKeyHelper(TreeNode * currNode,int data)
{

    while(currNode != NULL)
    {
        if(currNode->key > data)
        {
            currNode = currNode->left;
        }
        else if(currNode->key < data)
        {
            currNode = currNode->right;
        }
        else if(currNode->key == data)
        {
            //cout << "Data found " << currNode->key << endl;
            return currNode;
        }
    }
    
    cout << "Data not found" << endl;
    return NULL;
}

bool Tree::searchTree(int data)
{
    TreeNode * check = searchKeyHelper(root,data);
    if(check == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}


