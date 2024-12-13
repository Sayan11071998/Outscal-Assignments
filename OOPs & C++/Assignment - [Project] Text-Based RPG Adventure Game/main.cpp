#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

// Forward Declaring Player & Enemy Class
class Player;
class Enemy;

// Forward Declaring 10% Chance Condition for Special Abilities
bool IsAbilityTriggered(int chance);

// Forward Declaring Random Number Calculation Function
int CalculateRandomNumber(int FirstNumber, int SecondNumber);

// Forward Declaring Game Loop Function
void gameLoop(Player &player, Enemy &enemy);

// Interface for Player Class
class IPlayer
{
public:
    virtual void SpecialAbility(const std::string& ability) = 0;
    virtual void SpecialItem(const std::string& item) = 0;
    virtual void LevelUp(int levelNumber) = 0;
    virtual void PrintPlayerStats() = 0;
    virtual int PlayerMeleeAttack() = 0;
    virtual int PlayerRangedAttack() = 0;
    virtual int CriticalHitSpecialAbility(int damage) = 0;
    virtual bool BlockerSpecialAbility() = 0;
    virtual void LifeStealSpecialAbility(int damageDealt) = 0;
    virtual void ActivateRangedAttackImmunity() = 0;
    virtual void DeactivateRangedAttackImmunity() = 0;
    virtual int RangedAttackSpecialAbility() = 0;
    virtual int PlayerAttack() = 0;
    virtual void Heal() = 0;
    virtual int GetPlayerHealthValue() const = 0;
    virtual void PlayerTakeDamage(int damage) = 0;
    virtual bool HasAllSpecialItems() const = 0;
};

// Interface for Enemy Class
class IEnemy
{
public:
    virtual int EnemyAttack() = 0;
    virtual void EnemyTakeDamage(int damage) = 0;
};

// Player Class
class Player : public IPlayer
{
public:
    // Player Constructor
    Player()
        : health(100), maxMeleeDamage(30), minMeleeDamage(10), meleeDamage(15), maxRangedDamage(25), minRangedDamage(5), rangedDamage(10), defence(50), specialAbilities({""}), specialItems({""}), hasCriticalHitAbility(false), IsBlockerActive(false), HasLifeStealAbility(false), HasRangedAttackImmunity(false) {}

    // Declaring the Friend Class to Access and Modify Private & Protected Members
    template <int levelNumber>
    friend void RunLevel(Player&);

    // Player Attributes Getters
    void GetHealth() const{ cout << "Health: " << health << endl; } // Health Getter
    void GetMeleeDamage() const{ cout << "Melee Damage: " << meleeDamage << endl; } // Melle Damage Value Getter
    void GetRangedDamage() const{ cout << "Ranged Damage: " << rangedDamage << endl; } // Range Damage Value Getter
    void GetDefence() const{ cout << "Defence: " << defence << endl; } // Defense Value Getter
    void GetSpecialAbilities() const{ // Special Abilities Getter
        cout << "Special Abilities: ";
        if(specialAbilities.empty()){ cout << "None";}
        else{
            for(int i = 0; i < specialAbilities.size(); i++){
                if(i > 0){ cout << ", "; }
                cout << specialAbilities[i];
            }
        }
        cout << endl;
    }
    void GetSpecialItems() const{ // Special Items Getter
        cout << "Special Items: ";
        if(specialItems.empty()){ cout << "None"; }
        else{
            for(int i = 0; i < specialItems.size(); i++){
                if(i > 0){ cout << ", "; }
                cout << specialItems[i];
            }
        }
        cout << endl;
    }
   
    // Adding New Special Abilities to Player After Level up
    void SpecialAbility(const std::string& ability) override{
        specialAbilities.push_back(ability);
        cout << "Player has gained new special Ability: " << ability << endl;
    }
   
    // Adding New Special Items to Player After Level up
    void SpecialItem(const std::string& item) override{
        specialItems.push_back(item);
        cout << "Player has gained new special Item: " << item << endl;
        cout << endl;
        PrintPlayerStats();
    }
   
