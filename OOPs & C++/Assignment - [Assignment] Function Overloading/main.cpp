#include <iostream>
#include <string>
using namespace std;

class Dragon
{
public:
    void AccessSuperPower(string attackName){
        if(IsDead())
            return;
        cout << "Dragon is perforimg " << attackName << " onto the enemies, burning out everything on the way!!" << endl;
    }
    
    void AccessSuperPower(string attackName, int attackRange){
        if(IsDead())
            return;
        cout << "Dragon is perforimg " << attackName << " onto the enemies, within the range of " << attackRange << " meters, washing out their existence!!" << endl;
    }

    void AccessSuperPower(string attackName, string attackType, int attackRange){
        if(IsDead())
            return;
        cout << "Dragon is perforimg " << attackType << " " << attackName << " onto the enemies, within the range of " << attackRange << " meters!!" << endl;
    }
protected:
    bool IsDead(){
        if(health <= 0){
            cout << "Dragon Died!!" << endl;
            return true;
        }
        return false;
    }

private:
    int health = 10;
    string attackName;
};

int main()
{
    Dragon dragon;
    dragon.AccessSuperPower("Fire Attack");
    dragon.AccessSuperPower("Water Attack", 200);
    dragon.AccessSuperPower("Air Attack", "Poisonous", 100);

    return 0;
}