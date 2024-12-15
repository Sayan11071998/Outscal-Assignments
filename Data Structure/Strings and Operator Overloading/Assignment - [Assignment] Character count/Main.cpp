#include <iostream>
#include <string>

using namespace std;

void charCount(const string& _input)
{
	int asciiCount[256] = { 0 };

	for (char c : _input) { asciiCount[(int)c]++; }

	for (int i = 0; i < 256; i++)
		if (asciiCount[i] > 0) { cout << (char)i << " - " << asciiCount[i] << endl; }
}

int main()
{
	string input_1 = "ABBAC";
	string input_2 = "abcAB";

	cout << "Input 1:" << endl;
	charCount(input_1);
	
	cout << "Input 2: " << endl;
	charCount(input_2);

	return 0;
}