#include "RPNCalculator.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

RPNCalculator::RPNCalculator()
{
    stackHead = NULL;
}

RPNCalculator::~RPNCalculator()
{
    Operand * temp = stackHead;

    while(stackHead != NULL)
    {
        temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }

    stackHead == NULL;
}

bool RPNCalculator::isEmpty()
{
    if(stackHead == NULL)
    {
        return true;
    }

    else
    {
        return false;
    }
    
}

void RPNCalculator::push(float number)
{
    Operand* hold = new Operand;
    hold->number = number;

    hold->next = stackHead;
    stackHead = hold;
}

void RPNCalculator::pop()
{
    if(!isEmpty())
    {
        Operand* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }

    else
    {
        cout << "Stack empty, cannot pop an item." << endl;
    }
}

Operand* RPNCalculator::peek()
{
    if(!isEmpty())
    {
        return stackHead;
    }

    else
    {
        cout << "Stack empty, cannot peek." << endl;
        return NULL;
    }
}

bool RPNCalculator::compute(string symbol)
{
    float t2;

    if(symbol != "*" && symbol != "+")
    {
        cout << "err: invalid operation" << endl;
        return false;
    }

    else if(isEmpty() ==  true)
    {
        cout << "err: not enough operands" << endl;
        return false;
    }

    else if(stackHead != NULL && stackHead->next != NULL)
    {
        float n1, n2;

        n1 = stackHead->number;
        n2 = stackHead->next->number;

        pop();
        if(!isEmpty())
        {
            pop();

            if(symbol == "*")
            {
                t2 = n1 * n2;
                push(t2);
                return true;
            }

            else if(symbol == "+")
            {
                t2 = n1 + n2;
                push(t2);
                return true;
            }
        }

        else
        {
            cout << "err: not enough operands" << endl;
            return false;            
        }
            
    }

    else
    {
        cout << "err: not enough operands" << endl;
        return false;
    }    
}