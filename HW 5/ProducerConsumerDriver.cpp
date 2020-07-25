/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	string n = "0", number = "0", item = "0", numC = "0";
	ProducerConsumer p1;

	while(stoi(n) != 3)
	{
		menu();
		getline(cin, n);

		int in = stoi(n);
		
		switch(in)
		{
			case 1:
				cout << "Enter the number of items to be produced:" << endl;
				getline(cin, number);
				for(int i = 0; i < stoi(number); i++)
				{
					cout << "Item" << i + 1 << ":" << endl;
					getline(cin, item);
					p1.enqueue(item);
				}
				break;
			
			case 2:
				cout << "Enter the number of items to be consumed:" << endl;
				getline(cin, numC);
				for(int j = 0; j < stoi(numC); j++)
				{
					if(p1.isEmpty() == true)
					{
						cout << "No more items to consume from queue" << endl;
						break;
					}

					else
					{
						cout << "Consumed: " << p1.peek() << endl;
						p1.dequeue();	
					}
				}
				break;

			case 3:
				cout << "Number of items in the queue:" << p1.peek() << endl;
				break;

			default:
				cout << "Invalid Input." << endl;
				break;

		}

	}
}
