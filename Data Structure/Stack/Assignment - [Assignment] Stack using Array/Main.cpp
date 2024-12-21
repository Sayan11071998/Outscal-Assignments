#include <iostream>
using namespace std;

// Stack Class
class Stack
{
public:
    // Constructor
    Stack(int capacity)
    {
        this->capacity = capacity;
        stack = new int[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() { delete[] stack; }

    // Print Function
    void print()
    {
        if (isEmpty())
        {
            cout << "\nStack is Empty!" << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
            cout << stack[i] << endl;
    }

    // Adding Element to the Top
    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "\nStack Overflow: Cannot push " << value << endl;
            return;
        }

        stack[++top] = value;
    }

    // Removing Element from the Top
    int pop()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow: Cannot pop from an empty stack" << endl;
            return INT_MIN;
        }

        return stack[top--];
    }

    // Checking for Empty Stack
    bool isEmpty() { return top == -1; }

    // Getting Top Value
    int topValue()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty!" << endl;
            return INT_MIN;
        }

        return stack[top];
    }

    // Getters
    void getTop()
    {
        if (isEmpty())
            cout << "\nTop: nullptr" << endl;
        else
            cout << "\nTop: " << stack[top] << endl;
    }

    void getHeight() { cout << "\nHeight: " << (top + 1) << endl; }

private:
    int* stack;
    int top;
    int capacity;
};

int main()
{
    // Initialize the stack with a capacity
    Stack stack(5);

    // Use push to add elements
    stack.push(50);
    stack.push(100);
    stack.push(150);

    // Print the current stack
    cout << "\nStack after pushing elements:" << endl;
    stack.print();

    // Get the top value
    cout << "\nTop value using topValue(): " << stack.topValue() << endl;

    // Check if the stack is empty
    cout << "\nIs stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Print the top element using getTop()
    stack.getTop();

    // Print the height of the stack
    stack.getHeight();

    // Pop an element and print the stack
    cout << "\nPopped value: " << stack.pop() << endl;
    cout << "\nStack after popping an element:" << endl;
    stack.print();

    // Pop all elements to empty the stack
    cout << "\nPopping all elements:" << endl;
    while (!stack.isEmpty()) { cout << "\nPopped: " << stack.pop() << endl; }

    // Check the stack after emptying
    cout << "\nIs stack empty now? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Try to pop from an empty stack
    cout << "\nAttempt to pop from an empty stack: " << stack.pop() << endl;

    // Check the top value of an empty stack
    cout << "\nTop value of an empty stack: " << stack.topValue() << endl;

    // Check the height of an empty stack
    stack.getHeight();

	return 0;
}