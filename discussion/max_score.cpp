/*
https://leetcode.com/discuss/interview-question/4931781/Amazon-SDE-2%3A-OA-question
To promote physical fitness, on the portal they launched a "GetFit" tournament consisting of n sprints. 
Each sprint lasts for a given number of days and includes several tasks such as push-ups, running, etc. 
Some tasks are scheduled for each day of the sprint. The ith sprint lasts for days[i] days, and each sprint starts just after the other.
That is, if the ith sprint ends on day d, the (i + 1)th sprint starts on day (d + 1). 
During each sprint, completing the required tasks scheduled on the jth day of the sprint earns the participant j points.

The tournaments are periodic, i.e, as soon as the last sprint of a tournament ends, the first sprint of the next tournament begins. 
Each tournament, however, has the same schedule of sprints. More formally, the tournament schedule can be considered cyclic in nature and 
after the last sprint, the first sprint starts again.
An employee decides to participate. However, due to a tight schedule, the employee cannot complete all tasks every day. 
Instead, the employee will complete the tasks of exactly k consecutive days, hoping to achieve the maximum number of points.
Given the sprint days of n sprints, and the number of days for which the employee competes for k, find the maximum points the employee can score.
The training can start and end on any day of any sprint.

Note:
•⁠ ⁠k is guaranteed to be less than the total number of days for which the sprints last.
•⁠ ⁠Also, it is not necessary to start and end the training in the same tournament.
•⁠ ⁠A sprint here denotes a set of activities performed in a particular time period

Example
There are n = 3 sprints, the number of days of each sprint are days = [2,3,2], and k = 4.

The maximum number of points that can be attained = 2 + 1 + 2 + 3 = 8. One choice is to start on the last day of the first sprint and end on the last day of the second sprint.

Function Description
Complete the function getMaximumPoints in the editor below.
getMaximumPoints has the following parameters: int days[n]: the number of days in each sprint int k. the number of consecutive days to train.
Returns
long int: the maximum points that can be earned after training for k consecutive days.

Constraints
•⁠ ⁠1 ≤ n≤ 10^5
•⁠ ⁠1≤ days[i] ≤10^5,i =1，..., n
•⁠ ⁠1 ≤ k ≤ days[1] + days[2] +..... + days[n]

Sample Input For Custom Testing
5 -> days [] count n = 5
7 -> days = [7, 4, 6, 3, 5]
4
6
3
5
8 -> k = 8
Sample Output
33
Explanation
A maximum of 33 points can be earned by starting on day 5 of sprint 4 and ending on the last day of sprint 5. The number of points earned is (5) + (1 + 2 + 3 + 4+5 + 6 + 7) = 33.
Note how as soon as one set of sprint ends, the tournament again starts with the sprint of 7 days.

NOTE: I tried creating array for each day, example for [7, 4, 6, 3, 5], I created array of [1,2,3,4,5,6,7,1,2,3,4,1,2,3,4,5,6,1,2,3,1,2,3,4,5] but obviously I got Memory exceeded, I then tried using 2 pointer approach to store the start and end points (basically similar to what I did in previous approach but without creating whole array) but again got TLE.

Could someone please tell me a better approach which will work for given contraints.
*/
#include <bits/stdc++.h>

using namespace std;

int max_score(vector<int> sprints, int k)
{
    int max_score = 0;
    int largest_sprint = 0;
    for (int i  = 0; i < sprints.size(); i++)
    {
        if (sprints[i] > sprints[largest_sprint])
            largest_sprint = i;
    }
    while (k)
    {
        for (int score = sprints[largest_sprint]; score > 0 && k > 0; score--, k--)
        {
            max_score += score;
        }
        largest_sprint--;
        if (largest_sprint < 0)
            largest_sprint = sprints.size() - 1;
    }
    return max_score;
    //if non consective days then this
    // map<int, int> score_count;
    // for (auto &days: sprints)
    // {
    //     int start = days >= k ? days -k : 0;
    //     for (; start < days; start ++)
    //     {
    //         score_count[start]++;
    //     }
    // }
    // 
    // for (auto itr = score_count.rbegin(); itr != score_count.rend() && k > 0; itr++)
    // {
    //     int score = itr->first;
    //     int score_cnt = itr->second;
    //     max_score += score*(min(score_cnt, k));
    //     k -= min(score_cnt, k);
    // }
}

void print_vec(vector<int> s)
{
    cout<<"[ "; 
    for(int x: s)
    {
        cout<<x<<" "; 
    }
    cout<<" ]"; 
    cout<<endl;
}

int main()
{
    {
    vector<int> temp = {7, 4, 6, 3, 5};
    print_vec(temp);
    cout << "    Expected 33. Got " << max_score(temp, 8) << endl;
    }
    return 0;
}
