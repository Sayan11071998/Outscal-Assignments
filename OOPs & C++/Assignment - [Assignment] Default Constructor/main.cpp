#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
    Player(int PlayerHealth, int Score, string Name){
        playerHealth = PlayerHealth;
        score = Score;
        name = Name;
        cout << "Hi, I am a default constructor of Class Player, basically developers use me to initialize important variables/parameters of the player.."  << endl;
    }

    ~Player(){

    }

    int GetPlayerHealth() const{
        return playerHealth;
    }

    int GetScore() const{
        return score;
    }

    string GetName() const{
        return name;
    }

private:
    int playerHealth;
    int score;
    string name;
};

int main()
{
    int playerHealth;
    int score;
    string name;

    cout << "Please provide the player health : ";
    cin >> playerHealth;
    cout << "Please provide the player score : ";
    cin >> score;
    cin.ignore();
    cout << "Please provide player name : ";
    getline(cin, name);

    Player player(playerHealth, score, name);
    cout << "Player health is : " << player.GetPlayerHealth() <<endl;
    cout << "Player score is : " << player.GetScore() <<endl;
    cout << "Player name is : " << player.GetName() <<endl;

    return 0;
}