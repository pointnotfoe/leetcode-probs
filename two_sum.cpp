/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/two-sum/
*/
class Solution {
public:
    //[2,3,4,5,6,7], 10
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                    cout <<" first index  = " <<i<<endl;
                    cout <<" second index = " <<j<<endl;
                    return indices;
                }
                    
            }
        }
        return indices;
        
    }
};

int main()
{
    Solution two_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    vector<int> answer = test_data.twoSum(test_data,64);

    return 0;

}