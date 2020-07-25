#include "hashChain.hpp"
#include <limits.h>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

HashTable::HashTable(int bsize)
{
    //sets tableSize and has the table pointer point to a dynamically
    //created array of node pointer types
    //sets all heads to NULL
    tableSize = bsize;
    table = new node*[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = NULL;
        //cout << "test" << endl;
    }
}

bool HashTable::insertItem(int key)
{
    int hashI = hashFunction(key);
    node *last = NULL;
    
    for(int i = 0; i < tableSize; i++)
    {
        if(table[i] == NULL && i == hashI)
        {
            node *n = new node;
            table[i] = n;
            n->key =  key;
            n->next = NULL;
        }

        else if(table[i] != NULL && i == hashI)
        {

        }
    }
}

unsigned int HashTable::hashFunction(int key)
{
    int index = key % tableSize;
    return index;
}

void HashTable::printTable()
{

}

int HashTable::getNumOfCollision()
{
    return numOfcolision;
}

node* HashTable::searchItem(int key)
{
    int look = hashFunction(key);
}
