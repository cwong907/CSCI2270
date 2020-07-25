//the hashLDriver.cpp and hashQDriver.cpp are basically identical to hashCDriver.cpp

#include "hashLinear.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;

void RNG(int rngIndex[], int size, int range)
{
    srand(0);

    for(int i = 0; i < size; i++)
    {
        rngIndex[i] = rand()%range;
    }
}

int main()
{
    //read and import data into array from dataSetA or dataSetB

    string fileName;
    
    cout << "Enter file you are reading (dataSetA.csv or dataSetB.csv)" << endl;
    cin >> fileName;
    ifstream newFile;
    newFile.open(fileName);

    if(!newFile)
    {
        cout << "Failed to open file: " << fileName << endl;
        return 0; 
    }
    
    //read in entire data to array
    //declare insert and search times arrays
    int testData[40000] = {-1};
    float HLinsert[400] = {-1};
    float HLsearch[400] = {-1};
    int rngIndex[100] = {-1};
    string line;
    int i = 0;
    int searchCollisions[4] = {-1};
    int insertCollisions[4] = {-1};
    int a = 0;
    int b = 0;
    //instantiate HashTable class with array size for the class
    HashTable Table(40009);

    while(!newFile.eof())
    {
        getline(newFile,line,',');
        testData[i] = stoi(line);
        i++;
    }
    //####testing stuff can ignore####
    //insert test
    // for(int i = 0; i < 2000; i++)
    // {
    //     Table.insertItem(testData[i]);
    //     //cout << testData[i] << endl;
    // }
    
//  ~~~~~INSERT AND TIMING~~~~~
    //outer for loop iterates the hundreds
    //inner loop goes through the tens and ones
    //also included is the timing
    for(int i = 0; i < 400; i++)
    {
        using namespace std::chrono;
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int x = (i * 100); x < (i * 100) + 100; x++)
        {
            Table.insertItem(testData[x]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> execTime = duration_cast<microseconds>(end - start);
        
        HLinsert[i] = (execTime.count() / 100);
        if(i == 99 || i == 199 || i == 299 || i == 399)
        {
            insertCollisions[a] = Table.getNumOfCollision();
            a++;
        }
    }
    //stores data in the file
    ofstream ofile(fileName + "_HashLinearInsertTimes.csv");        
    for(int i = 0; i < 400; i++)
    {
        ofile << HLinsert[i] << "," << endl;
    }
    ofile.close();

    ofstream ofile2(fileName + "_HashLinearInsertCollision.csv");        
    for(int i = 0; i < 4; i++)
    {
        ofile2 << insertCollisions[i] << "," << endl;
    }
    ofile2.close();
    

//  ~~~~~SEARCH AND TIMING~~~~~~
    for(int i = 0; i < 400; i++)
    {
        RNG(rngIndex, 100, (i*100)+100);
        using namespace std::chrono;
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int y = 0; y < 100; y++)
        {
            //cout << "test" << endl;
            Table.searchItem(testData[rngIndex[y]]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> time = duration_cast<microseconds>(end - start);
        
        HLsearch[i] = (time.count() / 100);
        //cout << HCsearch[i] << endl;
        if(i == 99 || i == 199 || i == 299 || i == 399)
        {
            searchCollisions[b] = Table.getNumOfSearchCollision();
            b++;
        }
    }
    
    ofstream ofile4(fileName + "_HashLinearSearchTimes.csv");
    for(int i = 0; i < 400; i++)
    {
        ofile4 << HLsearch[i] << "," << endl;
    }
    ofile4.close();

    ofstream ofile3(fileName + "_HashLinearSearchCollision.csv");        
    for(int i = 0; i < 4; i++)
    {
        ofile3 << searchCollisions[i] << "," << endl;
    }
    ofile3.close();
    //Table.printTable();
}    
    
    //####test stuff can ignore####
    //Table.printTable();
    //cout << "Number of collisions: " << Table.getNumOfCollision() << endl;
    //cout << execTime.count() << endl;
    // for(int i = 0; i < 400; i++)
    // {
    //     cout << HCinsert[i] << endl;
    // }
    //Table.searchItem(41700);