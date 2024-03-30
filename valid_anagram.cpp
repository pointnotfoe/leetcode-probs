/*
Autor: pointnotfoe
Leetcode:https://leetcode.com/problems/valid-anagram/
242. Valid Anagram
Easy

7386

245

Add to List

Share
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
/*
Runtime: 43 ms, faster than 5.82% of C++ online submissions for Valid Anagram.
Memory Usage: 7.3 MB, less than 82.56% of C++ online submissions for Valid Anagram.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> char_map;
        for (auto &c: s)
        {
            char_map[c]++;
        }
        for (auto &c: t)
        {
            if (char_map.find(c) != char_map.end())
            {
                char_map[c]--;
                if (char_map[c] == 0)
                    char_map.erase(c);
            }
            else
                return false;
        }
        return char_map.size() == 0;
        
        
    }
};