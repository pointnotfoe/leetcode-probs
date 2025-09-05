/*2055. Plates Between Candles
Solved
Medium
Topics
premium lock icon
Companies
Hint
There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.

You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.

 

Example 1:

ex-1
Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]
Explanation:
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.
Example 2:

ex-2
Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
Output: [9,0,0,0,0]
Explanation:
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.
 

Constraints:

3 <= s.length <= 105
s consists of '*' and '|' characters.
1 <= queries.length <= 105
queries[i].length == 2
0 <= lefti <= righti < s.length


Runtime 4 ms Beats 97.39% 
Memory 146.82 MB Beats 70.39%

*/
class Solution {
public:
    // void printVec(vector<int> vec, string prefix)
    // {
    //     cout << prefix <<": ";
    //     for (int i = 0; i < vec.size(); ++i)
    //     {
    //         cout << vec[i] << ", ";
    //     }
    //     cout << endl;
    // }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // set<int> candle_idx;
        // std::vector<int> candle_idx;
        //https://www.youtube.com/watch?v=4Ch3Zt5qGeA&t=966s
        int q = queries.size();
        vector<int> res(q,0);
        int n = s.size();
        if (n == 0)
        {
            return res;
        }
        vector<int> run_sum(n,0);
        vector<int> left_candle(n,0);
        vector<int> right_candle(n,0);
        run_sum[0] = s[0] == '*' ? 1 :0;
        left_candle[0] = s[0] == '|' ? 0 :-1;
        right_candle[n-1] = s[n-1] == '|' ? n-1 :n;
        for (int i = 1; i < n; ++i)
        {
            run_sum[i] = run_sum[i-1] + (s[i] == '*');
            left_candle[i] = s[i] == '|' ? i : left_candle[i-1];
            right_candle[n - 1 - i] = s[n - 1 - i] == '|' ? n - 1 - i : right_candle[n - i];
        }
        // printVec(run_sum, "run_sum");
        // printVec(left_candle, "left_candle");
        // printVec(right_candle, "right_candle");
        int start;
        int end;
        for (int i = 0; i < q; ++i)
        {
            start = right_candle[queries[i][0]];
            end = left_candle[queries[i][1]];
            if (start >= end)
            {
                continue;
            }
            res[i] = run_sum[end] - run_sum[start];
        }


        /*
        map<int, list<pair<int,int>> > q_map;
        for (auto &q: queries)
        {
            q_map[q[0]].push_back(make_pair(res.size(), q[1]));
            res.push_back(0);
        }
        int i = s.find('|');
        while (i < s.size())
        {
            int next = s.find('|', i);
            int count = next - i - 1;
            auto itr = q_map.lower_bound(i);
            if (itr != candle_idx.end())
            {
                for (auto &[res_idx, end_idx]: itr)
                {
                    if (next <= end_idx)
                    {
                        res[res_idx] += count;
                    }
                }
            }
            i = next;
        }
        std::vector<int> candle_idx;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '|')
            {
                // candle_idx.insert(i);
                candle_idx.push_back(i);
            }
        }*/

        /*TLE 11/13 passed
        // set<int> candle_idx;
        std::vector<int> candle_idx;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '|')
            {
                // candle_idx.insert(i);
                candle_idx.push_back(i);
            }
        }
        for (auto &q: queries)
        {
            // auto itr = candle_idx.lower_bound(q[0]);
            auto itr = lower_bound(candle_idx.begin(), candle_idx.end(), q[0]);
            if (itr == candle_idx.end() || *itr > q[1])
            {
                res.push_back(0);
                continue;
            }
            int int_start = *itr;
            int count = 0;
            while (int_start <= q[1])
            {
                // itr = candle_idx.upper_bound(int_start);
                itr = upper_bound(itr, candle_idx.end(), int_start);
                if (itr == candle_idx.end() || *itr > q[1])
                {
                    break;
                }
                count += *itr - int_start - 1;
                int_start = *itr;
            }
            res.push_back(count);
        }*/
        return res;
    }
};