/*
https://leetcode.com/problems/search-suggestions-system/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1
1268. Search Suggestions System
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
 

Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
400,819/616K
Acceptance Rate
65.1%
Topics
icon
Companies
Hint 1
Hint 2
Hint 3
Discussion (55)

Runtime 144 ms Beats 30.79%
Memory 134.34 MB Beats 24.49%
*/
class Solution {
    typedef struct trie
    {
        char c;
        set<string> prodIdx;
        unordered_map<char, trie *> sub;
    }trie;
    trie root;
public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res(searchWord.size());
        for (auto i = 0; i < products.size(); ++i)
        {
            trie *node = &root;
            for (auto j = 0; j < products[i].size(); ++j)
            {
                char c = products[i][j];
                if (!node->sub[c])
                {
                    node->sub[c] = new trie;
                }
                node = node->sub[c];
                node->prodIdx.insert(products[i]);
            }
        }
        trie *node = &root;
        for (auto i = 0; i < searchWord.size(); ++i)
        {
            char c = searchWord[i];
            if (!node->sub[c])
            {
                break;
            }
            node = node->sub[c];
            for (auto &idx : node->prodIdx)
            {
                res[i].push_back(idx);
                if (res[i].size() == 3)
                {
                    break;
                }
            }
        }
        return res;
    }
};

/*
https://leetcode.com/problems/search-suggestions-system/solutions/436674/c-java-python-sort-and-binary-search-the-prefix/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1
[C++/Java/Python] Sort and Binary Search the Prefix

lee
365 Days Badge
74049
Nov 24, 2019
Intuition
In a sorted list of words,
for any word A[i],
all its sugested words must following this word in the list.

For example, if A[i] is a prefix of A[j],
A[i] must be the prefix of A[i + 1], A[i + 2], ..., A[j]

Explanation
With this observation,
we can binary search the position of each prefix of search word,
and check if the next 3 words is a valid suggestion.


Complexity
Time O(NlogN) for sorting
Space O(logN) for quick sort.

Time O(logN) for each query
Space O(query) for each query
where I take word operation as O(1)

*/
    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, A.end(), cur);
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                string& s = *(it + i);
                if (s.find(cur)) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }