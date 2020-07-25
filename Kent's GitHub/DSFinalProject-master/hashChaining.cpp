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

bool HashTable::insertItem(int key)
{
    int hashI = hashFunction(key);
    //cout << hashI << endl;
    //don't need to go through for loop, start at hashI and insert directly there
    
    if(table[hashI] == NULL)
    {
        node *n = new node;
        table[hashI] = n;
        n->key =  key;
        n->next = NULL;
        //cout << n->key << endl;
    }

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
    int index = key % tableSize;
    return index;
}

void HashTable::printTable()
{
    node* crawl = NULL;
    for(int i = 0; i < 2000; i++)
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

node* HashTable::searchItem(int key)
{
    int look = hashFunction(key);
    node* find = NULL;

    find = table[look];
    while(find->key != key)
    {
        find = find->next;
    }
    //cout << find->key << endl;
}