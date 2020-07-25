#include "hashQuad.hpp"
#include <limits.h>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

HashTable::HashTable(int bsize)
{
    //sets tableSize
    //sets all indices in the array to -1
    counter = 0;
    tableSize = bsize;
    table[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }
}

bool HashTable::insertItem(int key)
{
    //first if checks if the hash table is already full
    int x = 1;
    int hashI = hashFunction(key);
    int temp = hashI;
    //cout << hashI << endl;
    //don't need to go through for loop, start at hashI and insert directly there
    
    if(counter > 40008)
    {
        cout << "Hash table is full." << endl;
        return false;
    }
    //if there is an available slot at the hashing index then insert and increment counter
    if(table[hashI] == -1)
    {
        table[hashI] = key; 
        counter++;
        return true;
    }
    //else, while the key at the hashing index doesn't equal the key
    //create a new hash index using the quadratic hashing formula, incrementing x everytime the while loop repeats
    //if an empty slot is found, enter the key at the index
    else if(table[hashI] != -1)
    {
        while (table[hashI] != key)
        {
            numOfcolision++;
            hashI = (temp + x^2) % tableSize;

            if(table[hashI] == -1)
            {
                table[hashI] = key;
                counter++;
                return true;
            }
            x++;
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
    for(int i = 0; i < tableSize; i++)
    {
        cout << "Index: " << i << " @ value: " << table[i] << endl;
    }
}

int HashTable::getNumOfCollision()
{
    return numOfcolision;
}

int HashTable::getNumOfSearchCollision()
{
    return numOfSearchCollision;
}

int HashTable::searchItem(int key)
{
    //reuse the hashing and the rehash fuction in search to find the hash index of that key
    //the if statment that checks if table at x is equal to key makes sure we acutally find the right value
    //as opposed to going to where the hashing index directs us
    int x = hashFunction(key);
    int y = x;
    int z = 1;

    if(table[x] == key)
    {
        return key;
    }

    else
    {
        while(table[x] != key)
        {
            numOfSearchCollision++;

            x = (y + z^2) % tableSize;

            if(table[x] == key)
            {
                return table[x];
            }

            if(table[x] == -1)
            {
                cout << "Cannot be found." << endl;
                return -1;
            }
            z++;
        }
    return table[x];
    }
   
}