//https://leetcode.com/explore/learn/card/recursion-i/255/recursion-memoization/1661/
class Solution {
public:
    Solution() 
    {
        fib_map[0] = 0;        
        fib_map[1] = 1;

    }
    unordered_map<int, int> fib_map;
    int fib(int n) {
        if (fib_map.count(n))
        {
            return fib_map[n];
        }
        fib_map.insert(make_pair(n, fib(n-1) + fib(n-2)));
        return fib_map[n];
    }
};