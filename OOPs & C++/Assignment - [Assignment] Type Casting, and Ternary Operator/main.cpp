#include <iostream>
using namespace std;

int main()
{
    // Implicit Type Casting
    cout << "Implicit Type Casting" << endl;
    int playerHealth;
    cout << "Please provide Player health : ";
    cin >> playerHealth;
    short playerCode;
    playerCode = (short) playerHealth;
    cout << "Size of int data type player health : " << sizeof(playerHealth) << endl;
    cout << "Size of short data type player code :  " << sizeof(playerCode) << endl;
    cout << endl;

    // Explicit Type Casting
    cout << "Explicit Type Casting" << endl;
    int playerHealthExplicit;
    cout << "Please provide Player health : ";
    cin >> playerHealthExplicit;
    float playerHealthFractional;
    playerHealthFractional = (float) playerHealthExplicit / 2;
    cout << "Size of int data type player health : " << sizeof(playerHealthExplicit) << endl;
    cout << "Size of float data type player health fractional :  " << sizeof(playerHealthFractional) << endl;
    cout << endl;

    // Ternary Operator
    cout << "Ternary Operator" << endl;
    string result = (playerHealth == playerCode) ? "true" : "false";
    cout << result;

    return 0;
}
