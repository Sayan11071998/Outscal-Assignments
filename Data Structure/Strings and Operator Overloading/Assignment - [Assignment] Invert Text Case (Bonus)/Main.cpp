#include <iostream>
#include <string>

using namespace std;

class StringConverter
{
public:
	StringConverter(const string& _input) : input(_input) {}

	string flipStringCase()
	{
		string output;
		
		for (char c : input)
		{
			if (islower(c))
				output += toupper(c);
			else if (isupper(c))
				output += tolower(c);
			else
				output += c;
		}

		return output;
	}

private:
	string input;
};


int main()
{
	string userInput;

	cout << "Please enter the string: ";
	getline(cin, userInput);

	StringConverter string_converter(userInput);

	cout << "Inverted result: " << string_converter.flipStringCase();

	return 0;
}