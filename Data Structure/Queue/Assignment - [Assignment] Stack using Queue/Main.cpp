/*

Problem Statement
Implement a Stack using Queues.
You can use C++ STL Queue.

*/

#include <iostream>
#include <queue>

using namespace std;

class Stack
{
public:
    void push(int value)
    {
        q2.push(value);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    void pop()
    {
        if (!q1.empty())
            q1.pop();
        else
            cout << "Stack is Empty!" << endl;
    }

    int top()
    {
        if (!q1.empty())
            return q1.front();
        else
            cout << "Stack is Empty!" << endl;

        return -1;
    }

    bool empty() { return q1.empty(); }

private:
    queue<int> q1, q2;
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30
    s.pop();
    cout << "Top element: " << s.top() << endl; // 20
    s.pop();
    cout << "Top element: " << s.top() << endl; // 10
    s.pop();
    cout << "Stack is empty: " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}