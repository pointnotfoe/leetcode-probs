/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
Given an integer n, return any array containing n unique integers such that they add up to 0.

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find N Unique Integers Sum up to Zero.
Memory Usage: 6.7 MB, less than 69.99% of C++ online submissions for Find N Unique Integers Sum up to Zero.
Next challenges:
*/
class Solution {
public:
    vector<int> sumZero(int n) {
         vector<int> sum_zero_arr;
        if (n%2 != 0)
        {
            sum_zero_arr.push_back(0);
            n--;
        }
            cout << " n = " << n <<endl;
        if (n <= 1 )
        {
            return sum_zero_arr;
        }
        for (int i = 1; i < n; i = i + 2)
        {
            cout << " i = " << i <<endl;
            sum_zero_arr.push_back(i);            
            sum_zero_arr.push_back(-i);
        }
        sort(sum_zero_arr.begin(),sum_zero_arr.end());
        return sum_zero_arr;

    }
};

