#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int insertIntoSortedArray(float myArray[], int numEntries, float newValue)
{
    if(numEntries == 0)
    {
        myArray[numEntries] = newValue;             //inserts new value into end of array
        numEntries++;
        return numEntries;
    }

    else
    {
        for(int i = 0; i < numEntries; i++)
        {
            //cout << newValue << " " << myArray[i] << endl;
            if(newValue >= myArray[i])
            {
                //cout << "Test" << endl;
                for(int k = numEntries; k > i; k--)
                {
                    myArray[k] = myArray[k - 1];
                }

                myArray[i] = newValue;
                numEntries++;
                return numEntries;
            }        
        }

        myArray[numEntries] = newValue;
        numEntries++;
        return numEntries;
    }
}

int main(int argc, char const *argv[])
{
    float myArray[100];
    int numEntries = 0;
    float newValue;
    string line;

    if(argc == 2)
    {
        ifstream inFile(argv[1]);

        if(inFile.is_open())
        {
            while(getline(inFile, line))
            {
                if(line != "")
                {
                    newValue = stof(line);
                    numEntries = insertIntoSortedArray(myArray, numEntries, newValue);
                    for(int i = 0; i < numEntries - 1; i++)
                    {
                        cout << myArray[i] << ",";
                    }
                    cout << myArray[numEntries - 1];
                    cout << endl;
                }
            }
        }

        else
        {
            cout << "Failed to open the file." << endl;
        }
    }

    else
    {
        cout << "Invalid amount of arguments." << endl;
    }
}