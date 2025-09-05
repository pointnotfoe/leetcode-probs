/*
https://leetcode.com/problems/reorder-data-in-log-files/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1

937. Reorder Data in Log Files
Solved
Medium
Topics
premium lock icon
Companies
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
Example 2:

Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

Constraints:

1 <= logs.length <= 100
3 <= logs[i].length <= 100
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the identifier.

Runtime 0 ms Beats 100.00%
Memory 13.54 MB Beats 96.51% 
*/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int N = logs.size();
        vector<string> res(N);
        map<pair<string,string>, int> log_id_idx;
        int dig_idx = N-1;
        int log_start;
        for (int i = N - 1; i >= 0; --i)
        {
            log_start = logs[i].find(' ');
            if (isdigit(logs[i][log_start + 1]))
            {
                res[dig_idx--] = logs[i];
            }
            else
            {
                log_id_idx[make_pair(logs[i].substr(log_start + 1), logs[i].substr(0, log_start))] = i;
            }
        }
        int i = 0;
        for (auto &[log_id, idx] : log_id_idx)
        {
            res[i++] = logs[idx];
        }
        return res;
    }
};