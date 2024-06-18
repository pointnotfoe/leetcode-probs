/*
https://leetcode.com/problems/word-search/description/
79. Word Search
Solved
Medium
Topics
Companies
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/
/*
Runtime
1030
ms
Beats
14.26%
of users with C++
Memory
11.45
MB
Beats
46.60%
of users with C++
*/
class Solution {
public:
    const int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    bool dfs_exist(vector<vector<char>>& board, string word, int word_idx, int row, int col) {
        // cout << row << " " << col << " " << word_idx << endl;
        if (word_idx >= word.size())
        {
            return true;
        }
        if (row < 0 || col < 0 || row >= board.size() || col >= board[row].size() || 
            (word_idx < word.size() && (board[row][col] == '*' || board[row][col] != word[word_idx])))
        {
            return false;
        }
        board[row][col] = '*';
        bool found = false;
        for (int step = 0; step < 4; step++)
        {
            if (dfs_exist(board, word, word_idx + 1, row + dir[step][0], col + dir[step][1]))
            {    
                found = true;
                break;
            }
        }
        board[row][col] = word[word_idx];
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size())
        {
            return false;
        }
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[row].size(); col++)
            {
                if (dfs_exist(board, word, 0, row, col))
                    return true;
            }
        }
        return false;
    }
};

/*
Runtime
324
ms
Beats
66.59%
of users with C++
Memory
9.66
MB
Beats
79.87%
of users with C++
*/
class Solution {
public:
    bool dfs_exist(int row, int col) {
        if (word_idx >= word_size)
        {
            return true;
        }
        if (row < 0 || col < 0 || row >= board_rows || col >= board_cols || 
            (word_idx < word_size && board_ptr->at(row).at(col) != word_copy[word_idx]))
        {
            return false;
        }
        board_ptr->at(row).at(col) = '*';
        bool found = false;
        word_idx++;
        for (int step = 0; step < 4; step++)
        {
            if (dfs_exist(row + dir[step][0], col + dir[step][1]))
            {    
                found = true;
                break;
            }
        }
        word_idx--;
        board_ptr->at(row).at(col) = word_copy[word_idx];
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size())
        {
            return false;
        }
        word_copy = word;
        board_ptr = &board;
        word_size = word.size();
        board_rows = board.size();
        board_cols = board[0].size();
        
        for (int row = 0; row < board_rows; row++)
        {
            for (int col = 0; col < board_cols; col++)
            {
                word_idx = 0;
                if (dfs_exist(row, col))
                    return true;
            }
        }
        return false;
    }
    string word_copy;
    int word_size;
    int board_rows;
    int board_cols;
    int word_idx;
    const int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    vector<vector<char>>* board_ptr;
};