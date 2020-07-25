#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void swap(int *ip)
{
    *ip = 0;
}

int main()
{
    int i = 100;
    int *p = &i;
    swap(p);
    cout << *p << endl;
}