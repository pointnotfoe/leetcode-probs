/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/replace-words/
648. Replace Words
Medium

1554

155

Add to List

Share
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.


*/

/*
Runtime: 59 ms, faster than 83.79% of C++ online submissions for Replace Words.
Memory Usage: 50.3 MB, less than 64.27% of C++ online submissions for Replace Words.
*/
class trie {
    typedef struct data {
        char letter;
        bool is_word = false;
        data *node[26] = {};
    }data;
  public:
    //can further optimize to stop insertion if shorter root already exists e.g. inserting cats when cat is already there
    void add(string word)
    {
        if (word.size() < 1)
        {
            return;
        }
        data *temp = &root;
        for (char c : word)
        {
            int i = c - 'a';
            if (NULL == temp->node[i])
            {
                temp->node[i] = new data;
            }
            temp = temp->node[i];
            temp->letter = c;
        }
        temp->is_word = true;
    }
    string get(string word)
    {
        if ("" == word)
        {
            return "";
        }
        data *temp = &root;
        for (int i = 0; i < word.size(); i++)
        {
            temp = temp->node[word[i] - 'a'];
            if (!temp)
            {
                break;
            }
            if (temp->is_word)
            {
                return word.substr(0,i+1);
            }
        }
        return word;
        
    }
    data root;

};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (auto word: dictionary)
        {
            root.add(word);
        }
        string rooted_sentence;
        int i = 0;
        while ( i < sentence.size())
        {
            //cout << "i = " << i << endl;
            if (sentence[i] != ' ')
            {
                size_t space_index = sentence.find(" ", i);
                //cout << "space_index = " << space_index << endl;
                string word = sentence.substr(i, space_index - i);
                //cout << "word = " << word << endl;
                string temp = root.get(word);
                //cout << "root find = " << temp << endl;
                rooted_sentence += temp;
                i = space_index;
            }
            else
                rooted_sentence += sentence[i++];
            
        }
        return rooted_sentence;
    }
    trie root;
};