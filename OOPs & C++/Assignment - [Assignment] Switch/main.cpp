#include <iostream>
using namespace std;

int main()
{
    int PlayerType;
    cout << "Please choose the Player Type :" << endl;
    cout << "Press 1 for Extreme Powerful Character." << endl;
    cout << "Press 2 for Medium Powerful Character." << endl;
    cout << "Press 3 for Powerful Character." << endl;
    cout << "Press 4 for Weak Character." << endl;
    cout << "Press 5 for Extreme Weak Character." << endl;
    cout << "Please choose one : ";
    cin >> PlayerType;

    switch(PlayerType)
    {
        case 1:
            cout << "You have choosen an extremely powerful character!!" << endl;
            break;
        case 2:
            cout << "You have choosen a medium powerful character!!" << endl;
            break;
        case 3:
            cout << "You have choosen a powerful character!!" << endl;
            break;
        case 4:
            cout << "You have choosen a weak character!!" << endl;
            break;
        case 5:
            cout << "You have choosen a extremely weak character!!" << endl;
            break;
        default:
            cout << "Invalid option!!" << endl;
    }

    return 0;
}
