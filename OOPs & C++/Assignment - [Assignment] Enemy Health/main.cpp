#include <iostream>
using namespace std;

int main()
{
    int enemyHealth;
    cout << "Please type the enemy health : " << endl;
    cin >> enemyHealth;

    int* p;
    int* q;

    p = &enemyHealth;
    q = &enemyHealth;

    cout << "p : " << p << endl;
    cout << "q : " << q << endl;
    cout << "*p : " << *p << endl;
    cout << "*q : " << *q << endl;
    cout << "Enemy health : " << enemyHealth << endl;

    cout << "Please type another enemy health : " << endl;
    cin >> enemyHealth;

    cout << "*p : " << *p << endl;
    cout << "*q : " << *q << endl;
    cout << "Enemy health : " << enemyHealth << endl;

    return 0;
}