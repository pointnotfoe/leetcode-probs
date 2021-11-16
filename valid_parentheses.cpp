/*
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/merge-k-sorted-lists/submissions/
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.3 MB, less than 49.29% of C++ online submissions for Valid Parentheses.
*/
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        
        stack<char> lifo;
        lifo.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            char top = lifo.size() ? lifo.top() : '.';
            if ((top == '(' && ')'== s[i]) ||
                (top == '[' && ']'== s[i]) || 
                (top == '{' && '}'== s[i]))
            {
                lifo.pop();
            }
            else
            {
                lifo.push(s[i]);
            }
        }
        
        return lifo.empty();
    }
};