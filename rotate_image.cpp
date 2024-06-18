/*https://leetcode.com/problems/rotate-image/description/
48. Rotate Image
Solved
Medium
Topics
Companies
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/
/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.76
MB
Beats
21.35%
of users with C++
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int one ,two, three, four;
        int size = matrix.size();//3
        int total_segments = size/2;//1
        for (int segment = 0; segment < total_segments; segment++)
        {
            for (int point = segment; point < size -1 - segment; point++) //= total_segments - segment
            {
                one = matrix[segment][point];//fix row, move col forward
                two = matrix[point][size - 1 - segment];//move row down, fix col
                three = matrix[size - 1 - point][segment];//move row up, fix col 
                four = matrix[size - 1 - segment][size - 1 - point];//fix row, mov col backward
                
                matrix[segment][point] = three;
                matrix[point][size - 1 - segment] = one;
                matrix[size - 1 - point][segment] = four;
                matrix[size - 1 - segment][size - 1 - point] = two;
            }
        }
    }
};

/*https://leetcode.com/problems/rotate-image/solutions/3440564/animation-understand-in-30-seconds/
🚀[Animation] - Understand in 30 seconds

universe98
May LeetCoding Challenge
956
49913
Apr 21, 2023
C++
Array
Matrix
upvoting the answer will motivate me to create more animations! Thanks.

Approach
2 Steps to rotate image

Transpose the matrix

*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0;i<row; i++){
            for(int j=0; j<=i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};