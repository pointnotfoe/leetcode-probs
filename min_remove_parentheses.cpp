/*
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
1249. Minimum Remove to Make Valid Parentheses
Solved
Medium
Topics
Companies
Hint
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 

Constraints:

1 <= s.length <= 105
s[i] is either '(' , ')', or lowercase English letter.
*/

/*
inspired from : https://www.youtube.com/watch?v=FTo1kDyE-h4
Runtime
20
ms
Beats
63.08%
Analyze Complexity
Memory
12.78
MB
Beats
62.08%

*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> lifo;
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                lifo.push(i);
            }
            else if (s[i] == ')' && lifo.size())
            {
                lifo.pop();
            }
            else if (s[i] == ')')
            {
                s[i] = '-';
            }
            // else if (c != ')')
            // {
            //     res += c;
            // }
        }
        while (lifo.size())
        {
            int idx = lifo.top();
            lifo.pop();
            s[idx] = '-';
        }
        for (auto &c : s)
        {
            if (c == '-')
                continue;
            res += c;
        }
        return res;
    }
};