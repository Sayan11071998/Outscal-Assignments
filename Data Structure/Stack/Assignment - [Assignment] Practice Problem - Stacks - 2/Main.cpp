/*
Problem Statement:

Given an array of integers temperatures represents the daily temperatures. Your task is to find number of days you have to wait to get a warmer temperature after the current day for each index i that is 0 ≤ i < temperatures.length
Return an array ans of size temperatures.length such that ans[i] represents waiting time for each day as explained above


Example 1:
Input - temperatures = [73,74,75,71,69,72,76,73]
Output - ans = [1,1,4,2,1,1,0,0]


Explanation -
The number of waiting days for each day is as follows:
For index 0, Temperature is 73. The next warmer day for this day is at index 1 where the temperature is 74. So ans[0] = 1 - 0
For index 1, next warmer day is present at index 2. Hence ans[1] = 2 - 1
For index 2 with temperature 75, next greater temperature comes at index 6 which is 76. So ans[2] = 6 - 2 = 4. That’s how for all other indexes ans[i] has been calculated.


Constraints:
1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(const vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> s;

    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && temperatures[i] > temperatures[s.top()])
        {
            int prevIndex = s.top();
            s.pop();
            ans[prevIndex] = i - prevIndex;
        }

        s.push(i);
    }

    return ans;
}

int main()
{
    vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> ans = dailyTemperatures(temperatures);

    for (int days : ans)
        cout << days << " ";
    cout << endl;

    return 0;
}
