#include <string>
#include <iostream>




struct TreeNode{
    int key;
    TreeNode * left;
    TreeNode * right;
};


//Implement a class for a binary search tree. Your class should include at least
//insert, search, and display methods.


class Tree
{
    private:
        TreeNode * root;

    public:
        Tree();
        void addNode(int data);
        bool searchTree(int data);
        void printTree();
        
    

};