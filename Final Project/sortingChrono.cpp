#include <iostream>
#include <queue>
#include <algorithm>
#include <chrono>

// Turn on or off to show that array is being sorted.
// Should turn off for large array
#define PRINT_ARRAY true

// Run a timing test on different sorting algorithms
#define BUBBLE_TEST false
#define HEAP_TEST false
#define PQ_TEST false
#define STL_SORT_TEST false

// Size of array to be sorted
const int ARRAY_SIZE = 20;


// A class for Min Heap
class MinHeap
{
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void push(int k);
        int pop();
        int peek() { return heap[1]; }
        void printHeap();
    private:
        int *heap; // pointer to array of elements in heap
        int capacity; // maximum possible size of min heap
        int currentSize; // Current number of elements in min heap      
        void MinHeapify(int index);
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i+1); }
        int right(int i) { return (2*i + 2); }
        void swap(int &x, int &y);
};
 
MinHeap::MinHeap(int cap)
{
    currentSize = 0;
    capacity = cap; 
    heap = new int[capacity];
}

MinHeap::~MinHeap()
{
    delete [] heap;
}
 
void MinHeap::push(int k){
    if (currentSize == capacity){
        // could use a vector or add array doubling here
        std::cout << "At capacity, cannot insert key." << std::endl;
    }
 
    else {
        int i = currentSize;
        heap[i] = k; 
     
        // Fix the min heap property if it is violated
        while (i != 0 && heap[parent(i)] > heap[i]){
           swap(heap[i], heap[parent(i)]);
           i = parent(i);
        }
        currentSize++;
    }
}
 
// for now, just return -1 if there's nothing to pop
int MinHeap::pop(){

    if (currentSize <= 0)
        return -1;
    if (currentSize == 1)
    {
        currentSize--;
        return heap[0];
    }
 
    int poppedVal = heap[0];
    heap[0] = heap[currentSize-1];
    currentSize--;
    MinHeapify(0);
 
    return poppedVal;
}
 
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i){

    int leftChild = left(i);
    int rightChild = right(i);
    int smallest = i;
    if (leftChild < currentSize && heap[leftChild] < heap[i])
        smallest = leftChild;
    if (rightChild < currentSize && heap[rightChild] < heap[smallest])
        smallest = rightChild;

    if (smallest != i){
        swap(heap[i], heap[smallest]);
        MinHeapify(smallest);
    }
}
 
void MinHeap::swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void MinHeap::printHeap() {
    std::cout << "The heap array is currently {";
    for (int i = 0; i < currentSize; i++) {
        std::cout << heap[i];
        if (i < currentSize-1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}

void printArray(int a[], int size){
    for( int i = 0; i < size; i ++ )
        std::cout << a[i] << " ";
}

int main(){

    ////////////////////////////////////////////////////////////////////////
    // CREAT A TEST ARRAY OF RANDOM INTEGERS
    int testArr[ARRAY_SIZE], arr[ARRAY_SIZE];
    for( int i = 0; i < ARRAY_SIZE; i++)
        testArr[i] = rand()%1000;

#if PRINT_ARRAY
    std::cout << "the unsorted test array is: " << std::endl;
    printArray(testArr,ARRAY_SIZE);
    std::cout << "\n\n";
#endif

    ////////////////////////////////////////////////////////////////////////
    // TEST BUBBLE SORT
 #if BUBBLE_TEST   
    // Copy over test values
    for( int i = 0; i < ARRAY_SIZE; i ++ )
        arr[i] = testArr[i];
    
    using namespace std::chrono;
    high_resolution_clock::time_point start = high_resolution_clock::now();

    for ( int i = ARRAY_SIZE-1; i > 0; i-- ){
        for ( int j = 0; j < i; j++ )
            if ( arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
    }
    
    high_resolution_clock::time_point end = high_resolution_clock::now();
    
#if PRINT_ARRAY
    std::cout << "\nthe bubble sorted array is: " << std::endl;
    printArray(arr,ARRAY_SIZE);
#endif

    duration<double> execTime = duration_cast<microseconds>(end - start);

    std::cout << "\nbubble execution time: " << execTime.count() << " seconds." <<  std::endl;
#endif
    ////////////////////////////////////////////////////////////////////////
    // TEST HEAP SORT
#if HEAP_TEST
    // Re-populate test array with random ints
    for( int i = 0; i < ARRAY_SIZE; i ++ )
        arr[i] = testArr[i];

    MinHeap heap2(ARRAY_SIZE);

    start = high_resolution_clock::now();

    // Write array elements into heap
    for( int i = 0; i < ARRAY_SIZE; i ++ )
        heap2.push( arr[i]);


    // Pop the elements back off into the array
    for( int i = 0; i < ARRAY_SIZE; i ++ )
        arr[i] = heap2.pop();

    end = high_resolution_clock::now();

#if PRINT_ARRAY
    std::cout << "\nthe heap sorted array is: " << std::endl;
    printArray(arr,ARRAY_SIZE);
#endif

    std::cout << std::endl;

    
    execTime = duration_cast<microseconds>(end - start);

    std::cout << "heap execution time: " << execTime.count() << " seconds" << std::endl;
#endif
    ////////////////////////////////////////////////////////////////////////
    // TEST Priority Queue from STL for sorting

#if PQ_TEST
    // Re-populate test array with random ints
    for( int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = testArr[i];

    start = high_resolution_clock::now();
    std::priority_queue<int> pq;

    for( int i = 0; i < ARRAY_SIZE; i ++ )
        pq.push( arr[i]);

    for(int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = pq.top();
        pq.pop();
    }

    end = high_resolution_clock::now();
    
    
    execTime = duration_cast<microseconds>(end - start);
    std::cout << "\nSTL PQ time: " << execTime.count() << " seconds" << std::endl;
#endif
    ////////////////////////////////////////////////////////////////////////
    // TEST sort() from STL for sorting
#if STL_SORT_TEST
    // Re-populate test array with random ints
    for( int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = testArr[i];

    start = high_resolution_clock::now();
    std::sort(arr,arr+ARRAY_SIZE);

    end = high_resolution_clock::now();
    
    
    execTime = duration_cast<microseconds>(end - start);
    std::cout << "\nSTL sort() time:" << execTime.count() << " seconds\n" << std::endl;
#endif
    return 0;
}