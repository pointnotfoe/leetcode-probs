/**
Autor: pointnotfoe
Leetcode:https://leetcode.com/problems/top-k-frequent-words/
*/
/*
Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.

*/
/*
Runtime: 12 ms, faster than 76.38% of C++ online submissions for Top K Frequent Words.
Memory Usage: 12.7 MB, less than 29.09% of C++ online submissions for Top K Frequent Words.
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        std::map<string,int> unique_map;
        //std::map<int,string> string_map;
        std::multimap<int,string, greater <int> > string_map;
        int size = words.size();
        //vector<int> count;
        for (int i = 0; i < size; i++)
        {
            unique_map[words[i]]++;
        }
        int index = 0;
        words.clear();
        words.resize(k);
        //bool duplicate = false;
        
        for(std::map <string,int>::iterator itr = unique_map.begin(); itr != unique_map.end(); itr++)
        {
            //string_map[itr->second] = itr->first;
            string_map.insert(make_pair(itr->second, itr->first));
        }
        for(std::multimap <int,string>::iterator itr = string_map.begin(); itr != string_map.end() && index < k; itr++)
        {
            words[index++] = itr->second;
        }
        
        
        return words;
        
    }
};

int main()
{
    Solution two_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    vector<int> answer = test_data.twoSum(test_data,64);

    return 0;

}
