/**
Autor: pointnotfoe
Leetcode:https://leetcode.com/problems/set-matrix-zeroes/submissions/
*/
/*
Runtime: 39 ms, faster than 15.52% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.4 MB, less than 12.34% of C++ online submissions for Set Matrix Zeroes.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        for (int r = 0; r < matrix.size(); r++)
        {
            for (int c = 0; c < matrix[r].size(); c++)
            {
                if (matrix[r][c] == 0)
                {
                    rows.insert(r);
                    cols.insert(c);
                }
            }
        }
        for (const auto& r: rows)
        {
            for (int c = 0; c < matrix[r].size(); c++)
            {
                matrix[r][c] = 0;
            }
        }
        for (const auto& c: cols)
        {
            for (int r = 0; r < matrix.size(); r++)
            {
                matrix[r][c] = 0;
            }
        }

    }
};

/*Using platform solution
Runtime: 35 ms, faster than 30.76% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.3 MB, less than 55.49% of C++ online submissions for Set Matrix Zeroes.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_col = false;
        for (int r = 0; r < matrix.size(); r++)
        {
            if (matrix[r][0] == 0)
                first_col = true;
            for (int c = 1; c < matrix[r].size(); c++)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        for (int r = 1; r < matrix.size(); r++)
        {
            for (int c = 1; c < matrix[r].size(); c++)
            {
                if (matrix[r][0] == 0 || matrix[0][c] == 0)
                {
                    matrix[r][c] = 0;
                }
            }
        }
        if (matrix[0][0] == 0)
            for (int c = 0; c < matrix[0].size(); c++)
            {
                matrix[0][c] = 0;
            }
        if (true == first_col)
            for (int r = 0; r < matrix.size(); r++)
            {
                matrix[r][0] = 0;
            }

    }
};
*/