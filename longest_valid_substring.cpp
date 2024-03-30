/*
2781 https://leetcode.com/problems/length-of-the-longest-valid-substring/description/
You are given a string word and an array of strings forbidden.

A string is called valid if none of its substrings are present in forbidden.

Return the length of the longest valid substring of the string word.

A substring is a contiguous sequence of characters in a string, possibly empty.

 

Example 1:

Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
Output: 4
Explanation: There are 11 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", "ab", "abc" and "aabc". The length of the longest valid substring is 4. 
It can be shown that all other substrings contain either "aaa" or "cb" as a substring. 
Example 2:

Input: word = "leetcode", forbidden = ["de","le","e"]
Output: 4
Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
It can be shown that all other substrings contain either "de", "le", or "e" as a substring. 
 

Constraints:

1 <= word.length <= 105
word consists only of lowercase English letters.
1 <= forbidden.length <= 105
1 <= forbidden[i].length <= 10
forbidden[i] consists only of lowercase English letters.
//https://leetcode.com/problems/length-of-the-longest-valid-substring/solutions/3771333/picture-short-and-concise-approach-easy-to-understand-in-depth-explanation/comments/1972044
Runtime
493
ms
Beats
37.36%
of users with C++
Memory
126.67
MB
Beats
72.26%
of users with C++
*/


class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> na_set;
        for (const auto & str: forbidden)
        {
            na_set.insert(str);
        }
        int left = 0;
        string str = "";
        int max_str = 0;
        for (int right = 0; right < word.size(); right++)
        {
            // cout << "right: " << right << endl;
           for (int sub_start = max(left, right - 10); sub_start < right + 1; sub_start++)
           {    
                str = word.substr(sub_start, right-sub_start + 1);
                if (na_set.find(str) != na_set.end())
                {
                    left = sub_start + 1;
                }
                // cout << "    sub_start: "<<sub_start<< ", "<<  str << ", left: " << left<< endl;
           }
           max_str = max(max_str, right - left + 1);
        }
        return max_str;
    }
};

/*
https://leetcode.com/problems/length-of-the-longest-valid-substring/solutions/3771266/simple-solutions-with-c-java-python/
Runtime
326
ms
Beats
91.64%
of users with C++
Memory
126.56
MB
Beats
85.40%
of users with C++
*/
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int len = 0;
        unordered_set<string> all;
        for (const string &s : forbidden) {
            all.insert(s);
            len = max(len, (int) s.length());
        }
        const int n = word.length();
        int r = 0;
        for (int i = n - 1, right = n; right > r && i >= 0; --i) {
            int now = 0;
            string temp;
            for (int j = i; j < right && j - i < len; ++j) {
                temp.push_back(word[j]);
                if (all.count(temp)) {
                    right = j;
                    break;
                }
            }
            r = max(r, right - i);
        }
        return r;
        
    }
};