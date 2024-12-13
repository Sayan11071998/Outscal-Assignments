#include <iostream>
using namespace std;

class Player
{
public:
    Player(){
        cout << "Creating an object of class Player." << endl;
    }

    ~Player(){
        cout << "Deleting object of class Player." << endl;
    }

private:

};

class StrongPlayer : public Player
{
public:
    StrongPlayer(){
        cout << "Creating an object of class StrongPlayer." << endl;
    }

    ~StrongPlayer(){
        cout << "Deleting object of class StrongPlayer." << endl;
    }

private:

};

int main()
{
    
    StrongPlayer strongPlayer;

    return 0;
}