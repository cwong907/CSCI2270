#include "linkedlist.hpp"
using namespace std;

//default constructor that makes sures head is null
LinkedList::LinkedList()
{
    head = NULL;
}
//insert node function
//if head is null, create new head
//else traverse the linked list and add the data to the end of the list

void LinkedList::insertNodeLL(int data)
{
    if(head == NULL)
    {
        head = new Node;
        head->data = data;
        head->next = NULL;
        return;
    }
  
    Node * crawler = head;

    while(crawler->next != NULL)
    {
        crawler = crawler->next;
    }

    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    crawler->next = newNode;

    return;

}

//serach for node by traversing list until it is either null or hits input matches item in list
//outputs position found as well as data

Node * LinkedList::searchLL(int data)
{
    Node * crawler = head;
    int i = 0;

    while(crawler != NULL)
    {
        if(crawler->data == data)
        {
           // cout << "found: " << crawler->data << " at index:" << i << endl;
            return crawler;   
        }
        crawler = crawler->next;
        i++;
    }
    //cout << "Not found chief";
    return NULL;
}


//traverse entire linked list and outputs each node until it reaches the end of the list

void LinkedList::displayLL()
{
    Node * crawler = head;
    while(crawler != NULL)
    {
        cout << crawler->data << "->";
        crawler = crawler->next;
    }
    cout << "END" << endl;
 }