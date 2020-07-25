/*
 1-29-20
Automatic variables live in stack and they are deallocated automatically when the function pops off the stack(when function returns to main or
when main ends)

Dynamic varibles get allocated to heap (freestore) do not get automatically deallocated
Allocate simple int on heap:
int *p;
p = new int; //nameless variable
Or:
int *p = new int;

Access variable on heap:
Dereference pointer
*p = -1;

Once we're done with it:
Deallocate with:
delete p; //deallocates memory that p was pointing to in the heap does not delete pointer

Dynamically Allocated Array:
int *ptr
ptr = new int[5]; //allocate but must deallocate when finished
delete []ptr;

Array Doubling:
int n = 3;
int *a;

a = new int[n];

int *temp = new int[2*n];

for(int i = 0; i < n; i++)
{
    temp[i] = a[i];
}

delete [] a;

a = temp;
n = 2 * n;

int main()
{
    int n = 3;
    int *a;

    a = new int[n];
}
*/

/*
1-31-20

void arrDouble(int *&a, int n)
{
    int *temp = new int[2*n];

    for(int i = 0; i < n; i++)
    {
        temp[i] = a[i];
    }

    delete [] a;

    a = temp;
    n = 2 * n;


}

int main()
{
    int N = 3;
    int *a;
    a = new int[N];
    arrDouble(a, N);
}


CLasses:


*/

/*
2-3-20

int *ptr;

data_type * pointer name;
can do this with structs as well

struct Student
{
    string name;
    int age;
};

int main()
{
    Student s0;

    s0.name = "Pat";
    s0.age = 44;

    Student * sptr;
    sptr = &s0;

    (*sptr).name = "Patty";
    (*sptr).age = 94;
    Equivalent Syntax
    sptr -> name = "Patty";
    sptr -> age = 94;
}

Dynamically Allocate this crap

Student *s0 = new Student;

s0 -> name = "Maia";
s0->age = 33;

delete s0;

struct Student
{
    string name;
    int age;
    Student *next;
};

int main()
{
    Student * s0, *s1;
    s0 = new Student;
    s1 = new Student;

    s0->name = "Jenny";
    s0->age = 19;

    s1->name = "Archana";
    s1->age = 22;

    s0->next = s1;
    s1->next nullptr;

    s1 = new Student;
    s0 -> next->next = s1;
}
*/

/*
2-5-20

Linked List:
alt method to array for storing list of data in the memory
each element occupies its own node
nodes aren't sequential in memory
add new node anywhere in list without having to move other nodes
should have a seperate pointer variable that is named head
next ptr of last node should always be set to NULL
single or doubly linked list

single linked list:
struct NodeSLL
{
    int key;
    NodeSLL * next;
};

double linked list:
struct NodeSLL
{
    int key;
    NodeSLL * next;
    NodeSLL * previous;
};

Abstract Data Type (ADT):

collection of member data and the allowed operations of that data
abstract because the user only has info about the inputs the outputs and the explanation of the actions

Single Linked List ADT:
private:
    head - ptr to the first element in the linked list

public:
    initalize() - set header to null (constructor in C++)
    nodePtr = search(value) - find a value and return ptr to its node
    insertNode(previousPtr, newName) - given a ptr to a node, insert a new node right after it
    displayList() - starts at head and traverses list and displays all values
    deleteNode() - given a ptr to a node, remove from linked list
    deleteList() - clears whole list
*/

/*
2-7-20
*/

