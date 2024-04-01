/*
https://leetcode.com/problems/score-of-parentheses/
856 Score of parentheses
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
 

Constraints:

2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.
*/
/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.50
MB
Beats
30.91%
of users with C++
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> lifo;
        int score = 0;
        int sub_score = 0;
        char last;
        stack<int> sub_lifo;
        for (auto &c : s)
        {
            if (c == '(')
            {
                lifo.push(c);
                //if (sub_score)
                {
                    sub_lifo.push(sub_score);
                    sub_score = 0;
                }
            }
            else
            {
                lifo.pop();
                if (lifo.size())
                {
                    if (last == '(')
                        sub_score++;
                    else
                    {
                        while (sub_lifo.size())
                        {
                            auto top = sub_lifo.top();
                            sub_score += top;
                            sub_lifo.pop();
                            if (0 == top)
                            {
                                break;
                            }
                            
                        }
                        sub_score = (sub_score * 2);
                    }
                }
                else
                { 
                    while (sub_lifo.size())
                    {
                        sub_score += sub_lifo.top();
                        sub_lifo.pop();
                    }
                    if (sub_score)
                    {
                        score += (sub_score * 2);
                        sub_score = 0;
                    }
                    else
                    {
                        score++;
                    }
                }
            }
            last = c;
        }
        return score;
    }
};

/*
https://leetcode.com/problems/score-of-parentheses/solutions/141777/c-java-python-o-1-space/
Approach 0: Stack
cur record the score at the current layer level.

If we meet '(',
we push the current score to stack,
enter the next inner layer level,
and reset cur = 0.

If we meet ')',
the cur score will be doubled and will be at least 1.
We exit the current layer level,
and set cur += stack.pop() + cur

Complexity: O(N) time and O(N) space
*/
    int scoreOfParentheses(string S) {
        stack<int> stack;
        int cur = 0;
        for (char i : S)
            if (i == '(') {
                stack.push(cur);
                cur = 0;
            }
            else {
                cur += stack.top() + max(cur, 1);
                stack.pop();
            }
        return cur;
    }
/*
Approach 2: O(1) Space
We count the number of layers.
If we meet '(' layers number l++
else we meet ')' layers number l--

If we meet "()", we know the number of layer outside,
so we can calculate the score res += 1 << l.

C++:
*/
    int scoreOfParentheses(string S) {
        int res = 0, l = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') l++; else l--;
            if (S[i] == ')' && S[i - 1] == '(') res += 1 << l;
        }
        return res;
    }