    // Implementing the Logic for Player Level Up, Once Player Completes a Level
    void LevelUp(int levelNumber) override{
        health = 100 + (20 * (levelNumber));
        maxMeleeDamage += 10;
        minMeleeDamage += 10;
        meleeDamage += 10;
        maxRangedDamage += 10;
        minRangedDamage += 10;
        rangedDamage += 10;
        defence = 50 + (20 * (levelNumber));
        cout << "Hurrah!! Player has Powered up!!" << endl;
        cout << endl;
    }

    // Printing Player Stats
    void PrintPlayerStats() override{
        cout << "*** Player's Stats ***" << endl;
        GetHealth();
        GetMeleeDamage();
        GetRangedDamage();
        GetDefence();
        GetSpecialAbilities();
        GetSpecialItems();
        cout << endl;
    }
   
    // Implementing Melle Attack Method
    int PlayerMeleeAttack() override{
        meleeDamage = CalculateRandomNumber(maxMeleeDamage, minMeleeDamage);
        cout << "Player attacked Enemy with melee damage of " << meleeDamage << endl;
        return meleeDamage;
    }
   
    // Implementing Ranged Attack Method
    int PlayerRangedAttack() override{
        rangedDamage = CalculateRandomNumber(maxRangedDamage, minRangedDamage);
        cout << "Player attacked Enemy with ranged damage of " << rangedDamage << endl;
        return rangedDamage;
    }

    // Implementing Critical Hit Special Ability
    int CriticalHitSpecialAbility(int damage) override{
        if(hasCriticalHitAbility && IsAbilityTriggered(10)){
            cout << "Critical Hit with Melee! Damage is doubled!" << endl;
            damage *= 2;
        }
        return damage;
    }
   
    // Implementing Blocker Special Ability
    bool BlockerSpecialAbility() override{
        if(IsBlockerActive && IsAbilityTriggered(10)){
            cout << "Blocker ability active!! No damage taken by the player" << endl;
            return true;
        }
        return false;
    }

    // Implementing Life Steal Special Ability
    void LifeStealSpecialAbility(int damageDealt) override{
        if(HasLifeStealAbility && IsAbilityTriggered(10)){
            int lifeStealAmount = damageDealt * 0.2;  // The player will steal 20% of the damage done by the enemy from the enemy's health
            health += lifeStealAmount;
            cout << "Life Steal activated!! Player recovers " << lifeStealAmount << " HP." << endl;
        }
    }
   
    // Implementing Ranged Attack Special Ability
    // Activating Ranged Attack Special Ability Condition
    void ActivateRangedAttackImmunity() override{
        HasRangedAttackImmunity = true;
        cout << "Ranged Attack Immunity activated!! No damage from the next enemy attack." << endl;
    }
    // Deactivating Ranged Attack Special Ability Condition
    void DeactivateRangedAttackImmunity() override{
        HasRangedAttackImmunity = false;
        cout << "Ranged Attack Immunity deactivated!!" << endl;
    }
    // Checking the Ranged Attack Conditions and Implementing the Ranged Attack
    int RangedAttackSpecialAbility() override{
        rangedDamage = CalculateRandomNumber(maxRangedDamage, minRangedDamage);
        cout << "Player attacks with ranged damage of " << rangedDamage << endl;
        // Activate immunity after a ranged attack with 10% probability
        if (IsAbilityTriggered(10)){ ActivateRangedAttackImmunity(); }
        return rangedDamage;
    }
   
    // Implementing the Player's Main Attack Function
    int PlayerAttack() override{
        // Making Player's Normal Attack Random Between Melle and Ranged Attack
        int randomNumber = rand() % 2;
        int damage = (randomNumber == 0) ? PlayerMeleeAttack() : PlayerRangedAttack();
       
        // Calling Critical Hit Special Ability
        damage = CriticalHitSpecialAbility(damage);
       
        // Calling Life Steal Special Ability
        LifeStealSpecialAbility(damage);

        return damage;
    }

    // Implementing the Player's Heal Function
    void Heal() override{
        int maxHealValue = 30;
        int minHealValue = 10;
        // Randomizing Heal Amount
        int healAmount = CalculateRandomNumber(maxHealValue, minHealValue);
        health += healAmount;
        cout << "Player heals and now has health of " << health << endl;
    }
   
    // Get Player Health
    int GetPlayerHealthValue() const override{ return health; }
   
