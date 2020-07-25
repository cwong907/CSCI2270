/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
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
/* finished. do not touch. */
    head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
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
    
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        cout << "adding: " << countryName << " (HEAD)" << endl;
        head = new Country;
        head->name = countryName;
        head->numberMessages = 0;
        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL)
    {
        //case where it's a new head Country
        cout << "adding: " << countryName << " (HEAD)" << endl;
        Country *c = new Country;
        c->name = countryName;
        c->numberMessages = 0;
        c->next = head;
        head = c;
    }
    else
    {
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        Country *newCountry = new Country;
        newCountry->name = countryName;
        newCountry->numberMessages = 0;
        newCountry->next = previous->next;
        previous->next = newCountry;
    }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) 
{
    bool check = false;

    Country *temp = new Country;
    temp = head;
    Country *previous = NULL;

    if(head == NULL)
    {
        cout << "List is empty." << endl;
    }

    else
    {
        while(temp != NULL)
        {
            if(temp->name == countryName && temp == head)
            {
                head = temp->next;
                delete temp;
                check = true;
            }

            else if(temp->name == countryName)
            {
                previous->next = temp->next;
                
                delete temp;
                check = true;
            }

            if(check == true)
            {
                break;
            }

            else
            {
                previous = temp;
                temp = temp->next;
            }
        }

        if(check == false)
        {
            cout << "Country does not exist." << endl;
        }
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    int num_countries = 6;
    string countries[] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    deleteEntireNetwork();
    Country* prev = NULL;
    for(int i = 0; i < num_countries; i++)
    {
        insertCountry(prev, countries[i]);
        prev = searchNetwork(countries[i]);
    }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
// Search until the head is NULL, or we find the country
    Country* ptr = head;
    while (ptr != NULL && ptr->name != countryName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
* Purpose: Creates a loop from last node to the country specified.
* @param countryName name of the country to loop back
* returns pointer to last node before loop creation (to break the loop)
*/
Country* CountryNetwork::createLoop(string countryName)
{
    Country *place = head;
    Country *holder;
    Country *last;

    holder = searchNetwork(countryName);

    while(place->next != NULL)
    {
        place = place->next;
    }
    place->next = holder;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    Country *place = head;

    while(head != NULL)
    {
        place = head;
        head = head->next;
        cout << "deleting: " << place->name << endl;

        delete place;
        //place = place->next; 
    }

    head = NULL;
    cout << "Deleted network" << endl;
}

/*
*Purpose: to detect loop in the linkedlist
* @param
* returns true if loop is detected. Otherwise return false.
*/
bool CountryNetwork::detectLoop() 
{
    bool boolin = false;
    Country *temp = head;
    Country *pmet = head;

    while(pmet != NULL && pmet->next != NULL)
    {
        temp = temp->next;          // 1 hop
        pmet = pmet->next->next;     // 2 hops 

        if(temp == pmet)  // fast caught up to slow, so there is a loop
            return true;
    }

    return false;
}

/*
* Purpose: Take the chunk of nodes from start index to end index
*          Move that chunk at the end of the List
*@param: start index
*@param: end index
* return none
*/
void CountryNetwork:: readjustNetwork(int start_index, int end_index)
{
    int counter = 0;
    Country *temp = head;

    while(temp != NULL)
    {
        temp = temp->next;
        counter++;
    }

    if(head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }

    else if(start_index > end_index)
    {
        cout << "Invalid indices" << endl;
    }

    else if(end_index >= counter - 1  || end_index <= 0)
    {
        cout << "Invalid end index" << endl;
    }

    else if(start_index >= counter - 1 || start_index < 0)
    {
        cout << "Invalid start index" << endl; 
    }

    else if(start_index == 0)
    {
        Country *find = head;
        Country *previous = NULL;
        Country *store = head;
        int x = 0;

        while(x != end_index)
        {
            previous = find;
            find = find->next;
            x++;
        }

        previous = previous->next;
        find = find->next;

        previous->next = NULL;
        store = find;

        while(find->next != NULL)
        {
            find = find->next;
        }
        
        find->next = head;

        head = store;
    }

    else
    {
        Country *go = head;
        Country *go2 = head;
        Country *holder = NULL;
        Country *start = NULL;
        int index = 0;
        //int index2 = 0;

        while(go != NULL)
        {
            if(index == start_index)
            {
                start = go;
                holder = go2;
            }

            if(index == end_index)
            {
                go2 = go;
                go = go-> next;

                holder->next = go;
                go2->next = NULL;
                break;
            }

            index++;
            go2 = go;
            go = go->next;
        }

        while(go->next != NULL)
        {
            go = go->next;
        }

        go->next = start;
    }
    
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    Country* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr->next != NULL)
        {
            cout << ptr->name << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
