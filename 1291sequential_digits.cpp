/*https://leetcode.com/problems/sequential-digits/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1
1291. Sequential Digits
Solved
Medium
Topics
premium lock icon
Companies
Hint
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
Seen this question in a real interview before?
1/5
Yes
No
Accepted
230,015/352.4K
Acceptance Rate
65.3%

Runtime 0 ms Beats 100.00%
Memory 8.22 MB Beats
74.09%

*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int table[][2] = {
            {12, 11},
            {123, 111},
            {1234, 1111},
            {12345, 11111},
            {123456, 111111},
            {1234567, 1111111},
            {12345678, 11111111},
            {123456789, 111111111},
        };
        int table_elements = sizeof(table) / sizeof(table[0]);
        int i = 0;
        int ten_mult = 10;
        int factor;
        for (; i < table_elements; i++)
        {
            factor = (low / ten_mult);
            if (factor > 0 && factor <= 9)
            {
                break;
            }
            ten_mult *= 10;
        }
        int num = table[i][0];
        while (num < low)
        {
            num += table[i][1];
            //if last digit is 0 then we are not a sequence anymore
            if ((num % 10) == 0)
            {
                i++;
                if (i >= table_elements)
                {
                    return res;
                }
                num = table[i][0];
            }
        }
        while (num <= high)
        {
            res.push_back(num);
            num += table[i][1];
            //if last digit is 0 then we are not a sequence anymore
            if ((num % 10) == 0)
            {
                i++;
                if (i >= table_elements)
                {
                    break;
                }
                num = table[i][0];
            }
        }
        return res;
    }
};