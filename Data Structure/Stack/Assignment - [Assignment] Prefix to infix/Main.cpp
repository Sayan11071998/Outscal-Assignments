#include <iostream>
#include <string>
#include <climits>

using namespace std;

// Node Class
class Node
{
public:
    string value;
    Node* next;

    Node(string value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

// Stack Class
class Stack
{
public:
    // Constructor
    Stack()
    {
        top = nullptr;
        height = 0;
    }

    // Destructor
    ~Stack()
    {
        Node* temp = top;

        while (top)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    // Print Function
    void printStack()
    {
        Node* temp = top;

        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    // Adding Element from TOP
    void push(string value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    // Removing Element from TOP
    string pop()
    {
        if (height == 0) return "";

        Node* temp = top;
        string poppedValue = top->value;
        top = top->next;
        delete temp;
        height--;

        return poppedValue;
    }

    // Checking for Empty Stack
    bool isEmpty()
    {
        return height == 0;
    }

    // Getting TOP value
    string topValue()
    {
        if (top) return top->value;

        return "";
    }

    // Getters
    void getTop()
    {
        if (top == nullptr)
            cout << "Top: nullptr" << endl;
        else
            cout << "Top: " << top->value << endl;
    }

    void getHeight() { cout << "Height: " << height << endl; }

private:
    Node* top;
    int height;
};

// Checking for Operands
bool isOperand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Prefix to Infix Conversion
string prefixToInfix(string prefix)
{
    Stack stack;
    string infix = "";

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char element = prefix[i];

        if (isOperand(element))
        {
            stack.push(string(1, element));
        }
        else
        {
            string operand1 = stack.pop();
            string operand2 = stack.pop();

            string expr = "( " + operand1 + " " + element + " " + operand2 + " )";
            stack.push(expr);
        }
    }

    return stack.pop();
}

int main()
{
    string prefix1 = "* +AB -CD";
    string prefix2 = "* -A /BC - /AKL";

    cout << "Prefix Expression: " << prefix1 << endl;
    cout << "Infix Expression: " << prefixToInfix(prefix1) << endl;

    cout << "\nPrefix Expression: " << prefix2 << endl;
    cout << "Infix Expression: " << prefixToInfix(prefix2) << endl;

    return 0;
}