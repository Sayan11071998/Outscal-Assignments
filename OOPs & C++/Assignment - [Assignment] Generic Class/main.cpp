#include <iostream>
using namespace std;

template <typename T>
class SpecialAbility
{
public:
    SpecialAbility(T _attackStrength) : attackStrength(_attackStrength) {}
    
    ~SpecialAbility() {}

    T performSpecialAbility() const{
        return attackStrength;
    }

private:
    T attackStrength;
};


int main()
{
    int specialAbilityAttackStrength_1;
    cout << "Please provide attack strength <int> : ";
    cin >> specialAbilityAttackStrength_1;
    SpecialAbility<int>* specialAbility_1 = new SpecialAbility<int>(specialAbilityAttackStrength_1);
    cout << "Our hero has performed his special ability attack and has performed a damage <int> of : " << specialAbility_1->performSpecialAbility() << endl;

    float specialAbilityAttackStrength_2;
    cout << "Please provide attack strength <float> : ";
    cin >> specialAbilityAttackStrength_2;
    SpecialAbility<float>* specialAbility_2 = new SpecialAbility<float>(specialAbilityAttackStrength_2);
    cout << "Our hero has performed his special ability attack and has performed a damage <float> of : " << specialAbility_2->performSpecialAbility() << endl;

    delete specialAbility_1;
    delete specialAbility_2;

    return 0;
}