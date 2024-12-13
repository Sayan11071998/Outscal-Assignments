#include <iostream>
using namespace std;

class Player
{
public:
    Player(){
        cout << "I am a player (the name is as per your liking). I just got spawned in the game world because my developer created the player's object. Agggh! boring life begins, fight, die, respawn. Huh I am gonna kill that bastard if I get out of this game" << endl;
    }

    ~Player(){
        cout << "See?? that C++ destroyed my object(figure out how) and now I died." << endl;
    }

private:

};

int main()
{
    
    Player player;

    return 0;
}