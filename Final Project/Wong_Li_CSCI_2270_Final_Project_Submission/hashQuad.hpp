//Cody Wong was responsible for the hash table implementation coding and Kent Li was 
//responsible for the BST and Linked List implementation coding. Both worked together on 
//the driver file for organization, time tracking, and input and output functions.

#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP

using namespace std;

class HashTable
{
private:
    int tableSize;
    int counter;
    int table[40009];
    int numOfcolision = 0;
    int numOfSearchCollision = 0;

public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();
    int getNumOfSearchCollision();
    int searchItem(int key);
};
#endif