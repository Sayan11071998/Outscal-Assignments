/*

Problem Statement -
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
You are given a list of strings of operations named ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

An integer x : Record a new score of x
‘+’ : Record a new score that is sum of the previous 2 scores
‘D’ : Record a new score that is the double of the previous score
‘C’ : Discard the previous score, remove it from the record
Return the sum of all the scores on the record after applying all the operations.


Example 1:
Input - ops = ["5","2","C","D","+"]
Output - ans = 30

Explanation -
"5" : Since it is an integer value, add it to the record, Record = [5]
"2" : Add it to the record, Record = [5, 2]
"C" : Here we have to discard the previous value, so remove 2. Record = [5]
“D” : Add 2*5 to the record, Record = [5, 10]
“+” : Add 5 and 10 i.e. 15, So Record = [5, 10, 15]


Example 2:
Input - ops = ["1","C"]
Output - ans = 0

Explanation -
“1” : Record = [1]
“C” : We need to 1 from the record, so Record = [ ]
Since the Record is empty, total sum is 0


Constraints -
1 <= operations.length <= 1000
ops[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 10^4, 3 * 10^4].
For operation "+", there will always be at least two previous scores on the record.
For operations "C" and "D", there will always be at least one previous score on the record.

*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int basketballScore(const vector<string>& ops)
{
    int totalScore = 0;
    stack<int> record;

    for (const string& op : ops)
    {
        if (op == "C")
        {
            if (!record.empty())
                record.pop();
        }
        else if (op == "D")
        {
            if (!record.empty())
                record.push(2 * record.top());
        }
        else if (op == "+")
        {
            if (record.size() >= 2)
            {
                int top1 = record.top();
                record.pop();
                int top2 = record.top();
                record.push(top1);
                record.push(top1 + top2);
            }
        }
        else
        {
            record.push(stoi(op));
        }
    }

    while (!record.empty())
    {
        totalScore += record.top();
        record.pop();
    }

    return totalScore;
}

int main()
{
    vector<string> ops1 = { "5", "2", "C", "D", "+" };
    cout << "Output 1: " << basketballScore(ops1) << endl;

    vector<string> ops2 = { "1", "C" };
    cout << "Output 2: " << basketballScore(ops2) << endl;

    return 0;
}
