/*

Problem Statement
Insert 5 integers into a queue and print them.
You can use C++ STL Queue.
Insert the integers: 10, 20, 30, 40, 50 
Output : 10, 20, 30, 40, 50

*/

#include <iostream>
using namespace std;

// Queue Class using Array
class Queue
{
public:
    // Constructor
    Queue(int queueSize)
    {
        this->queueSize = queueSize;
        queue = new int[queueSize];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    // Destructor
    ~Queue() { delete[] queue; }

    // Print Queue
    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < currentSize; i++)
            cout << queue[(front + i) % queueSize] << " ";
        cout << endl;
    }

    // Push (Enqueue)
    void enqueue(int value)
    {
        if (currentSize == queueSize)
        {
            cout << "Queue is Full. Can not push!" << endl;
            return;
        }

        rear = (rear + 1) % queueSize;
        queue[rear] = value;
        currentSize++;
    }

    // Pop (Dequeue)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        front = (front + 1) % queueSize;
        currentSize--;
    }

    // Front
    int frontValue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1; // Return a sentinel value
        }

        return queue[front];
    }

    // Size
    int size() { return currentSize; }

    // Empty
    bool isEmpty() { return currentSize == 0; }

private:
    int* queue;
    int front;
    int rear;
    int currentSize;
    int queueSize;
};

int main()
{
    // Initialize the queue with a size of 5
    Queue myQueue(5);

    // Enqueue integers
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Print the queue elements
    myQueue.printQueue();

    return 0;
}