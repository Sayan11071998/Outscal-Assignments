#include <iostream>
using namespace std;

class Enemy
{
public:
    virtual void attack() = 0;
};

class BossEnemy : public Enemy
{
public:
    void attack() override{
        cout << "Boss is attacking." << endl;
    }
};

int main()
{
    Enemy* enemy;
    BossEnemy bossEnemy;

    enemy = &bossEnemy;

    enemy->attack();

    return 0;
}