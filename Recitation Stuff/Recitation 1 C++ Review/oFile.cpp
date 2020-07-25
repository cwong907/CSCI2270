#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ofstream oFile("fileName.txt");

    oFile << "Inserted this test into fileName.txt";

    oFile.close();
}