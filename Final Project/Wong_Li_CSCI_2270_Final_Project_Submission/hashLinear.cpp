#include "hashLinear.hpp"
#include <limits.h>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

HashTable::HashTable(int bsize)
{
    //sets tableSize
    //sets all indices in the array to -1
    tableSize = bsize;
    table[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }
}

bool HashTable::insertItem(int key)
{
    //test = new int[400009];

    int hashI = hashFunction(key);
    //cout << hashI << endl;
    //don't need to go through for loop, start at hashI and insert directly there
    //counter keeps track of whether or not the table is full
    //if the table at the hash index os equal to -1 then insert
    //if not increment hash index by one and check again if it is open
    //check if the index has stepped out of bounds the whole while

    if(counter > 40008)
    {
        cout << "Hash Table full." << endl;
    }

    if(table[hashI] == -1)
    {
        counter++;
        table[hashI] = key; 
        return true;
    }

    else if(table[hashI] != -1)
    {
        while (table[hashI] != -1)
        {
            numOfcolision++;

            if(hashI == 40008 && table[40008] != -1)
            {
                hashI = 0;
            }

            hashI++;

            if(table[hashI] == -1)
            {
                counter++;
                table[hashI] = key;
                return true;
            }
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
        cout << table[i] << endl;
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

//same idea as the insertion but instead the function loops through until it sees the value we are looking for
int HashTable::searchItem(int key)
{
   int x = hashFunction(key);

   if(table[x] == key)
   {
       return key;
   }

   else
   {
       while(table[x] != key)
       {
            numOfSearchCollision++;
            
            if(table[x] == -1)
            {
                cout << "Key cannot be found." << endl;
                return 0;
            }

            if(x == 40008 && table[40008] != key)
            {
                x = -1;
            }

            x++;
       }

       return table[x];
   }
   
}