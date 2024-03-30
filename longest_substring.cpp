/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

Runtime: 126 ms, faster than 12.01% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 19.2 MB, less than 11.56% of C++ online submissions for Longest Substring Without Repeating Characters.

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = s.size() > 0 ? 1 : 0;
        for (int i = 0; i < s.size(); i++)
        {
            string sub = s.substr(i,1);
            for(int j = i + 1; j < s.size(); j++)
            {
                if (sub.find(s[j]) == string::npos)
                {
                    sub += s[j];
                    longest = sub.size() > longest? sub.size() : longest ;
                }
                else
                {
                    break;
                }
            }
        }
        return longest;
    }
};
/*

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:
*/
//https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1737/C%2B%2B-code-in-9-lines.
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;//taking the index before so no need to do +1 on size
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)//already seen this character
                start = dict[s[i]];//update to last seen index, if we update to current the to +1 on maxlen calc
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }