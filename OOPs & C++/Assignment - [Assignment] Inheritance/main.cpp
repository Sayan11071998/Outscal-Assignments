#include <iostream>
using namespace std;

// Enemy Class
class Enemy
{
public:
    Enemy(int Health, int AttackPower, int AttackRange, int XP, int Level)
        : health(Health), attackPower(AttackPower), attackRange(AttackRange), XP(XP), Level(Level) {}
    
    // Getter
    int GetHealth() const{
        return health;
    }
    int GetAttackPower() const{
        return attackPower;
    }
    int GetAttackRange() const{
        return attackRange;
    }
    int GetXP() const{
        return XP;
    }
    int GetLevel() const{
        return Level;
    }

    // Setter
    void SetHealth(int HealthValue){
        health = HealthValue;
    }
    void SetAttackPower(int AttackPowerValue){
        attackPower = AttackPowerValue;
    }
    void SetAttackRange(int AttackRangeValue){
        attackRange = AttackRangeValue;
    }
    void SetXP(int XPValue){
        XP = XPValue;
    }
    void SetLevel(int LevelValue){
        Level = LevelValue;
    }

private:
    int health;
    int attackPower;
    int attackRange;
    int XP;
    int Level;
};

// Flying Enemy Class 
class FlyingEnemy : public Enemy
{
public:
    FlyingEnemy(int Health, int AttackPower, int AttackRange, int XP, int Level, int FlyingRadius, int FlyingSpeed, int WindAttackPower, int LazerAttackPower, int SpikeAttackPower)
        : Enemy(Health, AttackPower, AttackRange, XP, Level), flyingRadius(FlyingRadius), flyingSpeed(FlyingSpeed), windAttackPower(WindAttackPower), lazerAttackPower(LazerAttackPower), spikeAttackPower(SpikeAttackPower) {}
    
    // Getter
    int GetFlyingRadius() const{
        return flyingRadius;
    }
    int GetFlyingSpeed() const{
        return flyingSpeed;
    }
    int GetWindAttackPower() const{
        return windAttackPower;
    }
    int GetLazerAttackPower() const{
        return lazerAttackPower;
    }
    int GetSpikeAttackPower() const{
        return spikeAttackPower;
    }

    // Setter
    void SetFlyingRadius(int FlyingRadiusValue){
        flyingRadius = FlyingRadiusValue;
    }
    void SetFlyingSpeed(int FlyingSpeedValue){
        flyingSpeed = FlyingSpeedValue;
    }
    void SetWindAttackPower(int WindAttackPowerValue){
        windAttackPower = WindAttackPowerValue;
    }
    void SetLazerAttackPower(int LazerAttackPowerValue){
        lazerAttackPower = LazerAttackPowerValue;
    }
    void SetSpikeAttackPower(int SpikeAttackPowerValue){
        spikeAttackPower = SpikeAttackPowerValue;
    }

    // Member Functions
    void Fly(){
        cout << "Enemy is flying in the sky like an Angle of Death with speed of : " << flyingSpeed << " within the radius of : " << flyingRadius << endl;
    }

    void WindAttack(){
        cout << "Enemy has lanched Wind Attack with power of : " << windAttackPower << endl;
    }

    void LazerAttack(){
        cout << "Enemy has launched Lazer Attack with power of : " << lazerAttackPower<< endl;
    }

    void SpikeAttack(){
        cout << "Enemy has launched Spike Attack with power of : " << spikeAttackPower << endl;
    }

private:
    int flyingRadius;
    int flyingSpeed;
    int windAttackPower;
    int lazerAttackPower;
    int spikeAttackPower;
};

// Ground Enemy
class GroundEnemy : public Enemy
{
public:
    GroundEnemy(int Health, int AttackPower, int AttackRange, int XP, int Level, int PatrollingRadius, int RunningSpeed, int FistAttackPower, int Strength, int FirePower)
        : Enemy(Health, AttackPower, AttackRange, XP, Level), patrollingRadius(PatrollingRadius), runningSpeed(RunningSpeed), fistAttackPower(FistAttackPower), strength(Strength), firePower(FirePower) {}

