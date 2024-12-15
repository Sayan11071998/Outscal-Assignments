#include <iostream>
#include <string>

using namespace std;

bool bIsVowel(char c)
{
	c = tolower(c);
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string vowelReversal(string _input)
{
	int start = 0;
	int end = _input.length() - 1;

	while (start < end)
	{
		while (start < end && !bIsVowel(_input[start])) start++;
		while (start < end && !bIsVowel(_input[end])) end--;

		swap(_input[start], _input[end]);
		start++;
		end--;
	}

	return _input;
}

int main()
{
	string input_1 = "hello";
	string input_2 = "Outscal";

	cout << "Input: " << input_1 << " and Output: " << vowelReversal(input_1) << endl;
	cout << "Input: " << input_2 << " and Output: " << vowelReversal(input_2) << endl;

	return 0;
}