    // Implementing the Player's Take Damage Function
    void PlayerTakeDamage(int damage) override{
        // Checking If the Player is Alive
        if(health <= 0) return;
       
        // Checking If the Ranged Damage Special Ability is Active
        if (HasRangedAttackImmunity){
            cout << "Ranged Attack Immunity active! No damage taken by the player!!" << endl;
            DeactivateRangedAttackImmunity(); // Deactivating immunity After Blocking One Attack
            return;
        }
       
        // Calling Blocker Special Ability
        if(BlockerSpecialAbility()) return;
       
        // Reducing Health After Receiving Damage
        int TotalDamage = damage;
        int DamageDistribution = static_cast<int>(TotalDamage / 2);
        // Distributing the Damage Between the Health and Defense
        health -= DamageDistribution;
        defence = max(0, defence - (TotalDamage - DamageDistribution));
        // Notifying If Player Died
        if(health <= 0 ){
            cout << "Player Died!!" << endl;
        } else{
            cout << "Player health is: " << health << endl;
            cout << "Player defense is: " << defence << endl;
        }
    }
   
    // Checking If Player Class Has All Four Special Items to Get into the Final Boss Level
    bool HasAllSpecialItems() const override{
        return (find(specialItems.begin(), specialItems.end(), string("Sword")) != specialItems.end() &&
                find(specialItems.begin(), specialItems.end(), string("Shield")) != specialItems.end() &&
                find(specialItems.begin(), specialItems.end(), string("Armour")) != specialItems.end() &&
                find(specialItems.begin(), specialItems.end(), string("Bow")) != specialItems.end());
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
    bool hasCriticalHitAbility;
    bool IsBlockerActive;
    bool HasLifeStealAbility;
    bool HasRangedAttackImmunity;
};

// Enemy Class
class Enemy : public IEnemy
{
public:
    // Enemy Constructor
    Enemy(int _health, int _maxAttackDamage, int _minAttackDamage) : health(_health), maxAttackDamage(_maxAttackDamage), minAttackDamage(_minAttackDamage) {}
   
    // Enemy Attributes Getters
    int GetEnemyHealth() const { return health; }
    int GetMaxAttackDamage() const{ return maxAttackDamage; }
    int GetMinAttackDamage() const{ return minAttackDamage; }
   
    // Enemy Main Attack Function
    int EnemyAttack() override{
        int attackDamage = CalculateRandomNumber(maxAttackDamage, minAttackDamage);
        cout << "Enemy attacks with damage of " << attackDamage << endl;
        return attackDamage;
    }
   
    // Setting Condition for Final Boss Health Regeneration Special Ability
    bool HealthRegenerationAbility = false;
   
    // Implementing Final Boss Health Regeneration Special Ability
    void HealthRegeneration(){
        HealthRegenerationAbility = true;
        int maxHealthIncreseValue = 50;
        int minHealthIncreseValue = 30;
        int randomHealthIncreseValue = CalculateRandomNumber(maxHealthIncreseValue, minHealthIncreseValue);
        health = health + randomHealthIncreseValue;
        cout <<  "Morlocs current health " << health << endl;
    }
   
    // Implementing Enemy's Take Damage Function
    void EnemyTakeDamage(int damage) override{
        // Checking if Enemy is Alive
        if(health <= 0) return;
       
        // reducing Health After Receiving Damage
        health -= damage;
       
        // Printing Enemy Died
        if(health <= 0 )
            cout << "Enemy has been Defeated!!" << endl;
        else
            cout << "Enemy health is: " << health << endl;
    }

private:
    int health;
    int maxAttackDamage;
    int minAttackDamage;
};

// Final Boss Class
class FinalBoss : public Enemy
{
public:
    // Final Boss Constructor
    FinalBoss() : Enemy(500, 50, 30) {}
   
