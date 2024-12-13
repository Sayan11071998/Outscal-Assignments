#include <iostream>
using namespace std;

class Player
{
public:
    Player(){
        playerHealth = new int();
    }

    ~Player(){
        delete playerHealth;
    }

    int GetPlayerHealth() const{
        return *playerHealth;
    }

    void SetPlayerHealth(int playerHealthValue){
        *playerHealth = playerHealthValue;
    }

private:
    int* playerHealth;
};

int main()
{
    Player* player = new Player();
    player->SetPlayerHealth(100);
    cout << "Player Health is : " << player->GetPlayerHealth() << endl;

    delete player;

    return 0;
}