#include <iostream>
using namespace std;

class PlayerInterface
{
public:
    virtual void DoubleJump() = 0;
    virtual void Fire() = 0;
};

class Player : public PlayerInterface
{
public:
    void DoubleJump() override{
        cout << "Double Jump is over ridden" << endl;
    }

    void Fire() override{
        cout << "Fire is over ridden" << endl;
    }
};

int main()
{
    Player player;
    player.DoubleJump();
    player.Fire();

    return 0;
}