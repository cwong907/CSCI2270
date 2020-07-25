#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct wordItem
{
    string word;
    int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
    string line;
    int counter = 0;
    ifstream inFile(ignoreWordFileName);    

    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            if(line != "")
            {
                ignoreWords[counter] = line;
                counter++;
            }
        }
    }

    else
    {
        cout << "Failed to open " << ignoreWordFileName << endl;
    }
    
}

bool isStopWord(string word, string ignoreWords[])
{
    for(int i = 0; i < 50; i++)
    {
        if(ignoreWords[i] == word)
        {
            return true;
        }
    }
    return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
    int total = 0;

    for(int i = 0; i < length; i++)
    {
        total = total + uniqueWords[i].count;
    }

    return total;
}

void arraySort(wordItem uniqueWords[], int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            if(uniqueWords[i].count < uniqueWords[j].count)
            {
                wordItem temp;
                temp = uniqueWords[j];
                uniqueWords[j] = uniqueWords[i];
                uniqueWords[i] = temp;
            }
        }
    }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords)
{
    for(int i = N; i < N + 10; i++)
    {
        cout << fixed << setprecision(4) << (float) uniqueWords[i].count / totalNumWords << " - " << uniqueWords[i].word << endl;
    }
}

int main(int argc, char const *argv[])
{
    string line;
    ifstream anotherFile(argv[2]);

    string ignoreWords[50];
    int timesDoubled = 0;
    int n = 100;
    int size = 0;
    wordItem *a = new wordItem[n];
    
    if(argc == 4)
    {
        getStopWords(argv[3], ignoreWords);
        
        if(anotherFile.is_open())
        {
            while(anotherFile >> line)
            {
                if(line != "")
                {
                    if(isStopWord(line, ignoreWords) == false)
                    {
                        if(size >= n)
                        {
                            wordItem *newA = new wordItem[2*n];

                            for(int i = 0; i < n; i++)
                            {
                                newA[i] = a[i];
                            }
                            delete [] a;
                            n = 2*n;
                            a = newA;
                            timesDoubled++;
                        }

                        bool found = false;
                        for(int i = 0; i < size; i++)
                        {
                            if(a[i].word == line)
                            {
                                a[i].count++;
                                found = true;
                            }
                        }

                        if(found == false)
                        {
                            wordItem newItem;

                            newItem.word = line;
                            newItem.count = 1;
                            a[size] = newItem;
                            size++;
                        }
                    }
                }
            }

            arraySort(a, size);
            int totalNumWord = getTotalNumberNonStopWords(a, size);
            
            cout << "Array doubled: " << timesDoubled << endl;
            cout << "#" << endl;
            cout << "Unique non-common words: " << size << endl;
            cout << "#" << endl;
            cout << "Total non-common words: " << totalNumWord << endl;
            cout << "#" << endl;
            cout << "Probability of next 10 words from rank " << stoi(argv[1]) << endl;
            cout << "---------------------------------------" << endl;
            printNext10(a, stoi(argv[1]), totalNumWord);
        } 
    }

    else
    {
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
        return 0;
    }      
}