#include <iostream>
#include <string>

using namespace std;

bool bIsAnagram(const string& _input1, const string& _input2)
{
	if (_input1.length() != _input2.length()) { return false; }

	int asciiCount[256] = { 0 };

	for (char c : _input1) { asciiCount[(int)c]++; }
	for (char c : _input2) { asciiCount[(int)c]--; }

	for (int i = 0; i < 256; i++)
		if (asciiCount[i] != 0) { return false; }

	return true;
}

int main()
{
	string input_11 = "anagram";
	string input_12 = "nagaram";
	string input_21 = "rat";
	string input_22 = "car";

	cout << "Anagram Check between " << input_11 << " and " << input_12 << " is: " << (bIsAnagram(input_11, input_12) ? "True" : "False") << endl;
	cout << "Anagram Check between " << input_21 << " and " << input_22 << " is: " << (bIsAnagram(input_21, input_22) ? "True" : "False") << endl;

	return 0;
}