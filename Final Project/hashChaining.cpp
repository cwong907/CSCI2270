#include "hashChaining.hpp"
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

node* HashTable::createNode(int key, node*next)
{
    //creates a new node, and assigns key and next pointer location to chain the linked list
    node *newN = new node;
    newN->key = key;
    newN->next = next;
    return newN;
}

bool HashTable::insertItem(int key)
{
    //gets hash index
    int hashI = hashFunction(key);
    //cout << hashI << endl;
    //don't need to go through for loop, start at hashI and insert directly there
    
    //if the table at that index doesn't have anything written to yet
    //then create a new node, adds a key, and sets the table at that index to point to the head of the linked list
    if(table[hashI] == NULL)
    {
        //node *n = createNode(key, NULL);
        node *n = new node;
        n->key =  key;
        n->next = NULL;
        table[hashI] = n;
        //cout << n->key << endl;
    }

    //if there already exists a linked list at that index
    //then create a new node and all that but assign it as the new head
    else if(table[hashI] != NULL)
    {
        numOfcolision++;
        node *m = new node;
        m->key = key;
        m->next = table[hashI];
        table[hashI] = m;
    }
}

unsigned int HashTable::hashFunction(int key)
{
    //hashing
    int index = key % tableSize;
    return index;
}

void HashTable::printTable()
{
    //increments thorugh the indicies and traverses each node of the linked list
    node* crawl = NULL;
    for(int i = 0; i < tableSize; i++)
    {
        cout << "Values at index: " << i << endl;
        crawl =  table[i];
        while(crawl != NULL)
        {
            cout << crawl->key << endl;
            crawl = crawl->next;
        }
    }
}

int HashTable::getNumOfCollision()
{
    return numOfcolision;
}

int HashTable::getNumOfSearchCollision()
{
    return numOfSearchCollisions;
}

node* HashTable::searchItem(int key)
{
    //gets the hash function of the key and traverses the linked list at index until found
    //assumes that we can always find the node, if not and if check can be implemented inside the while loop
    int look = hashFunction(key);
    node* find = NULL;

    find = table[look];
    while(find->key != key)
    {
        numOfSearchCollisions++;
        find = find->next;
    }

    return find;
    //cout << find->key << endl;
}