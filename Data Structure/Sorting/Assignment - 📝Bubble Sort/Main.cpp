#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void processBubbleSort(int arr[], int n)
{
    bool bIsSwapped;

    for (int i = 0; i < n - 1; i++)
    {
        bIsSwapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                bIsSwapped = true;
            }
        }

        if (!bIsSwapped) break;
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) { cout << arr[i] << " "; }

    cout << endl;
}

void fillDynamicArrayWithRandomValues(int** arr, int* n)
{
    cout << "Enter the size of the array: ";
    cin >> *n;
    *arr = new int[*n];
    srand(time(0));
    for (int i = 0; i < *n; i++) { (*arr)[i] = rand() % 1000; }
}

int main()
{
    int* arr;
    int n;

    fillDynamicArrayWithRandomValues(&arr, &n);
    
    cout << "Unsorted array: ";
    displayArray(arr, n);
    
    processBubbleSort(arr, n);
    
    cout << "Sorted array: ";
    displayArray(arr, n);
    
    delete[] arr;
    
    return 0;
}