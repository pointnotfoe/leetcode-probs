/*
2398. Maximum Number of Robots Within Budget
Solved
Hard
Topics
premium lock icon
Companies
Hint
You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] units to run. You are also given an integer budget.

The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts), where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is the sum of running costs among the k robots.

Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.

 

Example 1:

Input: chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
Output: 3
Explanation: 
It is possible to run all individual and consecutive pairs of robots within budget.
To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 which is less than 25.
It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.
Example 2:

Input: chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
Output: 0
Explanation: No robot can be run that does not exceed the budget, so we return 0.
 

Constraints:

chargeTimes.length == runningCosts.length == n
1 <= n <= 5 * 104
1 <= chargeTimes[i], runningCosts[i] <= 105
1 <= budget <= 1015
Seen this question in a real interview before?
1/5
Yes
No
Accepted
29,309/79.3K
Acceptance Rate
37.0%
Topics
icon
Companies
Hint 1
Hint 2
Hint 3
Similar Questions
Discussion (27)

Choose a type



Copyright © 2025 LeetCode. All rights reserved.
*/
/*
Runtime
208
ms
Beats
19.40%
Analyze Complexity
Memory
159.02
MB
Beats
18.16%
*/
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int max_robots = 0;
        int n = runningCosts.size();
        vector<long long> run_sum(n+1, 0);
        int i= 1; 
        for (auto &c : runningCosts){
            run_sum[i] = run_sum[i-1] + c;
            i++;  
        }
        set<pair<int,int>> window;
        int left=1;
        long long current = 0;
        for (i = 1; i < n+1; i++)
        {
            window.insert(make_pair(chargeTimes[i-1], i-1));
            current = (run_sum[i] - run_sum[left-1])*(i-left + 1);
            current += (window.crbegin())->first;
            while (current > budget && left < i)
            {
                window.erase(window.find(make_pair(chargeTimes[left-1], left-1)));
                left++;
                current = (run_sum[i] - run_sum[left-1])*(i-left + 1);
                current += (window.crbegin())->first;
            }
            if (current <= budget)
            {
                max_robots = max(max_robots, i-left + 1);
            }
        }
        return max_robots;
    }
};

//15ms solution on site
class Solution {
public:
    int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
        int i = 0, n = times.size();
        long long sum = 0;
        deque<int> q;
        int res = 0;
        for (int j = 0; j < n; ++j) {
            sum += costs[j];
            while (q.size() && times[q.back()] <= times[j]) {
                q.pop_back();
            }
            q.push_back(j);
            if (times[q.front()] + (j - i + 1) * sum > budget) {
                if (q.front() == i) q.pop_front();
                sum -= costs[i++];
            } else {
                res = max(res, j - i + 1);
            }
        }
        return res;
    }
};