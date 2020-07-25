#include <iostream>
#include <string>


struct Node{
    int data;
    Node * next;
} ;

//Implement a class for singly linked list. 
  //insert,
  //search
  //display. 

class LinkedList {
    private:
        Node * head;
    public:
        LinkedList();
        void insertNodeLL(int data);
        Node * searchLL(int data);
        void displayLL();
};