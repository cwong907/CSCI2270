//Cody Wong was responsible for the hash table implementation coding and Kent Li was 
//responsible for the BST and Linked List implementation coding. Both worked together on 
//the driver file for organization, time tracking, and input and output functions.

#ifndef HASHCHAINING_HPP
#define HASHCHAINING_HPP

using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked list)
    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision = 0;
    //keeps track of search collisions
    int numOfSearchCollisions = 0;
    node* createNode(int key, node* next);

public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();
    node* searchItem(int key);
    //returns number of search collisions
    int getNumOfSearchCollision();
};
#endif