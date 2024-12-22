#include <iostream>
using namespace std;

// TwoStack Class
class TwoStack
{
public:
    // Constructor
    TwoStack(int capacity)
    {
        this->capacity = capacity;
        stack = new int[capacity];
        stack_1_top = -1;
        stack_2_top = capacity;
    }

    // Destructor
    ~TwoStack() { delete[] stack; }

    // Print Method for Stack 1
    void print_stack_1()
    {
        if (stack_1_top >= 0)
        {
            cout << "Stack 1: ";
            for (int i = 0; i <= stack_1_top; ++i)
                cout << stack[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "Stack 1 is empty!" << endl;
        }
    }

    // Print Method for Stack 2
    void print_stack_2()
    {
        if (stack_2_top < capacity)
        {
            cout << "Stack 2: ";
            for (int i = stack_2_top; i < capacity; ++i)
                cout << stack[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "Stack 2 is empty!" << endl;
        }
    }

    // Push ethod for Stack 1
    void push_stack_1(int value)
    {
        if (stack_1_top + 1 < stack_2_top)
            stack[++stack_1_top] = value;
        else
            cout << "\nStack Overflow for Stack 1: Cannot push " << value << endl;
    }

    // Push ethod for Stack 2
    void push_stack_2(int value)
    {
        if (stack_1_top + 1 < stack_2_top)
            stack[--stack_2_top] = value;
        else
            cout << "\nStack Overflow for Stack 2: Cannot push " << value << endl;
    }

    // Pop ethod for Stack 1
    int pop_stack_1()
    {
        if (stack_1_top >= 0)
        {
            return stack[stack_1_top--];
        }
        else
        {
            cout << "\nStack Underflow for Stack 1: Cannot pop" << endl;
            return INT_MIN;
        }
    }

    // Pop ethod for Stack 1
    int pop_stack_2()
    {
        if (stack_2_top < capacity)
        {
            return stack[stack_2_top++];
        }
        else
        {
            cout << "\nStack Underflow for Stack 2: Cannot pop" << endl;
            return INT_MIN;
        }
    }

    // Top Getter for Stack 1
    int get_top_stack_1()
    {
        if (stack_1_top >= 0)
        {
            return stack[stack_1_top];
        }
        else
        {
            cout << "\nStack 1 is empty!" << endl;
            return INT_MIN;
        }
    }

    // Top Getter for Stack 2
    int get_top_stack_2()
    {
        if (stack_2_top < capacity)
        {
            return stack[stack_2_top];
        }
        else
        {
            cout << "\nStack 2 is empty!" << endl;
            return INT_MIN;
        }
    }

private:
    int* stack;
    int stack_1_top, stack_2_top;
    int capacity;
};

int main()
{
    // Create an instance of TwoStack with a capacity of 10
    TwoStack ts(10);

    // Push elements to Stack 1
    cout << "Pushing elements to Stack 1:" << endl;
    ts.push_stack_1(10);
    ts.push_stack_1(20);
    ts.push_stack_1(30);

    // Push elements to Stack 2
    cout << "\nPushing elements to Stack 2:" << endl;
    ts.push_stack_2(100);
    ts.push_stack_2(200);
    ts.push_stack_2(300);

    // Print both stacks
    cout << "\nPrinting both stacks:" << endl;
    ts.print_stack_1();
    ts.print_stack_2();

    // Display the top elements of both stacks
    cout << "\nTop element of Stack 1: " << ts.get_top_stack_1() << endl;
    cout << "Top element of Stack 2: " << ts.get_top_stack_2() << endl;

    // Pop elements from Stack 1
    cout << "\nPopping elements from Stack 1:" << endl;
    cout << "Popped: " << ts.pop_stack_1() << endl;
    cout << "Popped: " << ts.pop_stack_1() << endl;

    // Pop elements from Stack 2
    cout << "\nPopping elements from Stack 2:" << endl;
    cout << "Popped: " << ts.pop_stack_2() << endl;
    cout << "Popped: " << ts.pop_stack_2() << endl;

    // Print both stacks after popping
    cout << "\nPrinting both stacks after popping:" << endl;
    ts.print_stack_1();
    ts.print_stack_2();

    // Test Stack Overflow
    cout << "\nTesting Stack Overflow:" << endl;
    ts.push_stack_1(40);
    ts.push_stack_1(50);
    ts.push_stack_1(60);
    ts.push_stack_1(70);
    ts.push_stack_1(80);
    ts.push_stack_1(90); // This will cause overflow

    // Test Stack Underflow
    cout << "\nTesting Stack Underflow:" << endl;
    cout << "Popping from empty Stack 1: " << ts.pop_stack_1() << endl;
    cout << "Popping from empty Stack 2: " << ts.pop_stack_2() << endl;

	return 0;
}