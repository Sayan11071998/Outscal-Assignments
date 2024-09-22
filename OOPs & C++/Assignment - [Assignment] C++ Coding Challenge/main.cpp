#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void GenerateRandomString(){
    srand(time(0));
    
    int minRandomStringLength = 1;
    int maxRandomStringLength = 8;
    int stringLength = minRandomStringLength + (rand() % (maxRandomStringLength - minRandomStringLength + 1));

    char randomString[stringLength + 1];
    for(int i = 0; i < stringLength; i++){
        if(rand() % 2 == 0){
            randomString[i] = 'R';
        } else{
            randomString[i] = 'B';
        }
    }

    randomString[stringLength] = '\0';
    std::cout << "Random String: " << randomString << std::endl;

    int totalScore = 0;
    int consecutiveNumberCount = 0;
     char lastChar = '\0';

    for (int i = 0; i < stringLength; i++){
        if(randomString[i] == 'R'){
            consecutiveNumberCount++;
            totalScore += 10 * consecutiveNumberCount;
            lastChar = 'R';
        }else if(randomString[i] == 'B'){
            consecutiveNumberCount = 0; 
            totalScore += 20;
            if(lastChar == 'B'){
                totalScore += 20 * (consecutiveNumberCount + 1);
                consecutiveNumberCount++;
            } else {
                consecutiveNumberCount = 1;
            }
            lastChar = 'B';
        }
    }

    cout << "Total Score is : " << totalScore << endl;;
 
}

int main()
{
    GenerateRandomString();

    return 0;
}
