#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "Sayan1107Nandi";
	string reverse_str = "";

	for (int i = str.size() - 1; i >= 0; i--) { reverse_str += str[i]; }
	cout << "Reverse String: " << reverse_str;
}