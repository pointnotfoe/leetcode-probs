/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/number-of-islands/
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

input: [["1","1","1"],["0","1","0"],["1","1","1"]]
Output 1


Runtime: 44 ms, faster than 6.74% of C++ online submissions for Number of Islands.
Memory Usage: 15.1 MB, less than 6.62% of C++ online submissions for Number of Islands.
*/
class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        map<int, int> seen;
        vector<set<int>> islands;
        //nodes to explore
        queue<pair<int,int>> explore;
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (int i = 0; i < m; i++)
        {
            int n = grid[i].size();
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '0')
                {
                    continue;
                }
                
                int src_xy = i*n + j;//current coordinate hash
                if (seen.find(src_xy) != seen.end())//if not seen then explore
                {
                    continue;
                }
                explore.push(make_pair(i,j));
                
                grid[i][j] = '0';
                
                seen.insert(pair<int,int>(src_xy, islands.size()));
                set<int> temp;
                temp.insert(src_xy);
                islands.push_back(temp);
        
                while(!explore.empty())
                {
                    //get the first node in queue
                    int row = explore.front().first;
                    int col = explore.front().second;
                    //delete this node from queue
                    explore.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int new_row = row + directions[dir][0];
                        int new_col = col + directions[dir][1];
                        int xy = new_row*n + new_col;//current coordinate hash
                        if(new_row >= 0 && new_row < m &&
                           new_col >= 0 && new_col < n &&
                           (grid[new_row][new_col] != '0') &&
                           (seen.find(xy) == seen.end()))
                        {
                            
                            grid[new_row][new_col] = '0';
                            //add to queue to explore its sorroundings
                            explore.push(make_pair(new_row, new_col));
                            //add current node to src node's set
                            seen.insert(pair<int,int>(xy, seen[src_xy]));
                            islands[seen[src_xy]].insert(xy);   
                        }
                    }
                }
                
                
            }
        }
        return islands.size();
    }
};

//https://leetcode.com/problems/number-of-islands/discuss/56589/C%2B%2B-BFSDFS --------------------------------------
//I saw many peope post DFS solutions but fewer BFS ones. So I wrote one below. Each time when I see a '1', I increment the counter and then erase all connected '1's using a queue.
//Runtime: 16 ms, faster than 58.21% of C++ online submissions for Number of Islands.
//Memory Usage: 10.2 MB, less than 24.32% of C++ online submissions for Number of Islands.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};

//Or I can erase all the connected '1's using DFS.
//Runtime: 12 ms, faster than 93.51% of C++ online submissions for Number of Islands.
//Memory Usage: 9.6 MB, less than 62.92% of C++ online submissions for Number of Islands.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};
//-------------------------------------------------------------------------