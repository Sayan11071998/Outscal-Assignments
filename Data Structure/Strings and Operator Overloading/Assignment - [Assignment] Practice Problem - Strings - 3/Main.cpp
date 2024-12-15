#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sumCalculation(string _input)
{
	int score = 0;

	for (int i = 1; i < _input.length(); i++)
		score += abs((int)_input[i] - (int)_input[i - 1]);

	return score;
}

int main()
{
	string input_1 = "hello";
	string input_2 = "zaz";

	cout << "Input: " << input_1 << " and Output: " << sumCalculation(input_1) << endl;
	cout << "Input: " << input_2 << " and Output: " << sumCalculation(input_2) << endl;

	return 0;
}