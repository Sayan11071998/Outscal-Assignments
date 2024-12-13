#include <iostream>
using namespace std;

class Weapon
{
public:
    Weapon(int _attackPower, int _length, int _weight)
        : attackPower(_attackPower), length(_length), weight(_weight) {} 
    
    ~Weapon(){}

    virtual void attack(){
        cout << "Weapon performed attack." << endl;
    }

    void info(){
        cout << "*** Weapon details ***" << endl;
        cout << "Attack Power : " << attackPower << endl;
        cout << "Length : " << length << endl;
        cout << "Weigth : " << weight << endl;
    }

protected:
    int attackPower;
    int length;
    int weight;

};

class RangedWeapon : public Weapon
{
public:
    RangedWeapon(int _attackPower, int _length, int _weight, int _range)
        : Weapon(_attackPower, _length, _weight), range(_range) {}
    
    ~RangedWeapon(){}

    void attack() override{
        cout << "Performing ranged attack." << endl;
    }

    void info(){
        cout << "*** Ranged Weapon details ***" << endl;
        cout << "Attack Power : " << attackPower << endl;
        cout << "Length : " << length << endl;
        cout << "Weigth : " << weight << endl;
        cout << "Range : " << range << endl;
    }

private:
    int range;
};

int main()
{
    Weapon* weapon = new Weapon(40, 10, 5);
    RangedWeapon rangedWeapon(20, 17, 7, 60);
    weapon = &rangedWeapon;
    weapon->attack();
    weapon->info();

    return 0;
}