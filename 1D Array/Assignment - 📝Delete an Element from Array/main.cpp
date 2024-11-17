#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int elementToDelete;
    cout << "Enter the integer to be removed: ";
    cin >> elementToDelete;

    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elementToDelete)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;

        cout << "Updated array: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
        cout << "Element not found. No deletion performed." << endl;

    return 0;
}