    // Getter
    int GetPatrollingRadius() const{
        return patrollingRadius;
    }
    int GetRunningSpeed() const{
        return runningSpeed;
    }
    int GetFistAttackPower() const{
        return fistAttackPower;
    }
    int GetStrength() const{
        return strength;
    }
    int GetFirePower() const{
        return firePower;
    }

    // Setter
    void SetPatrollingRadius(int PatrollingRadiusValue){
        patrollingRadius = PatrollingRadiusValue;
    }
    void SetRunningSpeed(int RunningSpeedValue){
        runningSpeed = RunningSpeedValue;
    }
    void SetFistAttackPower(int FistAttackPowerValue){
        fistAttackPower = FistAttackPowerValue;
    }
    void SetStrength(int StrengthValue){
        strength = StrengthValue;
    }
    void SetFirePower(int FirePowerValue){
        firePower = FirePowerValue;
    }

    // Member Functions
    void Dig(){
        cout << "Enemy is digging the ground to go into the ground for hiding" << endl;
    }
    void Patrol(){
        cout << "Enemy is patrolling within a radius of : " << patrollingRadius << endl;
    }
    void Run(){
        cout << "Enemy is running with a speed of : " << runningSpeed << endl;
    }
    void FistAttack(){
        cout << "Enemy has launched Fist Attack with power of : " << fistAttackPower << endl;
    }
    void FireAttack(){
        cout << "Enemy has launched Fire Attack with power of : " << firePower << endl;
    }

private:
    int patrollingRadius;
    int runningSpeed;
    int fistAttackPower;
    int strength;
    int firePower;
};

