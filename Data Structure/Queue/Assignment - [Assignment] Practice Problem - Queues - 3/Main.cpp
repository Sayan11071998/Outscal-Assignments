/*
Problem Statement -
There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.
You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].
Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.
Return the time taken for the person at position k (0-indexed) to finish buying tickets.


Example 1:

Input - tickets = [2,3,2], k = 2
Output - ans = 6
Explanation -
In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1] Time passed in the first pass = 3
In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0] Time passed till now = 6. And since person at position 2 has no tickets to buy now
Therefore the answer is 6


Example 2:

Input - tickets = [5,1,1,1], k = 0
Output - ans = 8
Explanation -
In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0] Time passed till here is 4.
In the next 4 passes, only the person in position 0 is buying tickets because all other people have already bought their required number of tickets.
The person at position 0 has successfully bought 5 tickets it took him 4 + 1 + 1 + 1 + 1 = 8 seconds


Constraints -
n == tickets.length
1 <= n <= 100
1 <= tickets[i] <= 100
0 <= k < n
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int timeToBuyTickets(vector<int>& tickets, int k)
{
    queue<pair<int, int>> q;
    int time = 0;

    for (int i = 0; i < tickets.size(); ++i) { q.push({ i, tickets[i] }); }

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        current.second -= 1;
        time += 1;

        if (current.second == 0)
        {
            if (current.first == k) return time;
        }
        else
        {
            q.push(current);
        }
    }

    return time;
}

int main()
{
    vector<int> tickets = { 5, 1, 1, 1 };
    int k = 0;

    int result = timeToBuyTickets(tickets, k);
    cout << "The time taken for person at position " << k << " to finish buying tickets is: " << result << " seconds." << endl;

    return 0;
}
