#include <iostream>

using namespace std;

int main()
{
  int PlayerHealth;
  int LivesCount;
  double PlayerId;
  float WinPercentage;
  bool HasPlayerWon;
  char TypeOfPlayer;

  int HasPlayerWonInput;

  cout << "***Please enter the Player Stats below***" << endl;
  cout << endl;
  
  cout << "Enter Player Health: ";
  cin >> PlayerHealth;

  cout << "Enter Lives Count: ";
  cin >> LivesCount;

  cout << "Enter Player Id: ";
  cin >> PlayerId;

  cout << "Enter Win Percentage: ";
  cin >> WinPercentage;

  cout << "Enter if the Player has Won (Yes == 1, No == 0): ";
  cin >> HasPlayerWonInput;
  HasPlayerWon = HasPlayerWonInput == 1;

  cout << "Enter the Type of the Player: ";
  cin >> TypeOfPlayer;

  cout << endl;

  cout << "---------------------------------------" << endl;
  cout << endl;
  
  cout << "***Please find your player's Stats***" << endl;
  cout << endl;
  cout << "PlayerHealth: " << PlayerHealth << endl;
  cout << "LivesCount: " << LivesCount << endl;
  cout << "PlayerId: " << PlayerId << endl;
  cout << "WinPercentage: " << WinPercentage << endl;
  cout << "HasPlayerWon: " << (HasPlayerWon ? "Yes" : "No") << endl;

  return 0;
}