    // Enemy Attack Override for Final Boss
    int EnemyAttack() override{
        int action = rand() % 5;
        int attackDamage = 0;
        switch(action)
        {
            case 0: // Final Boss Normal Attack
                attackDamage = CalculateRandomNumber(GetMaxAttackDamage(), GetMinAttackDamage());
                cout << "Murlocs attacks with damage of " << attackDamage << endl;
                return attackDamage;
           
            case 1: // Final Boss Defence
                cout << "Murlocs is defending! Blocked incoming attack!!" << endl;
                return 0;
           
            case 2: // Final Boss Ground Slash Special Ability
                attackDamage = CalculateRandomNumber(GetMaxAttackDamage(), GetMinAttackDamage());
                cout << "Murlocs used special ability Ground Slash with the damage of " << (attackDamage * 2) << endl;
                return attackDamage * 2;
           
            case 3: // Final Boss Speed Dash Special Ability
                cout << "Murlocs used special ability Speed Dash to avoid the player attack!!" << endl;
                return 0;
           
            case 4: // Final Boss Health Regeneration Special Ability
                cout << "Murlocs used special ability Health Regeneration!!" << endl;
                HealthRegeneration();
                return 0;
           
            default:
                return 0;
        }
    }

};

// Template Class For Game Levels
template <int levelNumber>
class Level
{
public:
    // Level Constructor
    Level(){
        numberOfEnemies = levelNumber;
        int enemyHealth = baseEnemyHealth + (levelNumber * 5); // Increasing Enemy Health with Levels
        int maxEnemyAttackDamage = baseMaxEnemyDamage + (levelNumber * 3); // Increasing Enemy Max Damage with Levels
        int minEnemyAttackDamage = baseMinEnemyDamage + (levelNumber * 3); // Increasing Enemy Min Damage with Levels
        for(int i = 0; i < numberOfEnemies; i++){ // Increasing Number of Enemies with increment of Levels
            enemies.push_back(Enemy(enemyHealth, maxEnemyAttackDamage, minEnemyAttackDamage));
        }
    }
   
    // Calling Run Level Class to Start the Level
    bool runLevel(Player &player){
        cout << "Level " << levelNumber << " has started with " << numberOfEnemies << " number of enemies!!" << endl;
       
        for (auto& enemy : enemies){ // Checking If Our Player is Alive
            if (player.GetPlayerHealthValue() <= 0){
                cout << "Player has died!! Game Over!!" << endl;
                return false;
            }
           
            cout << "New Enemy has appeared!!" << endl;
           
            // Starting the Game Loop
            gameLoop(player, enemy);
        }
        cout << "Congrats!! Level Cleared!! Proceed to the next level!!" << endl;
        return true;
    }

private:
    int numberOfEnemies;
    int baseEnemyHealth = 50;
    int baseMaxEnemyDamage = 20;
    int baseMinEnemyDamage = 5;
    vector<Enemy> enemies;
};

// Final Boss Class
class FinalBossLevel
{
public:
    // calling the Base Enemy Class to Construct the Final Boss Object
    FinalBossLevel() : boss() {}
   
