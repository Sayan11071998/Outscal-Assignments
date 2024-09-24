#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Player;
class Enemy;

void gameLoop(Player &player, Enemy &enemy);

// Interface for Player Actions
class IPlayer {
public:
    virtual int MeleeAttack() = 0;
    virtual int RangedAttack() = 0;
    virtual int PlayerAttack() = 0;
    virtual void Heal() = 0;
    virtual void LevelUp() = 0;
    virtual int GetPlayerHealthValue() const = 0;
    virtual void PlayerTakeDamage(int damage) = 0;
    virtual void SpecialAbility(const std::string& ability) = 0;
    virtual void SpecialItem(const std::string& item) = 0;
};

// Interface for Enemy Actions
class IEnemy {
public:
    virtual int EnemyAttack() = 0;
    virtual int GetEnemyHealth() const = 0;
    virtual void EnemyTakeDamage(int damage) = 0;
};

class Player : public IPlayer
{
public:
    // Constructors
    Player()
        : health(100), maxMeleeDamage(10), minMeleeDamage(5), meleeDamage(7), maxRangedDamage(10), minRangedDamage(7), rangedDamage(10), defence(100), specialAbilities({""}), specialItems({""}), IsBlockerActive(false) {}

    // Getters
    void GetHealth() const{ cout << "Health: " << health << endl; } // Get Health
    void GetMeleeDamage() const{ cout << "Melee Damage: " << meleeDamage << endl; } // Get Melle Damage Value
    void GetRangedDamage() const{ cout << "Ranged Damage: " << rangedDamage << endl; } // Get Range Damage Value
    void GetDefence() const{ cout << "Defence: " << defence << endl; } // Get Defense Value
    void GetSpecialAbilities() const{ // Get Special Abilities
        cout << "Special Abilities: ";
        if(specialAbilities.empty()){
            cout << "None";
        } else{
            for(int i = 0; i < specialAbilities.size(); i++){
                if(i > 0){
                    cout << ", ";
                }
                cout << specialAbilities[i];
            }
        }
        cout << endl;
    }
    void GetSpecialItems() const{ // Get Special Items
        cout << "Special Items: ";
        if(specialItems.empty()){
            cout << "None";
        } else{
            for(int i = 0; i < specialItems.size(); i++){
                if(i > 0){
                    cout << ", ";
                }
                cout << specialItems[i];
            }
        }
        cout << endl;
    }

    // Printing Player Stats
    void PrintPlayerStats(){
        cout << "*** Player's Stats ***" << endl;
        GetHealth();
        GetMeleeDamage();
        GetRangedDamage();
        GetDefence();
        GetSpecialAbilities();
        GetSpecialItems();
        cout << endl;
    }

    // Player Attack
    int MeleeAttack() override{
        srand(time(0));
        meleeDamage = (rand() % (maxMeleeDamage - minMeleeDamage + 1) + minMeleeDamage);
        cout << "Player attacks with melee damage of: " << meleeDamage << endl;
        return meleeDamage;
    }

    int RangedAttack() override{
        srand(time(0));
        rangedDamage = (rand() % (maxRangedDamage - minRangedDamage + 1) + minRangedDamage);
        cout << "Player attacks with ranged damage of: " << rangedDamage << endl;
        return rangedDamage;
    }

    bool hasCriticalHitAbility = false;

    bool IsCriticalHit(){
        return (rand() % 100) < 10;
    }

    int PlayerAttack() override{
        srand(time(0));
        int randomNumber = rand() % 2;
        int damage = 0;
        if(randomNumber == 0){
            damage = MeleeAttack();
            if(hasCriticalHitAbility && IsCriticalHit()){
                cout << "Critical Hit with Melee! Damage is doubled!" << endl;
                damage *= 2;
            }
        } else{
            damage = RangedAttack();
            if(hasCriticalHitAbility && IsCriticalHit()){
                cout << "Critical Hit with Melee! Damage is doubled!" << endl;
                damage *= 2;
            }
        }

        return damage;
    }

