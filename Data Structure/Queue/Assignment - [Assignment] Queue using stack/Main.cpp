/*

Problem Statement
Implement a Queue using Stacks.
Use C++ STL Stack.

*/

#include <iostream>
#include <stack>

using namespace std;

class Queue
{
public:
    void enqueue(int value) { s1.push(value); }

    void dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int front()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() { return s1.empty() && s2.empty(); }

private:
    stack<int> s1, s2;
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // 10
    q.dequeue();
    cout << "Front element: " << q.front() << endl; // 20
    q.dequeue();
    cout << "Front element: " << q.front() << endl; // 30
    q.dequeue();
    cout << "Queue is empty: " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}