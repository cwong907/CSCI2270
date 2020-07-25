/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//void displayMenu();  // declaration for main's helper-function

/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;

    string in = "3";
    string country;
    string message;
    string newCountry;
    string previousCountry;
    Country *check;

    while(stoi(in) !=5)
    {
        displayMenu();
        //cin >> input;
        getline(cin, in);   

        switch(stoi(in))
        {
        case 1:
            CountryNet.loadDefaultSetup();
            CountryNet.printPath();
            break;
        case 2:
            CountryNet.printPath();
            break;
        case 3:
            cout << "Enter name of the country to receive the message:" << endl;
            getline(cin, country);
            
            cout << "Enter the message to send:" << endl;
            cout << endl;
            getline(cin, message);
            CountryNet.transmitMsg(country, message);
            break;
        case 4:
            cout << "Enter a new country name:" << endl;
            getline(cin, newCountry);

            cout << "Enter the previous country name (or First):" << endl;
            getline(cin, previousCountry);
            
            while(CountryNet.searchNetwork(previousCountry) == NULL && previousCountry != "First")
            {
                cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                getline(cin, previousCountry);
            }
            if(previousCountry == "First")
            {
                CountryNet.insertCountry(NULL, newCountry);
                CountryNet.printPath();
            }

            else
            {
                check = CountryNet.searchNetwork(previousCountry);
                CountryNet.insertCountry(check, newCountry);
                CountryNet.printPath();
            }
                       
            break;
        case 5:
            cout << "Quitting..." << endl;
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid Input." << endl;
            break;
        }
    }
    return 0;
}