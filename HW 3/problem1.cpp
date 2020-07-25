#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

bool append(string *& str_arr, string s, int &numEntries, int &arraySize)
{
    bool check = false;

    if(numEntries == arraySize)
	{
		//str_arr = resize(str_arr, capacity);
        int newCapacity = 2 * arraySize;
        cout << "Resizing from " << arraySize << " to " << newCapacity << endl;

        string *newArray = new string[newCapacity];

        for(int i = 0; i < arraySize; i++)
        {
            newArray[i] = str_arr[i];
        }
        delete[] str_arr;

        str_arr = newArray;
        arraySize = newCapacity;

        check = true;
	}

    str_arr[numEntries] = s;
    numEntries++;

    return check;
}

int main(int argc, char* argv[])
{
    int arraySize = 100;
    int numEntries = 0;
    string s;
    string *str_arr = new string[(arraySize)];
    
    string filename = argv[1];
	ifstream data;
	data.open(filename.c_str());
    
	string temp;

    if(argc != 2)
	{
		cout << "Incorrect number of inputs." << endl;
	}

	if(data.is_open())
	{
		while(getline(data, temp))
		{
			// int toBeInsert = stoi(temp);
			// str_arr[numOfElement] = toBeInsert;
			// numOfElement++;

            append(str_arr, s, numEntries, arraySize);
		}
		data.close();
	}

	for(int i = 0; i < numEntries; i++)
	{
		cout << "Num: " << str_arr[i] << endl;
	}
	return 0;    
}