#include <iostream>
#include <vector>

int main()
{
    int N;

    std::cout << "Enter the size of the array (N): ";
    std::cin >> N;

    if (N <= 0)
    {
        std::cout << "Invalid size! Exiting program.";
        return 1;
    }

    std::vector<int> arr(N);

    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];

    std::cout << "Indices of peak elements: ";

    for (int i = 0; i < N; i++)
    {
        if ((i == 0 || arr[i] >= arr[i - 1]) && (i == N - 1 || arr[i] >= arr[i + 1]))
            std::cout << i << " ";
    }

    return 0;
}
