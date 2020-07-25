/****************************************************************/
/*                    ProducerConsumer Class                    */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/
#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 20;

class ProducerConsumer
{
private:
  int queueFront; //the index in queue[] that will be dequeued next
  int queueEnd; //the index in queue[] that was most recently enqueued
  int counter = 0; //changed
  string queue[SIZE];

public:
  ProducerConsumer();
  bool isEmpty();
  bool isFull();
  void enqueue(string item);
  void dequeue();
  string peek();
  int queueSize();   //changed
  int getQueueFront() { return queueFront; }
  int getQueueEnd() { return queueEnd; }
  string* getQueue() { return queue; }

};
