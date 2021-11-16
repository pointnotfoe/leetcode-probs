/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

---
Runtime: 1652 ms

[
[5,4,2,9,6,0,3,5,1,4,9,8,4,9,7,5,1],
[3,4,9,2,9,9,0,9,7,9,4,7,8,4,4,5,8],
[6,1,8,9,8,0,3,7,0,9,8,7,4,9,2,0,1],
[4,0,0,5,1,7,4,7,6,4,1,0,1,0,6,2,8],
[7,2,0,2,9,3,4,7,0,8,9,5,9,0,1,1,0],
[8,2,9,4,9,7,9,3,7,0,3,6,5,3,5,9,6],
[8,9,9,2,6,1,2,5,8,3,7,0,4,9,8,8,8],
[5,8,5,4,1,5,6,6,3,3,1,8,3,9,6,4,8],
[0,2,2,3,0,2,6,7,2,3,7,3,1,5,8,1,3],
[4,4,0,2,0,3,8,4,1,3,3,0,7,4,2,9,8],
[5,9,0,4,7,5,7,6,0,8,3,0,0,6,6,6,8],
[0,7,1,8,3,5,1,8,7,0,2,9,2,2,7,1,5],
[1,0,0,0,6,2,0,0,2,2,8,0,9,7,0,8,0],
[1,1,7,2,9,6,5,4,8,7,8,5,0,3,8,1,5],
[8,9,7,8,1,1,3,0,1,2,9,4,0,1,5,3,1],
[9,2,7,4,8,7,3,9,2,4,2,2,7,8,2,6,7],
[3,8,1,6,0,4,8,9,8,0,2,5,3,5,5,7,5],
[1,8,2,5,7,7,1,9,9,8,9,2,4,9,5,4,0],
[3,4,4,1,5,3,3,8,8,6,3,5,3,8,7,1,3]
]
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();//rows
        int n = grid[0].size();//columns
        //cout << "rows = " << m << ", columns = " << n << endl;
        if (n == 1 && m == 1)
        {
            return grid[0][0];
        }
        
        queue <tuple<int,int,int>> explore;//row,col,cost
        explore.push(make_tuple(0,0,grid[0][0]));
        //directions to explore {down, right} {row,column}
        int directions[2][2] = {{1,0}, {0,1}};
        bool all_positive = true;
        
        int min_cost = 0x3FFFFFFF;//min cost to beat
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] < 0)
                {
                    all_positive = false;
                }
            }
        }
        int dir = 0;
        //int walk = 1;
        
        while(!explore.empty())
        {                
            //cout << "----WALK #-------" << walk << endl;

            int cur_cost;
            //get the first node in queue
            int row;// = explore.front().first;
            int col;// = explore.front().second;
            //cur_cost = grid[row][col];
            tie(row,col,cur_cost) = explore.front();
            //delete this node from queue
            explore.pop();
            //cout<<" start: row = "<<row << ", col = "<< col << ", cost = "<< cur_cost << endl;

            int step = 1;
            while (1)
            {
                //we cant get better then the current cost so abandon this path
                if ((cur_cost > min_cost) && (all_positive == true))
                {
                    break;
                }
                //cout << "----STEP #------- " << step << endl;
                int new_row = row + directions[(dir == 0) ? 1 : 0][0];
                int new_col = col + directions[(dir == 0) ? 1 : 0][1];
                
                //check if the next step will cause a change of direction in current search
                int temp_r = row + directions[dir][0];
                int temp_c = col + directions[dir][1];   
                if(new_row >= 0 && new_row < m && 
                   new_col >= 0 && new_col < n && 
                   step == 1 &&
                   temp_r >= 0 && temp_r < m && 
                   temp_c >= 0 && temp_c < n)
                {
                    //cout<<" New start: new_row = "<<new_row << ", new_col = "<< new_col << ", cost = "<< cur_cost + grid[new_row][new_col] << endl;

                    //add to queue to explore its sorroundings
                    explore.push(make_tuple(new_row, new_col, cur_cost + grid[new_row][new_col]));
                }
                row += directions[dir][0];
                col += directions[dir][1];
                //cout <<" dir = " << dir << endl;
                //cout<<" step: row = "<<row << ", col = "<< col;

                if(row >= 0 && row < m && 
                   col >= 0 && col < n)
                {
                    cur_cost += grid[row][col];
                    //cout << ", cost = "<< cur_cost << endl;
                    if (row == m -1 && col == n-1)
                    {
                        if (cur_cost < min_cost)
                        {
                            min_cost = cur_cost;
                        }
                        break;
                    }
                    //check if the next will cause a change of direction in current search
                    temp_r = row + directions[dir][0];
                    temp_c = col + directions[dir][1];                    
                    new_row = row + directions[(dir == 0) ? 1 : 0][0];
                    new_col = col + directions[(dir == 0) ? 1 : 0][1];
                    if(new_row >= 0 && new_row < m && 
                       new_col >= 0 && new_col < n &&
                       temp_r >= 0 && temp_r < m && 
                       temp_c >= 0 && temp_c < n)
                    {
                        //cout<<" New : new_row = "<<new_row << ", new_col = "<< new_col << ", cost = "<< cur_cost + grid[new_row][new_col] << endl;

                        //add to queue to explore its surroundings
                        explore.push(make_tuple(new_row, new_col, cur_cost + grid[new_row][new_col]));
                    }
                }
                else
                {
                    //cout << ". OUT OF RANGE! Changing direction" << endl;
                    row -= directions[dir][0];
                    col -= directions[dir][1];
                    //cant go any further in this direction, so turn the other way.
                    if (dir == 0)
                    { 
                        dir = 1;
                    }
                    else
                    {
                        dir = 0;
                    }
                }
                step++;
            }
            //walk++;
        }
        return min_cost;
        
        
    }
};

/*
int main()
{
    Solution two_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    vector<int> answer = test_data.twoSum(test_data,64);

    return 0;

}
*/