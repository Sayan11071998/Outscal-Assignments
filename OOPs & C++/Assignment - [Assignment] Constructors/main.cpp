#include <iostream>
using namespace std;

class Player
{
public:
    Player(){}

    Player(int HealthValue, int LivesValue) : health(HealthValue), lives(LivesValue) {
        cout << "I am a player, I just got spawned! My starting health is : " << health << endl;
    }

    ~Player(){
        cout << "I am a player and I died!! My health is : " << health << endl;
    }

private:
    int health;
    int lives;

};

class FastPlayer : public Player
{
public:
    FastPlayer(){}

    FastPlayer(int HealthValue, int LivesValue, int SpeedValue)
        : Player(HealthValue, LivesValue), speed(SpeedValue) {
            cout << "I am a fast player, I just got spawned! My speed is : " << speed << endl;
    }

    ~FastPlayer(){
        cout << "I am a fast player and I died!! My speed is : " << speed << endl;
    }
    

private:
    int speed;

};

void localObject(){
    Player* player = new Player(300, 3);
    FastPlayer* fastPlayer = new FastPlayer(500, 4, 1000);

    delete player;
    delete fastPlayer;
}

int main()
{
    Player* player1 = new Player(100, 3);
    Player* player2 = new Player(150, 2);
    Player* player3 = new Player(200, 1);
    FastPlayer* fastPlayer = new FastPlayer(70, 5, 2000);

    localObject();

    delete player1;
    delete player2;
    delete player3;
    delete fastPlayer;

    return 0;
}