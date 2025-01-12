#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void countSort(int arr[], int n, int exponent)
{
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exponent) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) { count[i] += count[i - 1]; }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exponent) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) { arr[i] = output[i]; }
}

void radixSort(int arr[], int n)
{
    int maxElement = *max_element(arr, arr + n);

    for (int exponent = 1; maxElement / exponent > 0; exponent *= 10) { countSort(arr, n, exponent); }
}

void handleNegativeNumbers(int arr[], int n)
{
    int minElement = *min_element(arr, arr + n);

    if (minElement < 0)
    {
        for (int i = 0; i < n; i++)
            arr[i] -= minElement;
    }
}

void restoreNegativeNumbers(int arr[], int n, int minElement)
{
    if (minElement < 0)
    {
        for (int i = 0; i < n; i++)
            arr[i] += minElement;
    }
}

void processRadixSort(int arr[], int n)
{
    int minElement = *min_element(arr, arr + n);
    
    handleNegativeNumbers(arr, n);
    radixSort(arr, n);
    restoreNegativeNumbers(arr, n, minElement);
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void fillDynamicArrayWithRandomValues(int** arr, int* n)
{
    cout << "Enter the size of the array: ";
    cin >> *n;
    *arr = new int[*n];
    srand(time(0));
    for (int i = 0; i < *n; i++)
        (*arr)[i] = rand() % 2001 - 1000;
}

int main()
{
    int* arr;
    int n;
    
    fillDynamicArrayWithRandomValues(&arr, &n);
    cout << "Unsorted array: ";
    displayArray(arr, n);
    
    processRadixSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    
    delete[] arr;
    
    return 0;
}