#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    char str[10];

    ifstream iFile ("filename.txt");
    
    iFile >> str;
    cout << str << endl;

    cin.get();

    iFile.close();
}