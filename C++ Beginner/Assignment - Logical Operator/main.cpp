#include <iostream>

using namespace std;

int main()
{
    bool isPlayerInRange, isPlayerAttacking, isPlayerDefending;
    int PlayerHealth;

    cout << "Is the Player in Range? (YES = 1, No = 0) " << endl;
    cin >> isPlayerInRange;
    cout << "Is the Player Attacking? (YES = 1, No = 0) " << endl;
    cin >> isPlayerAttacking;
    cout << "Is the Player Defending? (YES = 1, No = 0) " << endl;
    cin >> isPlayerDefending;
    cout << "Enter Player's Health: " << endl;
    cin >> PlayerHealth;

    if(isPlayerInRange)
    {
        if(!isPlayerAttacking && !isPlayerDefending)
            cout << "The Enemy should Attack" << endl;
        else if(isPlayerDefending)
            cout << "Enemy should hold" << endl;
        
        if((PlayerHealth < 20) && isPlayerAttacking)
            cout << "Player should deliver a rage attack." << endl;
        
        if(!isPlayerDefending && (PlayerHealth == 100 || PlayerHealth < 10))
            cout << "enemy should do a special ability attack." << endl;
    }


    return 0;
}