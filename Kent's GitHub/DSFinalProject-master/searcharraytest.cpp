#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;



void random_value(int theArray[], int sizeOfArray, int upper_range, int random_seed)
{
    srand(time(0) + random_seed);
    
    for(int i = 0; i < sizeOfArray; i++)
    {
       theArray[i] = 1 + (rand()%upper_range);
    }
}

int main()
{

    ifstream newFile;
    newFile.open("DataSetA.csv");
    
    int testData[40000] = {0};
    int search[100] = {1,2,3,4,5,6,7,8,9,10};
    string line;
    int i = 0;


    while(!newFile.eof())
    {
        getline(newFile,line,',');
        testData[i] = stoi(line);
        i++;
    }

    cout << "value before revaluing" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << search[i] << ",";
    }
        cout << endl;
 
    for(int x = 0; x < 400; x++)
    {
        srand(time(0));
        int random_seed = rand() + x;
        random_value(search,100, x*100 + 100, random_seed);


        cout << "max value is " << x*100 + 100 << ": ";
        
        for(int yx = 0; yx < 100; yx++)
        {
            cout << search[yx] << ",";
            
            if(search[yx] > (x*100 + 100))
            {
                cout << "ERROR" << endl;
                return 0;
            }

        }
        cout << endl;
    }

}