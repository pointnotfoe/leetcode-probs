/**
Autor: pointnotfoe
Leetcode:https://leetcode.com/problems/remove-duplicate-letters/
*/
/*
Example 1:

Input: s = "bcabc"
Output: "abc"

Example 2:

Input: s = "cbacdcbc"
Output: "acdb"

*/
class Solution {//not lexicographical_comparesmallest
public:
    string removeDuplicateLetters(string s) {
        std::map<char,int> unique_map;
        int size = s.length();
        for (int i = 0; i < size; i++)
        {
            unique_map[s[i]]++;
        }
        int index = 0;
        for(std::map <char,int>::iterator itr = unique_map.begin(); itr != unique_map.end(); itr++)
        {
            s[index++] = itr->first;
        }
        s.resize(index);
        return s;
    }
};
//https://stackoverflow.com/questions/34476853/select-lexicographical-smallest-string-after-duplicates-removed
string smallestString(string input) {
    int chars = 0;
    int after[sizeof(input)];
    for (int i = input.length() - 1; i >= 0; i--) {
        chars |= 1 << (input[i] - 97);
        after[i] = chars;
    }
    string result = "";
    int start = 0, pos;
    while (chars) {
        for (int i = 0; i < 26; i++) {
            if (chars & (1 << i)) {
                pos = input.find('a' + i, start);
                if (chars == (chars & after[pos])) {
                    result += 'a' + i;
                    chars -= 1 << i;
                    break;
                }
            }
        }
        start = pos + 1;
    }
    return result;
}

int main()
{
    Solution two_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    vector<int> answer = test_data.twoSum(test_data,64);

    return 0;

}
