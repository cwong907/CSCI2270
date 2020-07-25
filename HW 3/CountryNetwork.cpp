/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = NULL;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    Country *temp = new Country;
    temp->name = countryName;

    if(head == NULL)
    {
        temp->next = head;
        head = temp;
        cout << "adding: " << countryName << " (HEAD)" << endl;
    }

    else if(previous == NULL)
    {
        temp->next = head;
        head = temp;

        cout << "adding: " << countryName << " (HEAD)" << endl;
    }

    else
    {
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        temp->next = previous->next;
        previous->next = temp;
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    insertCountry(head, "United States");
    insertCountry(searchNetwork("United States"), "Canada");
    insertCountry(searchNetwork("Canada"), "Brazil");
    insertCountry(searchNetwork("Brazil"), "India");
    insertCountry(searchNetwork("India"), "China");
    insertCountry(searchNetwork("China"), "Australia");
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    Country * aPointer = head;
    Country * previous = aPointer;

    if(head == NULL)
    {
        return NULL;
    }

    else
    {
        while((aPointer != NULL))
        {
            previous = aPointer;

            if(aPointer -> name == countryName)
            {
                return aPointer;
            }

            aPointer = aPointer -> next;
        }

        return NULL;
    }
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    Country *check;
    Country * bPointer = head;

    check = searchNetwork(receiver);

    if(head == NULL)
    {
        cout << "Empty list" << endl;
    }

    else if(check == NULL)
    {
        cout << "Country not found" << endl;
    }
    
    else
    {
        while((bPointer != NULL))
        {
            bPointer->message = message;
            bPointer->numberMessages++;
            cout << bPointer->name << " [# messages received: " << bPointer->numberMessages << "] received: " << bPointer->message << endl;
            
            if(bPointer->name == receiver)
            {
                break;
            }
            bPointer = bPointer->next;
        }
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    Country *cPointer = head;

    cout << "== CURRENT PATH ==" << endl;

    if(head == NULL)
    {
        cout << "nothing in path" << endl;
        cout << "===" << endl;
    }    

    else
    {
        while(cPointer != NULL)
        {
            cout << cPointer->name << " -> ";
            cPointer = cPointer->next;
        }
        cout << "NULL" << endl;
        cout << "===" << endl;
    }
    
}