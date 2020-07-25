#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int insertIntoSortedArray(float myArray[], int numEntries, float newValue)
{
    if(numEntries == 0)
    {
        myArray[0] = newValue;
        numEntries++;
        return numEntries;
    }

    else if(numEntries > 0)
    {
        float temp[100];

        if(numEntries == 1 && newValue > myArray[0])
        {
            temp[0] = myArray[0];
            myArray[0] = newValue;
            myArray[1] = temp[0];
            numEntries++;
            return numEntries;
        }

        else if(numEntries == 1 && newValue < myArray[0])
        {
            myArray[1] = newValue;
            numEntries++;
            return numEntries;
        }

        else
        {
            for(int j = 0; j < numEntries; j++)
            {
                if(j == 0 && newValue > myArray[0])
                {
                    for(int i = 0; i < numEntries; i++)
                    {
                        temp[i] = myArray[i];
                    }

                    for(int i = 1; i <= numEntries; i++)
                    {
                        myArray[i] = temp[i - 1];
                    }
                    myArray[0] = newValue;
                    numEntries++;
                    return numEntries;
                }

                else if(j != 0 && (newValue < myArray[j - 1] && newValue > myArray[j + 1]))
                {
                    for(int i = 0; i < numEntries; i++)
                    {
                        temp[i] = myArray[j + 1];
                        j++;
                    }

                    myArray[j + 1] = newValue;
                    
                    numEntries++;
                    return numEntries;
                }

                else if(j == newValue - 1 && newValue < myArray[j])
                {
                    myArray[j + 1] = newValue;

                    numEntries++;
                    return numEntries;
                }
            }
        }
        // for(int i = 0; i < numEntries; i++)
        // {
        //     temp[i] = myArray[i];
        // }
        // //cout << temp[0] << endl;

        // for(int i = 1; i <= numEntries; i++)
        // {
        //     myArray[i] = temp[i - 1];
        // }
        // myArray[0] = newValue;
        // numEntries++;
        // for(int i = 0; i < numEntries; i++)
        // {
        //     cout << myArray[i] << " ";
        // }
        // cout << endl;
        // return numEntries;
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