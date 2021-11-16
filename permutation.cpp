/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/permutations/submissions/
*/

class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
          } while ( std::next_permutation(nums.begin(),nums.end()) );
        return result;
    }
};
/*
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/
int main()
{
    Solution two_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    vector<int> answer = test_data.twoSum(test_data,64);

    return 0;

}