#include <iostream>

using namespace std;

class Player
{
    public:
        void Shoot(){
            if(bullets <= 0){
                cout << "We are Out of Bullets!" << endl;
            } else {
                bullets --;
                cout << "The number of available bullets are : " << bullets << endl;
            }
        }

        void TakeDamage(int damage){
            if(IsDead()){
                cout << "Player Died!!" << endl;
            } else{
                health -= damage;
                if(health > 0)
                    cout << "Player's current health is : " << health << endl;
            }
        }

        void ReviveHealth(int value){
            health += value;
        }

    private:
        int health = 100;
        int bullets = 10;

        bool IsDead(){
            if(health > 0)
                return false;
            return true;
        }
};

int main()
{
    Player player;

    return 0;
}