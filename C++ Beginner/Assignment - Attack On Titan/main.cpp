#include <iostream>
#include <ctime>

using namespace std;

class Player{
    public:
        Player(){
            cout << "*** Hello! I am Eren Yeager. Let me tell you my story! ***" << endl;
            cout << "• The walls have always been our prison, but I refuse to live in fear any longer." << endl;
            cout << "• Every Titan I see is a reminder of the world that was stolen from us." << endl;
            cout << "• I will fight to my last breath to uncover the truth and free humanity from these chains." << endl;
            cout << "• With every battle, I inch closer to my goal — to see the day when we can live without fear of the Titans." << endl;
            cout << "• This is not just a fight for survival; it's a fight for our freedom and our future." << endl;
            cout << endl;
        }

        int GetHealth(){
            return health;
        }

        int GetMaxAttackPower(){
            return maxAttackPower;
        }

        int GetMinAttackPower(){
            return minAttackPower;
        }

        int GetMaxHealingPower(){
            return maxHealingPower;
        }

        int GetMinHealingPower(){
            return minHealingPower;
        }

        int GiveDamage(){
            srand(time(0));
            int randomDamage = (rand() % (maxAttackPower - minAttackPower + 1) + minAttackPower);

            return randomDamage;
        }

        void Takedamage(int damage){
            cout << "Careful!! Eren has received a critical damage." << endl;
            cout << "Titan is dealing a damage of " << damage << " to Eren!!" << endl;
            health -= damage;
            
            if(health < 0){
                cout << endl;
                cout << "Eren Died!!!" << endl;
            } else{
                cout << "Eren's current health after receiving the damage is : " << health << endl;
                cout << endl;
            }
        }

        void Heal(){
            srand(time(0));
            int randomHeal = (rand() % (maxHealingPower - minHealingPower + 1) + minHealingPower);

            health += randomHeal;
            cout << "Eren healed with HP of " << randomHeal << endl;
            cout << "Eren's health after healing is : " << health << endl;
            cout << endl;
        }

    private:
        int health = 100;
        int maxAttackPower = 20;
        int minAttackPower = 5;
        int maxHealingPower = 30;
        int minHealingPower = 10;
};

class Enemy{
    public:
        Enemy(){
            cout << "*** Suddenly a Titan appeared!! ***" << endl;
            cout << "• I am the harbinger of destruction, emerging from the depths of darkness." << endl;
            cout << "• With every step, the earth trembles, and with every roar, fear spreads among the walls." << endl;
            cout << "• My immense power and unyielding hunger make me a force to be reckoned with." << endl;
            cout << "• I am not merely a beast; I am a relentless storm that tests the very will of humanity." << endl;
            cout << "• Prepare for a battle where every clash echoes the struggle for survival." << endl;
            cout << endl;
        }

        int GetHealth(){
                return health;
        }

        int GetMaxAttackPower(){
            return maxAttackPower;
        }

        int GetMinAttackPower(){
            return minAttackPower;
        }

        int GiveDamage(){
            srand(time(0));
            int randomDamage = (rand() % (maxAttackPower - minAttackPower + 1) + minAttackPower);

            return randomDamage;
        }

        void Takedamage(int damage){
            cout << "Titan has received a critical damage." << endl;
            cout << "Eren is dealing a damage of " << damage << " to Titan!!" << endl;
            health -= damage;

            if(health < 0){
                cout << endl;
                cout << "Titan Died!!!" << endl;
            } else{
                cout << "Titan's current health after receiving the damage is : " << health << endl;
                cout << endl;
            }
        }

    private:
        int health = 100;
        int maxAttackPower = 40;
        int minAttackPower = 20;
};

void gameLoop(Player eren, Enemy titan){
    
    char playerChoice;
    
    do{
        cout << "Press 'A' to attack or 'H' to heal" << endl;
        cin >> playerChoice;
        cout << endl;

        if(playerChoice == 'a' || playerChoice == 'A'){
            // Attack the Titan
            titan.Takedamage(eren.GiveDamage());
            
            if(titan.GetHealth() > 0){
                cout << "Thats all you got?? Its my turn now!!" << endl;
                cout << endl;
                eren.Takedamage(titan.GiveDamage());
            }

        } else if(playerChoice == 'h' || playerChoice == 'H'){
            // Heal Eren
            eren.Heal();
            
            if(titan.GetHealth() > 0){
                cout << "Thats all you got?? Its my turn now!!" << endl;
                cout << endl;
                eren.Takedamage(titan.GiveDamage());
            }

        } else {
            system("clear");
            cout << "Invalid input!!" << endl;
        }

    } while (eren.GetHealth() > 0 && titan.GetHealth() > 0);
    
}

void gameStory(){
    cout << "Hello and Welcome to Attack on Titan!" << endl;
    cout << "-------------------------------------" << endl;
    cout << "• In a world ravaged by colossal giants, humanity teeters on the brink of extinction." << endl;
    cout << "• The last remnants of civilization cling to existence within massive, towering walls, shielded from the monstrous Titans that roam the land." << endl;
    cout << "• The walls have protected humanity for generations, but the peace they offer is a fragile illusion." << endl;
    cout << "• Your journey begins in the heart of this beleaguered world. As a new recruit in the elite Survey Corps, you are tasked with a critical mission: to uncover the truth behind the Titans and reclaim humanity's lost freedom." << endl;
    cout << "• Rumors whisper of a hidden power that could change the tide of battle — a power buried deep within the Titans themselves." << endl;
    cout << "• But the path ahead is fraught with danger. Titans lurk beyond the walls, their ferocious hunger and unrelenting strength making every step a perilous gamble." << endl;
    cout << "• You must navigate the treacherous battlefield, harnessing the advanced maneuvering gear and honing your combat skills to survive." << endl;
    cout << "• As you fight to protect the last vestiges of humanity, you will uncover secrets that could shatter everything you thought you knew about the Titans and the world itself." << endl;
    cout << "• Will you be the hero who leads humanity to victory, or will you become another lost soul in the shadow of the Titans?" << endl;
    cout << "• Prepare yourself — the battle for survival begins now. Choose your destiny wisely!" << endl;
    cout << endl;
}

int main()
{
    gameStory();

    char userInput;
    do{
        cout << "Press S to start the game or any other key to exit!!" << endl;
        cin >> userInput;
        cout << endl;

        if(userInput == 'S' || userInput == 's'){
            Player eren;
            cout << "Eren's Health is : " << eren.GetHealth() << endl;
            cout << "Eren's attack power range is between " << eren.GetMinAttackPower() << " to " << eren.GetMaxAttackPower() << endl;
            cout << "Eren's healing power range is between " << eren.GetMinHealingPower() << " to " << eren.GetMaxHealingPower() << endl;
            cout << endl;

            Enemy titan;
            cout << "Titan's Health is : " << titan.GetHealth() << endl;
            cout << "Titan's attack power range is between " << titan.GetMinAttackPower() << " to " << titan.GetMaxAttackPower() << endl;
            cout << endl;

            gameLoop(eren, titan);
            
        } else{
            cout << "Thanks for playing Attack on Titan!!" << endl;
        }

    } while (userInput == 'S' || userInput == 's');
    
    return 0;
}