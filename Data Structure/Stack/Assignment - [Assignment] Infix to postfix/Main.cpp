#include <iostream>
#include <string>

using namespace std;

// Node Class
class Node
{
public:
	char value;
	Node* next;

	Node(char value)
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
	void push(char value)
	{
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
		height++;
	}

	// Removing Element from TOP
	char pop()
	{
		if (height == 0) return INT_MIN;

		Node* temp = top;
		char poppedValue = top->value;
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
	char topValue()
	{
		if (top) return top->value;

		return INT_MIN;
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

// Checking Operator Precende
int precedenceCheck(char c)
{
	if (c == '^') return 3;
	if (c == '*' || c == '/') return 2;
	if (c == '+' || c == '-') return 1;
	return 0;
}

// Checking for Operands
bool isOperand(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Infix to Postfix Conversion
string infixToPostfix(string infix)
{
	Stack stack;
	string postfix = "";

	for (int i = 0; i < infix.length(); i++)
	{
		char element = infix[i];

		if (isOperand(element))
		{
			postfix += element;
		}
		else if (element == '(')
		{
			stack.push(element);
		}
		else if (element == ')')
		{
			while (!stack.isEmpty() && stack.topValue() != '(')
				postfix += stack.pop();
			stack.pop();
		}
		else
		{
			while (!stack.isEmpty() && precedenceCheck(stack.topValue()) >= precedenceCheck(element))
				postfix += stack.pop();
			stack.push(element);
		}
	}

	while (!stack.isEmpty())
		postfix += stack.pop();

	return postfix;
}

int main()
{
	string infix = "a+b*(c^d-e)^(f+g*h)-i";
	cout << "Infix Expression: " << infix << endl;

	string postfix = infixToPostfix(infix);
	cout << "Postfix Expression: " << postfix << endl;

	return 0;
}