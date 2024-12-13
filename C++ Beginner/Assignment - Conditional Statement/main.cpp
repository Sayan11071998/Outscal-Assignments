#include <iostream>

using namespace std;

int main()
{
    int PlayerHealth, EnemyHealth;

    cout << "Please Enter the Player Health: ";
    cin >> PlayerHealth;
    cout << "Please Enter the Enemy Health: ";
    cin >> EnemyHealth;

    if(PlayerHealth == 100)
    {
        cout << "Player Health is full!" << endl;
    } else if(PlayerHealth == 50)
    {
        cout << "Player Health is Half!" << endl;
    } else if(PlayerHealth == 0)
    {
        cout << "Player is dead!" << endl;
    }

    if(PlayerHealth > 0)
    {
        if(EnemyHealth == 100)
        {
            cout << "Enemy Health is full!" << endl;
        } else if(EnemyHealth == 50)
        {
            cout << "Enemy Health is Half!" << endl;
        } else if(EnemyHealth == 0)
        {
            cout << "Enemy is dead!" << endl;
        }
    }

    if(PlayerHealth == 0 && EnemyHealth == 0)
    {
        cout << "Game Over! Match Draw!" << endl;
    } else if(PlayerHealth == 0 || EnemyHealth == 0)
    {
        if(PlayerHealth != 0)
        {
            cout << "Game Over! Player Won!" << endl;
        } else
        {
            cout << "Game Over! Player Lost!" << endl;
        }
    }

    return 0;
}