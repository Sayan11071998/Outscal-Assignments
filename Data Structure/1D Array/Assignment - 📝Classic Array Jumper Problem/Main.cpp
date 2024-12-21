#include <iostream>
#include <algorithm>
using namespace std;

int minJumps(int nums[], int n) {
    if (n == 1) return 0;

    int jumps = 0;
    int current_end = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);

        if (i == current_end) {
            jumps++;
            current_end = farthest;

            if (current_end >= n - 1) break;
        }
    }

    return jumps;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 0;
    }

    int* nums = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = minJumps(nums, n);
    cout << "Minimum number of jumps: " << result << endl;

    delete[] nums;
    return 0;
}