    // Calling Run Level Class to Start the Level
    bool runLevel(Player &player){
        cout << "Monster Murlocs has appeared!!" << endl;
       
        // Calling Game Loop
        gameLoop(player, boss);
       
        // Checking if Player is Alive
        if(player.GetPlayerHealthValue() <= 0){
            cout << "Player has died!! Game Over!!" << endl;
            return false;
        }
        cout << "Congratulations! You defeated Murlocs and completed the game!" << endl;
        return true;
    }

private:
    FinalBoss boss;
};

// Implementing 10% Chance Condition for Special Abilities
bool IsAbilityTriggered(int chance){
    return (rand() % 100) < chance;
}

// Function to Calculate a Random Between Two Numbers
int CalculateRandomNumber(int FirstNumber, int SecondNumber){
    int randomNumber = 0;
    if(FirstNumber > SecondNumber){
        randomNumber = (rand() % (FirstNumber - SecondNumber + 1) + SecondNumber);
    } else{
        randomNumber = (rand() % (SecondNumber - FirstNumber + 1) + FirstNumber);
    }
    return randomNumber;    
}

// Implementing Game Loop unction
void gameLoop(Player &player, Enemy &enemy){
    char playerChoice;
   
    // Taking User Input for Either Attack/Heal
    do{
        cout << "Press 'A' to attack or 'H' to heal" << endl;
        cin >> playerChoice;
        cout << endl;
       
        if(playerChoice == 'a' || playerChoice == 'A'){
            int damageDealt = player.PlayerAttack();
            int enemyDamage = enemy.EnemyAttack();
           
            // Applying Damage to Enemy
            if(enemyDamage > 0){
                enemy.EnemyTakeDamage(damageDealt);
            }
           
            if(enemy.GetEnemyHealth() > 0){ // Checking For Enemy Death Condition
                if (enemyDamage > 0){ // Applying Damage to Player
                    player.PlayerTakeDamage(enemyDamage);
                } else{
                    cout << "Player takes no damage!!" << endl;
                }
            }
            cout << endl;
        } else if(playerChoice == 'h' || playerChoice == 'H'){
            player.Heal(); // Heal Player
            if(enemy.GetEnemyHealth() > 0){ // Checking For Enemy Death Condition
                int enemyDamage = enemy.EnemyAttack();
                if (enemyDamage > 0){
                    player.PlayerTakeDamage(enemyDamage);
                } else{
                    cout << "Player takes no damage!!" << endl;
                }
            }
            cout << endl;
        } else{
            cout << "Invalid input!!" << endl;
        }
    } while(player.GetPlayerHealthValue() > 0 && enemy.GetEnemyHealth() > 0);
}

// Implementing Run Level to Continue through the Level
template<int levelNumber>
void RunLevel(Player& player){
    // Setting Level Number
    Level<levelNumber> level;
   
    // Setting Game Continuation Condition
    bool gameRunning = level.runLevel(player);
   
    if(gameRunning){
        // Leveling Up the Player
        player.LevelUp(levelNumber);
       
        // Initializing Level 2
        if constexpr(levelNumber == 2){
            player.SpecialAbility("Critical Hit");
            player.SpecialItem("Sword");
            player.hasCriticalHitAbility = true;
            cout << "Critical Hit ability Got Unlocked!!" << endl;
            cout << endl;
        }
       
        // Initializing Level 3
        if constexpr(levelNumber == 3){
            player.SpecialAbility("Blocker");
            player.SpecialItem("Shield");
            player.IsBlockerActive = true;
            cout << "Blocker ability activated!!" << endl;
            cout << endl;
        }
       
        // Initializing Level 4
        if constexpr(levelNumber == 4){
            player.SpecialAbility("Life steal");
            player.SpecialItem("Armour");
            player.HasLifeStealAbility = true;
            cout << "Life Steal ability activated!!" << endl;
            cout << endl;
        }
       
        // Initializing Level 5
        if constexpr(levelNumber == 5){
            player.SpecialAbility("Ranged Attack");
            player.SpecialItem("Bow");
            cout << "Ranged Attack Immunity unlocked!" << endl;
            cout << endl;
        }
    }
}

int main()
{
    // Seeding the Time
    srand(time(0));
   
    // Stating Game Story
    cout << "Once there was a village named Eldergrove. The village was peaceful and villagers were happy. Suddenly a Monster named Murlocs appeared.He captured the village and imprisoned the villagers. Now to defeat the monster and free the village a hero, named Ben appeared and started his quest!!" << endl;
    cout << endl;
   
    // Taking User Input to Start The Game
    char userInput;
    do{
        cout << "Press S to start the game or any other key to exit!!" << endl;
        cin >> userInput;
        cout << endl;

        if(userInput == 'S' || userInput == 's'){
            Player player; // Creating Player Object
            player.PrintPlayerStats(); // Printing Player Stats
           
            // Starting Level 1
            if (player.GetPlayerHealthValue() > 0){
                RunLevel<1>(player);
                player.PrintPlayerStats();
            }
           
            // Starting Level 2
            if (player.GetPlayerHealthValue() > 0){
                RunLevel<2>(player);
            }
           
            // Starting Level 3
            if (player.GetPlayerHealthValue() > 0){
                RunLevel<3>(player);
            }
           
            // Starting Level 4
            if (player.GetPlayerHealthValue() > 0){
                RunLevel<4>(player);
            }
           
            // Starting Level 5
            if (player.GetPlayerHealthValue() > 0){
                RunLevel<5>(player);
            }
           
            // Starting Level 6, i.e. Final Level
            if (player.GetPlayerHealthValue() > 0){
                if(player.HasAllSpecialItems()){ // Checking If Player Has All The Special Items Required
                    FinalBossLevel finalBoss;
                    finalBoss.runLevel(player);
                } else{
                    cout << "You need to collect all special items to face the boss!" << endl;
                }
            }
        } else{
            cout << "Thanks for playing!!" << endl; // Ending The Game
        }
    } while(userInput == 'S' || userInput == 's');
   

    return 0;
}