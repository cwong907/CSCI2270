#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Park
{
    string parkname;
    string state;
    int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length)
{
  
    Park aPark;
    aPark.parkname = parkname;
    aPark.area = area;
    aPark.state = state;

    parks[length] = aPark;
}

void printList(const Park parks[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << parks[i].parkname << " [" << parks[i].state << "] " << "area: " << parks[i].area << endl; 
    }
}

int main(int argc, char const *argv[])
{
    Park parks[55];
    string parkname;
    string state;
    int area;
    int length = 0;
    string line;
    string line2;
    ofstream outFile(argv[2]);
    int minArea = stoi(argv[3]);
    int maxArea = stoi(argv[4]);

    if(argc == 5)
    {
        ifstream inFile(argv[1]);

        if(inFile.is_open())
        {
            while(getline(inFile, line))
            {
                if(line != "")
                {
                    stringstream np (line);

                    for(int i = 0; i < 3; i++)
                    {
                        getline(np, line2, ',');

                        if(i == 0)
                        {
                            parkname = line2;
                        }

                        else if(i == 1)
                        {
                            state = line2;
                        }

                        else if(i == 2)
                        {
                            area = stoi(line2);
                        }
                    }

                    addPark(parks, parkname, state, area, length);
                    length++;
                }
            }

            printList(parks, length);

            for(int i = 0; i < length; i++)
            {
                if(parks[i].area >= minArea && parks[i].area <= maxArea)
                {
                    outFile << parks[i].parkname << "," << parks[i].state << "," << parks[i].area << endl;
                }
            }

            outFile.close();
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