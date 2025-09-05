/*
1864. Minimum Number of Swaps to Make the Binary String Alternating
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.

The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Any two characters may be swapped, even if they are not adjacent.

 

Example 1:

Input: s = "111000"
Output: 1
Explanation: Swap positions 1 and 4: "111000" -> "101010"
The string is now alternating.
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating, no swaps are needed.
Example 3:

Input: s = "1110"
Output: -1
 

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
32,696/75.2K
Acceptance Rate
43.5%
*/

/*
Runtime 0 ms Beats 100.00%

Memory 9.60 MB Beats 8.33%
*/
class Solution {
public:
    int minSwaps(string s) {
        int zeroCount = 0;
        int oneCount = 0;
        char lastChar = 'x';
        bool alternating = true;
        string oneStart = "";
        string zeroStart = "";
        int idx = 0;
        int zeroStartDiff = 0;
        int zeroStartZeroCount = 0;
        int zeroStartOneCount = 0;

        int oneStartDiff = 0;
        int oneStartZeroCount = 0;
        int oneStartOneCount = 0;
        for (const char &c: s)
        {
            if (c == '0')
            {
                zeroCount++;
            }
            else
            {
                oneCount++;
            }
            if (lastChar == c)
            {
                alternating = false;
            }
            lastChar = c;
            if (idx++ % 2)
            {
                oneStart += '0';
                zeroStart += '1';
                if (c == '1')
                {
                    oneStartDiff++;
                }
                else
                {
                    zeroStartDiff++;
                }
                oneStartZeroCount++;
                zeroStartOneCount++;
            }
            else
            {
                oneStart += '1';
                zeroStart += '0';
                if (c == '0')
                {
                    oneStartDiff++;
                }
                else
                {
                    zeroStartDiff++;
                }
                zeroStartZeroCount++;
                oneStartOneCount++;
            }
        }
        if (true == alternating)
        {
            return 0;
        }
        if (abs(zeroCount - oneCount) > 1)
        {
            return -1;
        }
        int result;
        if (zeroStartZeroCount != zeroCount || zeroStartOneCount != oneCount)
        {
            result = oneStartDiff >> 1;
        }
        else if (oneStartZeroCount != zeroCount || oneStartOneCount != oneCount)
        {
            result = zeroStartDiff >> 1;
        }
        else
        {
            result = (min(zeroStartDiff, oneStartDiff)) >> 1;
        }
        cout << zeroStart << ": " << zeroStartDiff << endl;
        cout << oneStart << ": " << oneStartDiff << endl;
        return result;
    }
};

/*
Runtime 0 ms Beats 100.00% 
Memory 9.24 MB Beats 77.90%

*/
class Solution {
public:
    int minSwaps(string s) {
        int zeroCount = 0;
        int oneCount = 0;
        char lastChar = 'x';
        bool alternating = true;
        // string oneStart = "";
        // string zeroStart = "";
        int idx = 0;
        int zeroStartDiff = 0;
        int zeroStartZeroCount = 0;
        int zeroStartOneCount = 0;

        int oneStartDiff = 0;
        int oneStartZeroCount = 0;
        int oneStartOneCount = 0;
        for (const char &c: s)
        {
            if (c == '0')
            {
                zeroCount++;
            }
            else
            {
                oneCount++;
            }
            if (lastChar == c)
            {
                alternating = false;
            }
            lastChar = c;
            if (idx++ % 2)
            {
                // oneStart += '0';
                // zeroStart += '1';
                if (c == '1')
                {
                    oneStartDiff++;
                }
                else
                {
                    zeroStartDiff++;
                }
                oneStartZeroCount++;
                zeroStartOneCount++;
            }
            else
            {
                // oneStart += '1';
                // zeroStart += '0';
                if (c == '0')
                {
                    oneStartDiff++;
                }
                else
                {
                    zeroStartDiff++;
                }
                zeroStartZeroCount++;
                oneStartOneCount++;
            }
        }
        if (true == alternating)
        {
            return 0;
        }
        if (abs(zeroCount - oneCount) > 1)
        {
            return -1;
        }
        int result;
        if (zeroStartZeroCount != zeroCount || zeroStartOneCount != oneCount)
        {
            result = oneStartDiff >> 1;
        }
        else if (oneStartZeroCount != zeroCount || oneStartOneCount != oneCount)
        {
            result = zeroStartDiff >> 1;
        }
        else
        {
            result = (min(zeroStartDiff, oneStartDiff)) >> 1;
        }
        // cout << zeroStart << ": " << zeroStartDiff << endl;
        // cout << oneStart << ": " << oneStartDiff << endl;
        return result;
    }
};

/*
https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/solutions/1211155/count-misplaced-chars/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1

Vlad
100 Days Badge 2023
5163
May 15, 2021
C
First count the number of zeros and ones; return -1 if the counts differ by more than one.

If our string is odd-sized, then we know where zeros and ones should be. For even-sized strings, we need to check two cases: when the string starts with '0', and when with '1'.

I first used two pointers, but then realized that it can be simplified.
*/
int minSwaps(string s) {
    int cnt0 = count(begin(s), end(s), '0'), cnt1 = s.size() - cnt0, miss0 = 0, miss1 = 0;
    if (abs(cnt0 - cnt1) > 1)
        return -1;
    for (int i = 0; i < s.size(); i += 2) {
        miss0 += s[i] != '0';
        miss1 += s[i] != '1';
    }
    return cnt0 == cnt1 ? min(miss0, miss1) : cnt0 > cnt1 ? miss0 : miss1;
}