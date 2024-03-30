/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/two-sum/
Time Submitted      Status      Runtime Memory  Language
02/04/2020 23:18	Accepted	144 ms	9.3 MB	cpp
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

/*
Runtime: 12 ms, faster than 85.66% of C++ online submissions for Two Sum.
Memory Usage: 11 MB, less than 28.95% of C++ online submissions for Two Sum.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;//num, index
        vector<int> result;
        for(unsigned int i = 0; i < nums.size(); i++)
        {
            auto it = seen.find(target - nums[i]);
            if(seen.end() != it)
            {
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }
            seen[nums[i]] = i;
        }
        return result;
        
    }
};

int main()
{
    Solution two_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    vector<int> answer = test_data.twoSum(test_data,64);

    return 0;

}