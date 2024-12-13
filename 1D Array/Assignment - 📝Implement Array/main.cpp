#include <iostream>

int main()
{
    const int size = 15;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            arr[i] = 2 * i;
        else
            arr[i] = 3 * i;
    }

    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";

    return 0;
}
