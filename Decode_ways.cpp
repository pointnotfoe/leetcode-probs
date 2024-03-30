/*
https://leetcode.com/problems/decode-ways/description/
91 Decode ways
Medium
Topics
Companies
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).

*/
/*Runtime
778
ms
Beats
5.86%
of users with C++
Memory
357.63
MB
Beats
5.15%
of users with C++

*/
class Solution {
public:
    Solution () : idx_cnt (100,0)
    {
        for (int i = 0; i < 26; i++)
        {
            // lut[to_string(i+1)] = 'A'+i;
            lut.insert(to_string(i+1));
        }
        result = 0;
    }
    unordered_set<string> lut;
    vector<int> idx_cnt;
    int result;
    void numDecodingsRecur(string s, int idx)
    {
        if (s.size() ==0 || s[0] == '0')
        {
            return;
        }
        if (idx >= s.size())
        {
            result++;
            return;
        }
        if (idx_cnt[idx])
        {
            result += idx_cnt[idx];
            return;
        }
        //for (int start = idx; start < s.size(); start++)
        {   
            string temp(1, s[idx]);
            if (lut.count(temp))
            {
                numDecodingsRecur(s, idx + 1);
                idx_cnt[idx] = result;
            }
            if (idx + 1 < s.size() && lut.count(temp + s[idx+1]))
            {
                numDecodingsRecur(s, idx + 2);
                idx_cnt[idx] = result;
            }
        }
    }
    int numDecodings(string s) {
        numDecodingsRecur(s, 0);
        return result;
    }
};

/* 
https://leetcode.com/problems/decode-ways/solutions/1410794/c-python-from-top-down-dp-to-bottom-up-dp-o-1-space-clean-concise/

Solution 1: Top down DP

For a character s[i], we have 2 ways to decode:
Single digit: Require s[i] != '0' (decoded to 1..9)
Two digits: Require i + 1 < len(s) and (s[i] == 1 (decoded to 10..19) or s[i] == 2 and s[i+1] <= '6') (decoded to 20..26).
*/
class Solution { // 12 ms, faster than 9.19%
public:
    int memo[100] = {};
    int numDecodings(const string& s) {
        return dp(s, 0);
    }
    int dp(const string& s, int i) {
        if (i == s.size()) return 1;
        if (memo[i] != 0) return memo[i];
        int ans = 0;
        if (s[i] != '0') // Single digit
            ans += dp(s, i+1);
        if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
            ans += dp(s, i+2);
        return memo[i] = ans;
    }
};
/*
 Solution 2: Bottom-up DP

Just convert from Top-down DP to Bottom-up DP approach.
*/
class Solution { // 0 ms, faster than 100.00%
public:
    int numDecodings(const string& s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') // Single digit
                dp[i] += dp[i+1];
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};

/*Solution 3: Bottom-up DP (Space Optimized)


Since our dp only need to keep up to 3 following states:
Current state, let name dp corresponding to dp[i]
Last state, let name dp1 corresponding to dp[i+1]
Last twice state, let name dp2 corresponding to dp[i+2]
So we can achieve O(1) in space.
*/
class Solution { // 0 ms, faster than 100.00%
public:
    int numDecodings(const string& s) {
        int n = s.size(), dp = 0, dp1 = 1, dp2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') // Single digit
                dp += dp1;
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
                dp += dp2;
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};