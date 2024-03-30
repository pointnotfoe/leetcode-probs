/*
934: 
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.

Runtime
30
ms
Beats
82.28%
of users with C++
Memory
22.20
MB
Beats
82.63%
of users with C++
*/

class Solution {
public:
    Solution(){}
    int shortestBridge(vector<vector<int>>& grid_) {
        grid = std::move(grid_);
        bool found = false;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[row].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    dfs(row, col);
                    found = true;
                    break;
                }
            }
            if(found)
            {
                break;
            }
        }
        int step = 0;
        while(fifo.size())
        {
            int level_size = fifo.size();
            for (int node = 0; node < level_size; node++)
            {
                auto [node_r, node_c] = fifo.front();
                fifo.pop();
                for (auto &[dir_y, dir_x] : directions)
                {
                    int next_c = node_c + dir_x;
                    int next_r = node_r + dir_y;
                    if (is_oor(next_r, next_c)) 
                    {
                        continue;
                    }
                    if (grid[next_r][next_c] == 1)
                    {
                        return step;
                    }
                    if (grid[next_r][next_c] == 0)
                    {
                        grid[next_r][next_c] = -1;
                        fifo.push({next_r, next_c});
                    }
                }
            }
            if (fifo.size())
                step++;
        }
        return step;
    }
private:
    bool is_oor(int row, int col)
    {
        if (row < 0 || row >= grid.size() || 
            col < 0 || col >= grid[row].size())
        {
            return true;
        }

        return false;
    }
    void dfs(int row, int col)
    {
        if (is_oor(row, col) ||
            grid[row][col] == -1 || grid[row][col] == 0)
        {
            return;
        }
        fifo.push({row, col});
        grid[row][col] = -1;
        for (auto &[dir_y, dir_x] : directions)
        {
            dfs(row + dir_y, col + dir_x);
        }
    }
    vector<vector<int>> grid;
    const vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    queue<pair<int,int>> fifo;
};