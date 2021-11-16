/**
Autor: pointnotfoe
Leetcode:https://leetcode.com/problems/implement-trie-prefix-tree/submissions/

Runtime: 92 ms, faster than 22.81% of C++ online submissions for Implement Trie (Prefix Tree).
Memory Usage: 43.5 MB, less than 79.91% of C++ online submissions for Implement Trie (Prefix Tree).
*/
typedef struct trie_tree_t
{
    trie_tree_t() : full_word(false), char_hash()
    {
    
    }
    bool full_word;
    unordered_map<char, trie_tree_t*> char_hash;
}trie_tree_t;

class Trie {
public:
    Trie() :_trie_root(){
        
    }
    
    void insert(string word) {
        trie_tree_t *temp = &_trie_root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->char_hash[word[i]] == nullptr)
                temp->char_hash[word[i]] = new trie_tree_t();
            temp = temp->char_hash[word[i]];
        }
        temp->full_word = true;
    }
    
    bool search(string word) {
        trie_tree_t *temp = &_trie_root;
        int i;
        for (i = 0; i < word.size(); i++)
        {
            if (temp->char_hash[word[i]] == nullptr)
                break;           
            temp = temp->char_hash[word[i]];
        }
        return temp->full_word && i == word.size(); 
        
    }
    
    bool startsWith(string prefix) {
        trie_tree_t *temp = &_trie_root;
        int i;
        for (i = 0; i < prefix.size(); i++)
        {
            if (temp->char_hash[prefix[i]] == nullptr)
                break;           
            temp = temp->char_hash[prefix[i]];
        }
        return i == prefix.size(); 
    }
    
    trie_tree_t _trie_root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 