#include <iostream>
#include <memory>
using namespace std;

class Player
{
public:
    Player(){
        cout << "I am a player, I just not spawned" << endl;
    }

    ~Player(){
        cout << "Ops, that enemy killed me, I just died!" << endl;
    }

};

int main()
{
    Player player_1;

    Player* player_2 = new Player();
    //unique_ptr<Player> player_2 = make_unique<Player>();

    delete player_2;

    return 0;
}