/*
2-10-20

Destructor:

class SLL
{
    private:
    ...

    public:
        SLL(); //constructor
        ~SLL(); //destructor 
}

SLL::~SLL()
{
    Node *crawler;

    while(head != NULL)
    {
        crawler = head->next;
        delete head;
        head = crawler
    }
}

int main()
{
    SLL s0;
    ...
    s0.~SLL();
}

void SLL::deleteNode(Node * deleteNode)
{
    if(deleteNode !- NULL)
    {
        if(deleteNode == head)
        {
            head = head->next;
            delete deleteNode;
        }

        else
        {
            Node *temp = head;
            while(temp->next != deleteNode)
            {
                temp = temp->next;
            }
            temp->next =
        }
    }

    else
    {
        cout << "..." << endl;
    }
}

2-12-20
Complexity:

Stack:

call stack; during program execution keeping track of subroutines(automatic variables)

Last In First Out data structure(LIFO)
A "limited acess" DS
can only add to top
can only remove to top
depends on implementation can have hard limit on size
Usage examples:
call stack; during program execution keeping track of active subroutines

Stack ADT

private:
top - keep track of top element
maxSize - limit on total size of stack
count - current number of elements in stack

public:
initialize - (constructor)
destroy - (destructor)
isFull() - optional depending on implementation
isEmpty()
push(item) - add a new item to top
pop() - discard from top 
peek() - shows top item
display() - optional

singly linked list
array 

Stack SLL

Stack::Stack()
{
    top = NULL;
}

bool Stack::isEmpty()
{
    if(top ==NULL)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void Stack::push(string newItem)
{
    Node *temp = new Node;
    temp->item = newItem;

    if(isEmpty())
    {
        top = temp;
        top->next = NULL;
    }

    else
    {
        temp->next = top;
        top = temp;
    }
}

void Stack::pop()
{
    Node *temp;

    if(!isEmpty())
    {
        temp = top;
        top = top->next;
        delete temp;
    }

    else
    {
        cout << "Stack underflow" << endl;
    }
}

Stack array implementation

private:
int top - index of next available element
int count - current number of elements
strings[MAX_SIZE] - stack array

public:

bool isFull()
{
    return top == MAX_SIZE;
}

bool isEmpty()
{
    return top = 0;
}

string peek()
{
    if(!isEmpty())
    {
        return s[top - 1];
    }
}

void push(string newItem)
{
    if(!isFull)
    {
        s[top] = newItem;
    }

    else
    {
        cout << "stack overflow" << endl;
    }
}

void pop()
{

}


Array Based:
Pros:
memory efficient
fast
Cons:
fixed size
if using dynamic memory not linear speed

LL Based:
Pros:
no size cap

Cons:
slower(access heap)

2-17-20
Queue:
enqueue at tail
dequeue at head
First In First Out

private:
head - the first item in the q
tail - last item in the q
queueSize - number of elements in the q currently

public:
initialize()
isEmpty()
isFull()
enque(item) - add item at end of queue
dequeu() - remove item from head

Implementation:
head is always 0 
tail holds index of next available element

2-19-20
Exam Review:

Structs:
definition syntax
member data
no member functions (2270 convention)
all variable are public by default
pointer to a struct
    ptr->memberA
array of structs
arroy as a member of struct

Classes
all the same things as a struct + all the new things that come with classes
private vs public variables
member functions
    constructors and destructors(function overloading)

Pointers
variable that stores the memory location (address)
*& - dereference and address of operator
"value" space vs address space

Variables on stack vs heap
syntax:
    stack: automatic variables
        pointers live on stack
    heap: dynamic variables
        new and delete keywords
        nameless variables
        memory leaks
        manually allocating and deallocating

Parameter passing
pass by value
pass by reference
pass by array
pass by pointer

foo(int &x)
call
jkf()
{
    int y;
    foo(y);
}

Array doubling:
remember concept not just recipe
allocating arrays on the heap
effectively changing the length of an array
passing an array to function
properly de-allocating

List:
array 
    big O for core function
singly linked list
    nodes - how and where to allocate
    last node's pointer is NULL
    traversal, inserts, deletes
doubly linked list
    be able to make a small leap

stacks and queues concepts
    LIFO vs FIFO
    big-O
    implementations
        array vs LL
        circular array 4 queue

2-24-20

a tree is a non-linear DS
Hierarchial data structure 
each element is called a node
top node is the root node
there is only one root in a tree
connected by edges (pointers)
parent-child relationship
cannot have cycles
cannot have disconnected parts

binary tree is a special case of a general tree:
in a binary tree each node has exactly 2 children 
a child or both children can be null
one or both children can be null so we typically say that a node has 0, 1, 2 children
parent, left, and right child
root is the top most node
root's parent is null
self-similarity
tree is composed of smaller sub trees
we can apply the same algorithm to examine smaller and smaller sub-trees

Binary Search Tree:
4 any node in tree:
the nodes in the left subtree have smaller key values than the parent key value
the nodes in the right subtree have key values greater than or equal to the node value

with a BST we check for equality first, then we decide whether to visit the left child or the right child

if search->key == crawler->key
    return crawler

while(key not found)
{
    if search->key < crawler->key
        traverse left
    else
        traverse rights
}

log2(N+1)
big-O log2(N) = 3.9
N = 1000000
log2(1000000) = 19.9

struct Node
{
    <type> key;
    Node* leftChild;
    Node *rightChild;
}; some include parent pointer in struct definition

bool search(int sKey)
{
    Node* crawler = root;
    bool found = false;
    while(!found)
    {
        if(skey == crawler->key)
        {
            found = true;
        }

        else if(sKey < crawler->key)
        {
            crawler = crawler->leftChild;
        }

        else
        {
            crawler = crawler-> rightChild
        }
    }
    return found;
}

Recursive:
void printRecursive(int n)
{
    if(n == 0)
    {
        return;
    }

    cout << "n = " << n << endl;
    printRecursive(n-1);
}

int main()
{
    int x = 3;
    printRecursive(x);
    return 0;
}
*/

#include <iostream>
using namespace std;

void printRecursive(int n)
{
    if(n == 0)
    {
        return;
    }

    cout << "n = " << n << endl;
    printRecursive(n-1);
}

int main()
{
    int x = 30000;
    printRecursive(x);
    return 0;
}

/*
int fact(int n)
{
    if(n>1)
    {
        return n * fact(n-1);
    }
    
    else
    {
        return 1;
    }
}

3-2-20

3-4-20

3-6-20

3-9-20

Graphs:
a collection of vertices connected by edges
each vertex contains a "key" and a list of edges

list of edges is stored in an adjacency list or matrix
unlike BST there are no set relationships b/w vertices
    cannot know that v0->key > v1->key

3-11-20

all relationships have to be explicitly set

standard template library - very widely used set of template classes, includes most of the common data structures (list, queue, stack, vector, etc.)

Template class - a class that works generically on any type (primitive or user defined)

vector <int> vect;

struct myStruct
{
    int numbers;
    string words;
};
...
vector <myStruct> vectorOfStructs;

3-16-20

Graphs:
edges are essentially pointers
Insert a vertex = no duplicates = append to list
Add an edge = 
undirected (two way roads, connection to one another)

3-20-20

*/