#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player(string _name) : name(_name) {}

	Player operator +(const Player& otherPlayer)
	{
		return Player(this->name + " " + otherPlayer.name);
	}

	string getName() const
	{
		return name;
	}

private:
	string name;
};


int main()
{
	string name_1, name_2;

	cout << "Please Enter the Player 1 name: ";
	getline(cin, name_1);
	cout << "Please Enter the Player 2 name: ";
	getline(cin, name_2);

	Player player_1(name_1);
	Player player_2(name_2);

	cout << (player_1 + player_2).getName();

	return 0;

}