    // Player Heal
    void Heal() override {
        int maxHealValue = 15;
        int minHealValue = 10;
        srand(time(0));
        int healAmount = (rand() % (maxHealValue - minHealValue + 1) + minHealValue);
        health += healAmount;
        cout << "Player heals and now has health of: " << health << endl;
    }

    // Player Level Up
    void LevelUp() override {
        int maxHealth = 100;
        int maxDefense = 100;
        health = maxHealth + 20;
        maxMeleeDamage += 10;
        minMeleeDamage += 10;
        meleeDamage += 10;
        maxRangedDamage += 10;
        minRangedDamage += 10;
        rangedDamage += 10;
        defence = maxDefense + 20;
        cout << "Player has Leveled up!!" << endl;
        cout << endl;
        // PrintPlayerStats();
    }

    // Get Player Health
    int GetPlayerHealthValue() const{
        return health;
    }

    // Player Taking Damage
    void PlayerTakeDamage(int damage) override{
        if(health <= 0) return;

        if(IsBlockerActive){
            srand(time(0));
            if(rand() % 100 < 10){
                cout << "Blocker ability activated! No damage taken." << endl;
                return;
            }
        }

        health -= static_cast<int>(damage/2);
        defence -= static_cast<int>(damage/2);
        if(health <= 0 ){
            cout << "Player Died!!" << endl;
        } else{
            cout << "Player health is: " << health << endl;
            cout << "Player defense is: " << defence << endl;
        }
    }

    void ActivateBlocker(){
        IsBlockerActive = true;
        cout << "Blocker ability activated!" << endl;
    }

    // New Special Ability
    void SpecialAbility(const std::string& ability) override{
        specialAbilities.push_back(ability);
        cout << "Player has gained new special Ability: " << ability << endl;
    }

    // New Special Item
    void SpecialItem(const std::string& item) override{
        specialItems.push_back(item);
        cout << "Player has gained new special Item: " << item << endl;
        cout << endl;
        PrintPlayerStats();
    }

private:
    int health;
    int maxMeleeDamage;
    int minMeleeDamage;
    int meleeDamage;
    int maxRangedDamage;
    int minRangedDamage;
    int rangedDamage;
    int defence;
    vector<string> specialAbilities;
    vector<string> specialItems;
    bool IsBlockerActive;
};

class Enemy : public IEnemy
{
public:
    // Constructor
    Enemy(int _health, int _maxAttackDamage, int _minAttackDamage) : health(_health), maxAttackDamage(_maxAttackDamage), minAttackDamage(_minAttackDamage) {}
    
    // Enemy Attack
    int EnemyAttack() override{
        srand(time(0));
        int attackDamage = (rand() % (maxAttackDamage - minAttackDamage + 1) + minAttackDamage);
        cout << "Enemy attacks with damage of " << attackDamage << endl;
        return attackDamage;
    }
    
    // Get Enemy Health
    int GetEnemyHealth() const override{
        return health;
    }

    // Enemy Taking Damage
    void EnemyTakeDamage(int damage) override{
        if(health <= 0) return;
        health -= damage;
        if(health <= 0 )
            cout << "Enemy Defeated" << endl;
        else
            cout << "Enemy health is: " << health << endl;
    }

private:
    int health;
    int maxAttackDamage;
    int minAttackDamage;
};

template <int levelNumber>
class Level
{
public:
    // Constructor
    Level(){
        numberOfEnemies = levelNumber;
        int enemyHealth = 15 + (levelNumber * 3);
        int maxEnemyAttackDamage = 5 + (levelNumber * 2);
        int minEnemyAttackDamage = 5 + (levelNumber * 2);
        for(int i = 0; i < numberOfEnemies; i++){
            enemies.push_back(Enemy(enemyHealth, maxEnemyAttackDamage, minEnemyAttackDamage));
        }
    }

