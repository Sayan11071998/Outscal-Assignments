#include <iostream>

using namespace std;

void Shooting(){
    cout << "player is shooting" << endl;
}

void Healing(){
    cout << "player is healing" << endl;
}

void Attacking(){
    cout << "player is attacking" << endl;
}

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < 10; i++){
        Shooting();
    }

    while (j < 5){
        Healing();
        j++;
    }

    do{
        Attacking();
        k++;
    } while (k < 7);
    
    
    return 0;
}