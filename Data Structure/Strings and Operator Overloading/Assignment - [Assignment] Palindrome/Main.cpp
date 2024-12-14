#include <iostream>
#include <string>

using namespace std;

bool bIsPalindrome(const string& _input)
{
	int left = 0;
	int right = _input.length() - 1;
	string output;

	while (left < right)
	{
		if (_input[left] != _input[right])
			return false;
		left++;
		right--;
	}

	return true;
}

int main()
{
	string input_1 = "aba";
	string input_2 = "abcde";

	cout << "Result 1: " << (bIsPalindrome(input_1) ? "True" : "False") << endl;
	cout << "Result 2: " << (bIsPalindrome(input_2) ? "True" : "False") << endl;

	return 0;
}