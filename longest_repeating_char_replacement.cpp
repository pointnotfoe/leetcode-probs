/*
424. Longest Repeating Character Replacement
Solved
Medium
Topics
Companies
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/
/*
Runtime
3
ms
Beats
96.66%
of users with C++
Memory
8.14
MB
Beats
80.18%
of users with C++
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int cnt[26] = {0};
        int mask = 0;
        int size = s.size();
        int char_num;
        int longest = 1;
        int swap_count = 0;
        char_num = s[0] - 'A';
        cnt[char_num]++;
        int total_chars = 1;
        int longest_char = char_num;
        int longest_char_count = 1;
        for (int right = 1; right < size; right++)
        {
            char_num = s[right] - 'A';
            cnt[char_num]++;
            mask |= 1 << char_num;
            total_chars++;
            if (longest_char_count < cnt[char_num])
            {
                longest_char_count = cnt[char_num];
                longest_char = char_num;
            }
            while (total_chars - longest_char_count > k)//__builtin_popcount(mask) > k + 1
            {
                int left_char_num = s[left] - 'A';
                cnt[left_char_num]--;
                left++;
                total_chars--;
                if (left_char_num == longest_char)
                {
                    longest_char_count = 0;
                    for (int i =0; i < 26; i++)
                    {
                        if (cnt[i] > longest_char_count)
                        {
                            longest_char_count = cnt[i];
                            longest_char = i;
                        }
                    }
                }
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};

/*https://leetcode.com/problems/longest-repeating-character-replacement/solutions/278271/java-c-python-sliding-window-just-o-n/
Explanation
maxf means the max frequency of the same character in the sliding window.
To better understand the solution,
you can firstly replace maxf with max(count.values()),
Now I improve from O(26n) to O(n) using a just variable maxf.


Complexity
Time O(n)
Space O(128)
*/
    int characterReplacement(string s, int k) {
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < s.length(); ++i) {
            maxf = max(maxf, ++count[s[i]]);
            if (res - maxf < k)
                res++;
            else
                count[s[i - res]]--;
        }
        return res;
    }
    
    int characterReplacement(string s, int k) {
        int maxf = 0, i = 0, n = s.length();
        vector<int> count(26);
        for (int j = 0; j < n; ++j) {
            maxf = max(maxf, ++count[s[j] - 'A']);
            if (j - i + 1 > maxf + k)
                --count[s[i++] - 'A'];
        }
        return n - i;
    }