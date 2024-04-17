//https://leetcode.com/explore/learn/card/recursion-i/255/recursion-memoization/1662/
class Solution {
public:
    Solution() 
    {
        step_map[0] = 1;        
        step_map[1] = 1;       
        step_map[2] = 2;

    }
    unordered_map<int, int> step_map;
    int climbStairs(int n) {
        if (n < 0)
        {
            return 0;
        }
            
        if (step_map.count(n))
        {
            return step_map[n];
        }
        step_map[n] = climbStairs(n-1) + climbStairs(n-2);
        return step_map[n];
        
        
    }
};