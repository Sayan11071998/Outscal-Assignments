#include <iostream>

using namespace std;

float health = 100.f;
float attack = 30.f;
float defense = 100.f;
float healingPower = 25.f;

void TakeDamage(float damageToInflict)
{
    health -= damageToInflict;
    cout << "Player Health after receiving damage: " << health << endl;
}

void Heal(float healthToRecover)
{
    health += healthToRecover;
    cout << "Player Health after healing: " << health << endl;
}

void DamageMultiplier(float multiplier)
{
    cout << "Player damage after multiplier : " << attack * multiplier << endl;
}

int main()
{
    cout << "***Initial Player Stats***" <<endl;
    cout << "Player Health: " << health << endl;
    cout << "Attack Power: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Healing Power: " << healingPower << endl;

    cout << "***Final Player Stats***" << endl;
    TakeDamage(40);
    Heal(healingPower);
    DamageMultiplier(1.5);

    return 0;
}