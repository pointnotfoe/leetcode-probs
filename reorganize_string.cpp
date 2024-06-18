/*https://leetcode.com/problems/reorganize-string/description/
767. Reorganize String
Solved
Medium
Topics
Companies
Hint
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
394.9K
Submissions
722.4K
Acceptance Rate
54.7%

*/
/*
Runtime
4
ms
Beats
32.32%
of users with C++
Memory
8.56
MB
Beats
39.75%
of users with C++
*/
class Solution {
public:
    string reorganizeString(string s) {
        if (s.size() < 2)
            return s;
        unordered_map<char, int> freq;
        for (auto &c : s)
        {
            freq[c]++;
        }
        priority_queue<pair<int,char>> max_heap;
        for (auto &[c, count] : freq)
        {
            max_heap.push({count, c});
        }
        pair<int,char> last = make_pair(0,'-');
        string result = "";
        while(max_heap.size())
        {
            auto top = max_heap.top();
            max_heap.pop();
            result += top.second;
            top.first--;
            if (last.first > 0)
            {
                max_heap.push(last);
                last.first = 0;
                // result += last.second;
                // last.first--;
                // if (last.first > 0)
                // {
                //     max_heap.push(last);
                //     last.first = 0;
                // }
            }
            if (top.first)
            {
                last = top;
            }
        }
        if (last.first > 1)
            return "";
        if (last.first == 1)
            result += last.second;

        return result[result.size() -1 ] == result[result.size() -2 ] ? "" : result;
    }
};

/*
KasraCode
https://leetcode.com/problems/reorganize-string/solutions/335312/c-beat-100/

    explanation https://leetcode.com/problems/reorganize-string/solutions/335312/c-beat-100/comments/1282876
*/
class Solution
{
    public:
    string reorganizeString(string s)
    {
        // Step-1: Store the characters count in 'm'.
        //         And also keep track of most frequent character.
        int mostFreq = 0;
        vector<int> m(256, 0);
        for (char c: s) 
        {
            if(++m[c] > m[mostFreq])
                mostFreq = c;
        }
        
        // Step-2: If the most frequent character occurs more than half of the actual string size,
        //         it means that it is not possible to reorganize the input string. Return here.
        //         Otherwise, fill this mostFreq character in alternative even index of the result string (we can do it in-place).
        if (2*m[mostFreq] - 1 > s.size())
            return "";
        
        int i = 0;
        while (m[mostFreq] > 0)
        {
            s[i] = (char)mostFreq;
            m[mostFreq]--;
            i = i+2;            
        }
        
        // In step-2 above, why are we first filling the result array with mostFreq character first?
        // Why can't we just remove the above while loop and let the below loop handle everything?
        // This is because of some special cases like "vvvlo". If we leave everything to the below while loop,
        // then the result would be "lvovv", because that will start the loop with 'l', then 'o' and then finally 'v'.
        // By the time, the loop reached 'v', we already ran out of space and have to keep 'v's next to each other, which will void
        // the original condition.
        
        // Step-3: Fill each of the character in alternative index.
        //         Remember that 'i' is still an even number and we first fill even indices.
        //         Once, they are over, then we start filling odd indices starting from i=1
        for (int j=0; j<256; j++)
        {
            while (m[j] > 0)
            {
                if (i>=s.size())
                    i = 1;
                s[i] = (char)j;
                m[j]--;
                i = i+2;
            }
        }
        
        // Step-4: Done
        return s;
    }
};