/**
Autor: zhoubowei
Leetcode: https://leetcode.com/problems/flood-fill/
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) 
    {
        if (new_color == image[sr][sc])
        {
            return image;
        }
        
        int current_color = image[sr][sc];
        int max_row = image.size();
        int max_col = image[0].size();
        //nodes to explore
        queue<pair<int,int>> explore;
        explore.push(make_pair(sr,sc));
        //directions to explore {up, down, right, left}{row,column}
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        //paint the starting point
        image[sr][sc] = new_color;
        
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
                if(new_row >= 0 && new_row < max_row &&
                   new_col >= 0 && new_col < max_col &&
                   current_color == image[new_row][new_col])
                {
                    //paint this point
                    image[new_row][new_col] = new_color;
                    //add to queue to explore its sorroundings
                    explore.push(make_pair(new_row, new_col));
                }
            }
        }
        
        
        
        return image;
    }
};

//image = [
//[1,1,1],
//[1,1,0],
//[1,0,1]
//]


int main()
{
    Solution two_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    vector<int> answer = test_data.twoSum(test_data,64);

    return 0;

}