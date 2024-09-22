#include <iostream>
using namespace std;

template <typename T>
T GenericSum(T CurrentScore, T ScoreToBeAdded){
    return CurrentScore + ScoreToBeAdded;
}


int main()
{
    int CurrentScore_1;
    int ScoreToBeAdded_1;
    cout << "Please provide the Current Score : ";
    cin >> CurrentScore_1;
    cout << "Please provide the score to be added : ";
    cin >> ScoreToBeAdded_1;
    cout << "Total Score first case : " << GenericSum(CurrentScore_1, ScoreToBeAdded_1) << endl;;

    float CurrentScore_2;
    float ScoreToBeAdded_2;
    cout << "Please provide the Current Score : ";
    cin >> CurrentScore_2;
    cout << "Please provide the score to be added : ";
    cin >> ScoreToBeAdded_2;
    cout << "Total Score first case : " << GenericSum(CurrentScore_2, ScoreToBeAdded_2) << endl;

    return 0;
}