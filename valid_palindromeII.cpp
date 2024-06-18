/*https://leetcode.com/problems/valid-palindrome-ii/description/
680. Valid Palindrome II
Solved
Easy
Topics
Companies
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/
/*
From https://leetcode.com/problems/valid-palindrome-ii/solutions/107720/c-java-python-easy-and-concise/
Runtime
56
ms
Beats
48.60%
Analyze Complexity
Memory
21.10
MB
Beats
70.48
*/
class Solution {
public:
    bool validPalindrome(string s) {
        int left =0; 
        int right = s.size() - 1; 
        while (left < right)
        {
            if (s[left] != s[right])
            {
                //skip left char
                int l1 = left+1; 
                int r1 = right; 
                while (l1 < r1 && s[l1] == s[r1])
                {
                    l1++;
                    r1--;
                }
                if (l1 >= r1)
                    return true;
                    
                //skip right char
                l1 = left; 
                r1 = right-1; 
                while (l1 < r1 && s[l1] == s[r1])
                {
                    l1++;
                    r1--;
                }
                if (l1 >= r1)
                    return true;

                return false;
            }
            right--;
            left++;
        }
        return true;
    }
};