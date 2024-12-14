#include <iostream>
#include <string>

using namespace std;

string findDuplicates(const string& _input)
{
	int asciiCount[256] = { 0 };
	string output;

	for (char c : _input)
		asciiCount[(int)c]++;

		for (int i = 0; i < 256; i++)
		{
			if (asciiCount[i] > 1)
				output += (char)i;
		}

	return output;
}

int main()
{
	string input_1 = "ABCDEABE";
	string input_2 = "ABCDE";
	string input_3 = "ABCDabcacdA";

	cout << "Result 1: " << findDuplicates(input_1) << endl;
	cout << "Result 2: " << findDuplicates(input_2) << endl;
	cout << "Result 3: " << findDuplicates(input_3) << endl;

	return 0;
}