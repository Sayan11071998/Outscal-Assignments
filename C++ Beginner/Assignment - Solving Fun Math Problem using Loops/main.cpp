#include <iostream>

using namespace std;

int Sum(int n){
    int sum = 0;
    for (size_t i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

int main ()
{
    int n;

    cout << "Please provide us a pisitive integer number n: ";
    cin >> n;

    cout << Sum(n);

    return 0;
}