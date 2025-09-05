/*
https://leetcode.com/problems/group-anagrams/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1
49. Group Anagrams
Attempted
Medium
Topics
premium lock icon
Companies
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,903,406/5.5M
Acceptance Rate
71.1%

*/
/*
Runtime
2311
ms
Beats
5.03%
Analyze Complexity
Memory
28.12
MB
Beats
22.12%
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int N = strs.size();
        vector<vector<string>> result;
        unordered_map<string, array<int, 26>> freq_map;
        unordered_map<string, int> res_location;
        for (int i = 0; i < N; ++i){
            if (freq_map.find(strs[i]) != freq_map.end())
            {
                result[res_location[strs[i]]].push_back(strs[i]);
            }
            else
            {
                array<int, 26> freq = {0};
                for (auto &c : strs[i])
                {
                    freq[c - 'a']++;
                }
                bool found = false;
                for (auto &[w,f]:freq_map)
                {
                    //if (f == freq)
                        /*1813 ms Beats 5.03%
                          Memory 26.28 MB Beats 30.46%
                        */
                    if (0 == memcmp(&f, &freq, 26*sizeof(int)))    
                    {                

                        found = true;
                        result[res_location[w]].push_back(strs[i]);
                        break;
                    }
                }
                if (!found)
                {
                    freq_map[strs[i]] = freq;
                    result.push_back({strs[i]});
                    res_location[strs[i]] = result.size() - 1;
                }
            }
        }
        return result;
    }
};

/*
Runtime
1820
ms
Beats
5.03%
Analyze Complexity
Memory
26.36
MB
Beats
29.01%
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int N = strs.size();
        vector<vector<string>> result;
        unordered_map<int, array<int, 26>> freq_map;
        unordered_map<int, int> res_location;
        for (int i = 0; i < N; ++i){
            array<int, 26> freq = {0};
            for (auto &c : strs[i])
            {
                freq[c - 'a']++;
            }
            bool found = false;
            for (auto &[idx, f] : freq_map)
            {
                if (f == freq)
                {
                    found = true;
                    result[res_location[idx]].push_back(strs[i]);
                    break;
                }
            }
            if (!found)
            {
                freq_map[i] = freq;
                result.push_back({strs[i]});
                res_location[i] = result.size() - 1;
            }
        }
        return result;
    }
};