/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
1647. Minimum Deletions to Make Character Frequencies Unique
Medium

484

15

Add to List

Share
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. 
For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.
Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.
Runtime: 72 ms, faster than 42.75% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
Memory Usage: 17.5 MB, less than 34.09% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
*/
class Solution {
public:
    int minDeletions(string s) {
        int char_mask = 0;
        int count_arr[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {            
            int char_val = (s[i] - (int)'a');
            char_mask |= 1 << char_val; 
            count_arr[char_val]++;
            //cout << s[i] << " char_val = " << char_val<<  " count = " << count_arr[char_val] <<endl;
        }
       // cout << "char_mask = " << char_mask << endl;
        
        std::map <int, int> count_map;
        //int duplicate_count;
        for (int i = 0; i < 26; i++)
        {
            if ((char_mask&(1<<i)) == 0)//find the index of a char 
            {
                continue;
            }
            //see if we have already encountered a similar count
            //if (count_map.find(count_arr[i]) != count_map.end())
            {
            //    duplicate_count++;
                //count_map[count_arr[i]]++;//count up how many duplicates of this count
            }
            //else
            {
                //count_map[count_arr[i]] = (char)(i + (int)'a');

            }
            count_map[count_arr[i]]++;//count up how many duplicates of this count            
        }
        int delete_count = 0;
        std::map <int, int>::reverse_iterator itr;
        for (itr = count_map.rbegin(); itr != count_map.rend(); itr++)
        {
            if (itr->second <= 1)
            {
                continue;
            }
            //cout << itr->second << "  characters of size " << itr->first;
            delete_count += itr->second - 1;
            //cout << " , delete_count = " << delete_count << endl;
            //delete_count++;
            //itr->second--;
            
            int new_size = itr->first - 1;
            count_map[new_size] += itr->second - 1;//increase the new group's size 
            if (new_size == 0)
            {
                break;
            }
          //  while (count_map.find(new_size)->second > 1)
          //  {
          //      delete_count++;
          //      count_map[new_size]--;
          //      
          //      new_size = new_size - 1;
          //      count_map[new_size]++;9
          //  }
        }
        //itr--;//check the last one
        //cout << "Last: " << itr->second << " characters of size " << itr->first << endl;
        //if (itr->first > 0)
        {
         //   delete_count +=itr->second - 1;
        }
        return delete_count;
    }
};
//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/discuss/927549/C%2B%2BJavaPython-3-Greedy
/*
Runtime: 52 ms, faster than 94.26% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
Memory Usage: 17.4 MB, less than 55.25% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.

Input: s = "aaabbbcc"
Output: 2
*/
int minDeletions(string s) {
    int cnt[26] = {}, res = 0;
    unordered_set<int> used;
    for (char ch : s)
        ++cnt[ch - 'a'];
    for (int i = 0; i < 26; ++i)
        for (; cnt[i] > 0 && !used.insert(cnt[i]).second; --cnt[i])
            ++res;
    return res;
}