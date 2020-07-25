#include "hash.hpp"
#include "linkedlist.hpp"
#include "BST.hpp"
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <sys/time.h>


void random_value(int theArray[], int sizeOfArray, int upper_range)
{
    srand(time(0));
    
    for(int i = 0; i < sizeOfArray; i++)
    {
       theArray[i] = 1 + (rand()%upper_range);
    }
}

int main()
{
//step 1. READ and LOAD in specified input into testing platform (dataSetA or dataSetB) ---------------------------------------------------

    string name;
    cout << "Enter file you are reading (dataSetA.csv or dataSetB.csv)" << endl;
    cin >> name;
    ifstream newFile;
    newFile.open(name);

    if(!newFile)
    {
        cout << "Failed to open file: " << name << endl;
        return 0; 
    }
    
    //read in entire test data to fill in array of integers ---------------------------------------
    int testData[40000] = {0};
    string line;
    int i = 0;

    while(!newFile.eof())
    {
        getline(newFile,line,',');
        testData[i] = stoi(line);
        i++;
    }

//step2 TIME TESTING ------------------------------------------------------------------------------------------------------
    //TIME TRACKING ARRAYS
    float LL_insert[400] = {0};           //linked list
    float BST_insert[400] = {0};          //binary search tree
    float HTChain_insert[400] = {0};      //Hashtable chaining
    float HTQP_insert[400] = {0};        //Hashtable quadratic probing
    float HTLP_insert[400] = {0};        //Hash table linear probing

    float LL_search[400] = {0};           //linked list
    float BST_search[400] = {0};          //binary search tree
    float HTChain_search[400] = {0};      //Hashtable chaining
    float HTQP_search[400] = {0};        //Hashtable quadratic probing
    float HTLP_search[400] = {0};        //Hash table linear probing


    //INITIALIZE DATASTRUCTURE CLASSES
    LinkedList LLDS;                   //Linked list data structure
    Tree BST;                             //binarysearch tree
    //HashTable1       chaining search method method
    //Hastable2        quadratic probing insertion method
    //Hashtable3       linear probing insertion method


//LINKED LIST IMPLEMENTATION -------------------------------------------------------------------------------------------
    cout << "LINKED LIST TESTING" << endl;
 

    //LL INSERTION TESTING----------------
    for(int y = 0; y < 400; y++)
    {   
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        ios_base::sync_with_stdio(false);

        
        for(int x = 0; x < 100; x++)
        {
            LLDS.insertNodeLL(testData[(y*100)+x]);
        }
        
        clock_gettime(CLOCK_MONOTONIC,&end);
        double time_taken;
        time_taken = (end.tv_sec - start.tv_sec) * 1e9;
        time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        cout << "Time taken by Linked List insertion program for " << y * 100 << " to " << y * 100 + 99 << " is " << fixed <<
        time_taken << endl;

        
        LL_insert[y] = time_taken / 100;         //STORING AVERAGE TIME TAKEN IN ARRAY
    }

    
    ofstream ofile(name + "_LinkedListInsert.csv");            //OUTPUT INSERTION DATA INTO NEW FILE
    
    for(int h = 0; h < 400; h++)
    {
        ofile << LL_insert[h] << "," << endl;
    }
        ofile.close();

    //LLDS.displayLL();


    //LL SEARCH TESTING-----------------
   

    int LL_randsearch[100] = {0};

    for(int x = 0; x < 400; x++)
    {
        random_value(LL_randsearch,100, x*100 + 100);                  //CREATE ARRAY OF RANDOM INTEGERS WITHIN CERTAIN RANGE

        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        ios_base::sync_with_stdio(false);
       
        for(int yx = 0; yx < 100; yx++)
        {
            LLDS.searchLL(testData[ LL_randsearch[yx] ]);
        }
        
        clock_gettime(CLOCK_MONOTONIC,&end);
        double time_taken;
        time_taken = (end.tv_sec - start.tv_sec) * 1e9;
        time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
        cout << "Time taken by Linked List search program for positions within:" << 0 << " to " << x * 100 + 99 << " is " << fixed <<
        time_taken << endl;

        
        LL_search[x] = time_taken / 100;                  //PUT THE AVERAGE SEARCH TIME INTO LINKED LIST SEARCH ARRAY
    }

       
    ofstream ofile2(name + "_LinkedListSearch.csv");             //OUTPUT AVERAGE SEARCH TIMES INTO FILE
    
    for(int h2 = 0; h2 < 400; h2++)
    {
        ofile2 << LL_search[h2] << "," << endl;
    }
        ofile2.close();



//BST IMPLEMENTATION-----------------------------------------------------------------------------------------------------------------
    cout << "BST TESTING" << endl;

    //BST INSERTION TESTING----------------------------


    for(int q = 0; q < 400; q++)
    {
        
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        ios_base::sync_with_stdio(false);

        for(int q2 = 0; q2 < 100; q2++)
        {
            BST.addNode(testData[(q * 100) + q2]);
        }
        
        clock_gettime(CLOCK_MONOTONIC,&end);
        double time_taken;
        time_taken = (end.tv_sec - start.tv_sec) * 1e9;
        time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        cout << "Time taken by BST insertion program for " << q * 100 << " to " << q * 100 + 99 << " is " << fixed <<
        time_taken << endl;
        
       
        BST_insert[q] = time_taken / 100;  //STORING AVERAGE TIME TAKEN IN ARRAY
    }

    //BST.printTree();

    
    ofstream ofile3(name + "BSTInsert.csv");  //OUTPUT INSERTION DATA INTO NEW FILE
    
    for(int h = 0; h < 400; h++)
    {
        ofile3 << BST_insert[h] << "," << endl;
    }
        ofile3.close();
    

    //BST SEARCH TESTING-----------------------------------------------

    int BST_randsearch[100] = {0};

    for(int x2 = 0; x2 < 400; x2++)
    {
        random_value(BST_randsearch,100, x2*100 + 100);                  //CREATE ARRAY OF RANDOM INTEGERS WITHIN CERTAIN RANGE
        
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        ios_base::sync_with_stdio(false);
        
        for(int yx = 0; yx < 100; yx++)
        {
            BST.searchTree(testData[ BST_randsearch[yx] ]);
        }
        
        clock_gettime(CLOCK_MONOTONIC,&end);
        double time_taken;
        time_taken = (end.tv_sec - start.tv_sec) * 1e9;
        time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
        cout << "Time taken by BST search program for positions within:" << 0 << " to " << x2 * 100 + 99 << " is " << fixed <<
        time_taken << endl;
    
        
        BST_search[x2] = time_taken / 100;     //PUT THE AVERAGE SEARCH TIME INTO LINKED LIST SEARCH ARRAY
    }

    
    ofstream ofile4(name + "_BSTSearch.csv");  //OUTPUT AVERAGE SEARCH TIMES INTO FILE
    
    for(int h3 = 0; h3 < 400; h3++)
    {
        ofile4 << BST_search[h3] << "," << endl;
    }
        ofile4.close();


//HASHING IMPLEMNTATION------------------------------------------------------------------------------------------------------


    return 0;
}