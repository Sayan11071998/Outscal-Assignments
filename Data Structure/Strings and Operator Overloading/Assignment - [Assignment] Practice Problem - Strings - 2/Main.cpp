#include <iostream>
#include <string>

using namespace std;

int firstUniqueCharacter(string _input)
{
	int charCount[256] = { 0 };

	for (char c : _input) { charCount[(int)c]++; }

	for (int i = 0; i < _input.length(); i++)
		if (charCount[(int)_input[i]] == 1) { return i; }

	return -1;
}

int main()
{
	string input_1 = "leetcode";
	string input_2 = "loveleetcode";
	string input_3 = "aabb";

	cout << "Input: " << input_1 << " and Output: " << firstUniqueCharacter(input_1) << endl;
	cout << "Input: " << input_2 << " and Output: " << firstUniqueCharacter(input_2) << endl;
	cout << "Input: " << input_3 << " and Output: " << firstUniqueCharacter(input_3) << endl;

	return 0;
}