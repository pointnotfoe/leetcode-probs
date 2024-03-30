/*

Autor: pointnotfoe 
Leetcode: https://leetcode.com/problems/group-anagrams/
49. Group Anagrams
Medium

11003

350

Add to List

Share
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
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
*/

//mine
//Time Limit Exceeded
class Solution {
public:
    //each index is to match with result and a char map of words in that index
    vector<unordered_map<char, int>> index_char_map;
    vector<vector<string>> result;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (auto word : strs)
        {
            // cout << word;
            int index = anagram_index_get(word);
            if(index == -1)
            {
                // cout << " not seen before. ";
                index = index_char_map.size();
                index_char_map.push_back(unordered_map<char,int>());
                for (auto c: word)
                {
                    index_char_map[index][c]++;
                }
                result.push_back({word});
                // cout << "Added to index " << index << " ";
            }
            else
            {
                result[index].push_back(word);
            }
            // cout << endl;
            
        }
        return result;
    }
    int anagram_index_get(string word)
    {
        int index = -1;
        for (int i = 0; i < result.size(); i++)
        {
            //try to match the size of the first, since they are all same
            if (word.size() != result[i][0].size())
            {
                continue;
            }
            // cout << endl <<"  size match at index " << i << " ";
            //getting a copy of the char map
            unordered_map<char, int> char_map = index_char_map[i];
            for (int j = 0; j < word.size(); j++)
            {
                auto itr = char_map.find(word[j]);
                if (itr == char_map.end())
                {
                    break;
                }
                // cout << endl <<"    {" << word[j] << ", " << itr->second << " }";
                itr->second--;
                //erase if all such chars found 
                if (itr->second == 0)
                {
                    char_map.erase(itr);
                }
            }
            // cout << endl <<"  copy char_map size " << char_map.size() << 
            //             ",  original char_map size " << index_char_map[i].size() << endl;

            if (char_map.size() == 0)
            {
                return i;
            }
        }
        return index;
    }
    
//             auto itr = index_char_map.find(mask); 
//             if (itr != index_char_map.end())// we already have a mask for this
//             {
//                 result[itr->second].push_back(word);
//             }
//             else
//             {
//                 index_char_map[mask] = result.size();
//                 result.push_back({word});
//             }
    // int char_mask_get(string str)
    // {
    //     int mask = 0;
    //     for (char c: str)
    //     {
    //         mask |= c - 'a';
    //     }
    //     return mask;
    // }
};

//https://leetcode.com/problems/group-anagrams/discuss/19200/C%2B%2B-unordered_map-and-counting-sort
//auhor:jianchao-li
//Last Edit: October 16, 2018 8:27 PM
//Use an unordered_map to group the strings by their sorted counterparts. Use the sorted string as the key and all anagram strings as the value.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
//Moreover, since the string only contains lower-case alphabets, we can sort them using counting sort to improve the time complexity.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};

//https://leetcode.com/problems/group-anagrams/discuss/19200/C++-unordered_map-and-counting-sort/19270
//author:guangqianpeng
/*62
January 2, 2017 12:01 AM

Read More
Great answer! I have made several improvements of your code. The new answer takes 52ms

use auto& rather then auto to avoid unnecessary copy
use std::move() to steal vector from map
use vector.reserve() to avoid reallocate
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ret;
        for (const auto& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        ret.reserve(map.size());
        for (auto& p : map) {
            ret.push_back(std::move(p.second));
        }
        return ret;
    }
};