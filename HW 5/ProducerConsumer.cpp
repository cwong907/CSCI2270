#include "ProducerConsumer.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


ProducerConsumer::ProducerConsumer()
{
    queueFront = 0;
    queueEnd = 0;
}

bool ProducerConsumer::isEmpty()
{
    if(counter == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool ProducerConsumer::isFull()
{
    if(counter == SIZE)
    {
        return true;
    }

    else
    {
        return false;
    }
    
}

void ProducerConsumer::enqueue(string item)
{
    if(!isFull())
    {
        queue[queueEnd] = item;
        queueEnd  = (queueEnd + 1) % SIZE;
        cout << queueEnd << endl;
        counter++;
    }

    else
    {
        cout << "Queue full, cannot add new item" << endl;
    }
}

void ProducerConsumer::dequeue()
{
    if(!isEmpty())
    {
        queue[queueFront] = "";
        queueFront = (queueFront + 1) % SIZE;
        counter--;
    }

    else
    {
        cout << "Queue empty, cannot dequeue an item" << endl;
    }

}

string ProducerConsumer::peek()
{
    if(!isEmpty())
    {
        return queue[queueFront];
    }

    else
    {
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }    
}

int ProducerConsumer::queueSize()
{
    return counter;
}