int main()
{
    // Initializing Enemy
    Enemy enemy(100, 15, 30, 5, 2);
    
    cout << "Enemy stats from constructor :" << endl;
    cout << "---------------------------------" << endl;
    cout << "Health : " << enemy.GetHealth() <<endl;
    cout << "Attack Power : " << enemy.GetAttackPower() << endl;
    cout << "Attack Range : " << enemy.GetAttackRange() << endl;
    cout << "XP : " << enemy.GetXP() << endl;
    cout << "Level : " << enemy.GetLevel() << endl;
    cout << endl;
    
    cout << "Enemy stats after setter :" << endl;
    cout << "---------------------------" << endl;
    enemy.SetHealth(200);
    enemy.SetAttackPower(20);
    enemy.SetAttackRange(25);
    enemy.SetXP(10);
    enemy.SetLevel(5);
    cout << "Health : " << enemy.GetHealth() <<endl;
    cout << "Attack Power : " << enemy.GetAttackPower() << endl;
    cout << "Attack Range : " << enemy.GetAttackRange() << endl;
    cout << "XP : " << enemy.GetXP() << endl;
    cout << "Level : " << enemy.GetLevel() << endl;
    cout << endl;

    // Initializing Flying Enemy
    FlyingEnemy flyingEnemy(120, 20, 60, 10, 5, 200, 700, 50, 40, 30);

    cout << "Flying Enemy stats from constructor :" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Health : " << flyingEnemy.GetHealth() <<endl;
    cout << "Attack Power : " << flyingEnemy.GetAttackPower() << endl;
    cout << "Attack Range : " << flyingEnemy.GetAttackRange() << endl;
    cout << "XP : " << flyingEnemy.GetXP() << endl;
    cout << "Level : " << flyingEnemy.GetLevel() << endl;
    cout << "Flying Radius : " << flyingEnemy.GetFlyingRadius() << endl;
    cout << "Flying Speed : " << flyingEnemy.GetFlyingSpeed() << endl;
    cout << "Wind Attack Power : " << flyingEnemy.GetWindAttackPower() << endl;
    cout << "Lazer Attack Power : " << flyingEnemy.GetLazerAttackPower() << endl;
    cout << "Spike Attack Power : " << flyingEnemy.GetSpikeAttackPower() << endl;
    cout << endl;

    cout << "Flying Enemy stats after setter :" << endl;
    cout << "----------------------------------" << endl;
    flyingEnemy.SetHealth(250);
    flyingEnemy.SetAttackPower(25);
    flyingEnemy.SetAttackRange(40);
    flyingEnemy.SetXP(20);
    flyingEnemy.SetLevel(10);
    flyingEnemy.SetFlyingRadius(400);
    flyingEnemy.SetFlyingSpeed(1500);
    flyingEnemy.SetWindAttackPower(100);
    flyingEnemy.SetLazerAttackPower(80);
    flyingEnemy.SetSpikeAttackPower(40);
    
    cout << "Health : " << enemy.GetHealth() <<endl;
    cout << "Attack Power : " << enemy.GetAttackPower() << endl;
    cout << "Attack Range : " << enemy.GetAttackRange() << endl;
    cout << "XP : " << enemy.GetXP() << endl;
    cout << "Level : " << enemy.GetLevel() << endl;
    cout << "Flying Radius : " << flyingEnemy.GetFlyingRadius() << endl;
    cout << "Flying Speed : " << flyingEnemy.GetFlyingSpeed() << endl;
    cout << "Wind Attack Power : " << flyingEnemy.GetWindAttackPower() << endl;
    cout << "Lazer Attack Power : " << flyingEnemy.GetLazerAttackPower() << endl;
    cout << "Spike Attack Power : " << flyingEnemy.GetSpikeAttackPower() << endl;
    cout << endl;

    cout << "Flying Enemy functions :" << endl;
    cout << "-------------------------" << endl;
    flyingEnemy.Fly();
    flyingEnemy.WindAttack();
    flyingEnemy.LazerAttack();
    flyingEnemy.SpikeAttack();

    // Initializing Ground Enemy
    GroundEnemy groundEnemy(140, 30, 20, 15, 3, 100, 60, 50, 25, 40);
    cout << "Ground Enemy stats from constructor :" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Health : " << groundEnemy.GetHealth() <<endl;
    cout << "Attack Power : " << groundEnemy.GetAttackPower() << endl;
    cout << "Attack Range : " << groundEnemy.GetAttackRange() << endl;
    cout << "XP : " << groundEnemy.GetXP() << endl;
    cout << "Level : " << groundEnemy.GetLevel() << endl;
    cout << "Patrolling Radius : " << groundEnemy.GetPatrollingRadius() << endl;
    cout << "Running Speed : " << groundEnemy.GetRunningSpeed() << endl;
    cout << "Fist Attack Power : " << groundEnemy.GetFistAttackPower() << endl;
    cout << "Strength : " << groundEnemy.GetStrength() << endl;
    cout << "Fire Power : " << groundEnemy.GetFirePower() << endl;
    cout << endl;

    cout << "Ground Enemy stats after setter :" << endl;
    cout << "----------------------------------" << endl;
    groundEnemy.SetHealth(400);
    groundEnemy.SetAttackPower(30);
    groundEnemy.SetAttackRange(50);
    groundEnemy.SetXP(25);
    groundEnemy.SetLevel(15);
    groundEnemy.SetPatrollingRadius(700);
    groundEnemy.SetRunningSpeed(20);
    groundEnemy.SetFistAttackPower(100);
    groundEnemy.SetStrength(200);
    groundEnemy.SetFirePower(50);

    cout << "Ground Enemy stats from constructor :" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Health : " << groundEnemy.GetHealth() <<endl;
    cout << "Attack Power : " << groundEnemy.GetAttackPower() << endl;
    cout << "Attack Range : " << groundEnemy.GetAttackRange() << endl;
    cout << "XP : " << groundEnemy.GetXP() << endl;
    cout << "Level : " << groundEnemy.GetLevel() << endl;
    cout << "Patrolling Radius : " << groundEnemy.GetPatrollingRadius() << endl;
    cout << "Running Speed : " << groundEnemy.GetRunningSpeed() << endl;
    cout << "Fist Attack Power : " << groundEnemy.GetFistAttackPower() << endl;
    cout << "Strength : " << groundEnemy.GetStrength() << endl;
    cout << "Fire Power : " << groundEnemy.GetFirePower() << endl;
    cout << endl;
    
    cout << "Ground Enemy functions :" << endl;
    cout << "-------------------------" << endl;
    groundEnemy.Dig();
    groundEnemy.Patrol();
    groundEnemy.Run();
    groundEnemy.FistAttack();
    groundEnemy.FireAttack();

    return 0;
}