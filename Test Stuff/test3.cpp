#include <iostream>

using namespace std;

// struct Distance
// {
//     int feet;
//     int inch;
// };

// int main()
// {
//     int a[] = {5, 4, 3, 2, 1};
//     int *ptr = (int*)(a+4);

//     cout << *a + 1 << ", " << *(ptr - 1) << endl;
// }

struct Node {
  int key;
  Node *next;
};

Node *pres = head;
int count = 0;

while(pres!= NULL && count < 3) 
{
    if(pres->key == 5) 
    {
        count = count + 1;
    }
    pres = pres->next;
}
cout <<  pres->key  << endl;