    bool runLevel(Player &player){
        cout << "Level " << levelNumber << " has started with " << numberOfEnemies << " number of enemies!!" << endl;

        for (auto& enemy : enemies){
            if (player.GetPlayerHealthValue() <= 0){
                cout << "Player has died. Game Over!!" << endl;
                return false;
            }
            cout << "Enemy has appeared!" << endl;
            gameLoop(player, enemy);
        }

        cout << "Level Cleared!!" << endl;
        return true;
    }

private:
    int numberOfEnemies;
    vector<Enemy> enemies;
};

class FinalBossLevel
{
public:
    FinalBossLevel() : boss(200, 50, 30) {}

    bool runLevel(Player &player){
        cout << "Monster Murlocs has appeared!!" << endl;
        gameLoop(player, boss);
        
        if(player.GetPlayerHealthValue() <= 0){
            cout << "Player has died. Game Over!!" << endl;
            return false;
        }
        cout << "Congratulations! You defeated Murlocs and completed the game!" << endl;
        return true;

    }

private:
    Enemy boss;
};

void gameLoop(Player &player, Enemy &enemy){
    
    char playerChoice;
    
    do{
        cout << "Press 'A' to attack or 'H' to heal" << endl;
        cin >> playerChoice;
        cout << endl;

        if(playerChoice == 'a' || playerChoice == 'A'){
            enemy.EnemyTakeDamage(player.PlayerAttack());
            
            if(enemy.GetEnemyHealth() > 0){
                player.PlayerTakeDamage(enemy.EnemyAttack());
            }
            cout << endl;

        } else if(playerChoice == 'h' || playerChoice == 'H'){
            player.Heal();
            
            if(enemy.GetEnemyHealth() > 0){
                player.PlayerTakeDamage(enemy.EnemyAttack());
            }
            cout << endl;

        } else {
            cout << "Invalid input!!" << endl;
        }

    } while (player.GetPlayerHealthValue() > 0 && enemy.GetEnemyHealth() > 0);
    
}

template<int levelNumber>
void RunLevel(Player& player){
    Level<levelNumber> level;
    bool gameRunning = level.runLevel(player);
    if(gameRunning){
        player.LevelUp();

        if constexpr(levelNumber == 2){
            player.hasCriticalHitAbility = true;
            player.SpecialAbility("Critical Hit");
            player.SpecialItem("Sword");
        }

        if constexpr(levelNumber == 3){
            player.SpecialAbility("Blocker");
            player.SpecialItem("Shield");
            player.ActivateBlocker();
        }

        if constexpr(levelNumber == 4){
            player.SpecialAbility("Life steal");
            player.SpecialItem("Armour");
        }

        if constexpr(levelNumber == 5){
            player.SpecialAbility("Ranged Attack");
            player.SpecialItem("Bow");
        }

    }

}

int main()
{
    cout << "Once there was a village named Eldergrove. The village was peaceful and villagers were happy. Suddenly a Monster named Murlocs appeared.He captured the village and imprisoned the villagers. Now to defeat the monster and free the village a hero, named Ben appeared and started his quest!!" << endl;
    cout << endl;

    char userInput;
    do{
        cout << "Press S to start the game or any other key to exit!!" << endl;
        cin >> userInput;
        cout << endl;

        if(userInput == 'S' || userInput == 's'){
            Player player;
            player.PrintPlayerStats();
            
            if (player.GetPlayerHealthValue() > 0){
                RunLevel<1>(player);
            }

            // player.PrintPlayerStats();

            if (player.GetPlayerHealthValue() > 0){
                RunLevel<2>(player);
            }

            if (player.GetPlayerHealthValue() > 0){
                RunLevel<3>(player);
            }

            if (player.GetPlayerHealthValue() > 0){
                RunLevel<4>(player);
            }

            if (player.GetPlayerHealthValue() > 0){
                RunLevel<5>(player);
            }

            if (player.GetPlayerHealthValue() > 0){
                FinalBossLevel finalBoss;
                finalBoss.runLevel(player);
            }
            
        } else{
            cout << "Thanks for playing!!" << endl;
        }
    } while(userInput == 'S' || userInput == 's');
   

    return 0;
}