/*
https://leetcode.com/problems/find-triangular-sum-of-an-array/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1
2221. Find Triangular Sum of an Array
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).

The triangular sum of nums is the value of the only element present in nums after the following process terminates:

Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.
For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
Replace the array nums with newNums.
Repeat the entire process starting from step 1.
Return the triangular sum of nums.

 

Example 1:


Input: nums = [1,2,3,4,5]
Output: 8
Explanation:
The above diagram depicts the process from which we obtain the triangular sum of the array.
Example 2:

Input: nums = [5]
Output: 5
Explanation:
Since there is only one element in nums, the triangular sum is the value of that element itself.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 9
Seen this question in a real interview before?
1/5
Yes
No
Accepted
102,920/130.6K
Acceptance Rate
78.8%
Topics
icon
Companies
Hint 1
Hint 2
Similar Questions
Discussion (31)
*/
/*
Runtime
239
ms
Beats
24.43%
Analyze Complexity
Memory
24.04
MB
Beats
41.12%
*/

class Solution {
public:
 
    void print(auto rem, const std::vector<int>& c)
    {
        for (std::cout << rem; const int el : c)
            std::cout << el << ' ';
        std::cout << '\n';
    }
    int triangularSum(vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        if (0 == N)
        {
            return sum;
        }
        if (1 == N)
        {
            return nums[0];
        }
        // print("start", nums);
        vector<int> nums2(N-1,0);
        vector<vector<int> *> ptrs = {&nums, &nums2};
        int arr_idx = 0;
        for (int i = 0; i < N - 1; i++)
        {
            vector<int> &src = *ptrs[arr_idx];
            vector<int> &dst = *ptrs[!arr_idx];
            for (int j = 0; j < src.size() - 1; j++)
            {
                dst[j] = (src[j] + src[j+1])%10;
            }
            dst.resize(src.size() -1);
            // print("sums: ", dst);
            arr_idx = !arr_idx;
            cout << arr_idx << endl;
        }
            // print("src: ", *ptrs[arr_idx]);
            // print("dst: ", *ptrs[!arr_idx]);
        return ptrs[arr_idx]->at(0);
    }
};
//41 ms
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        while(n>1){
            for(int i=0; i<n-1; i++) {
                nums[i] = (nums[i]+nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
    }
};

//2ms
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int sum = 0;
	int bicoffCoprime10 = 1;
	int pow2 = 0;
	int pow5 = 0;
	int pow2mod10[] = {6, 2, 4, 8};
	int n = nums.size() - 1;
	int mod10Inv[] = {0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
	// bicoff = bicoffCoprime10 * (2 ^ pow2) * (5 ^ pow5);
	for (int k = 0; k <= n /* FIXME: <= or < */; ++k) {
		if (pow2 != 0 && pow5 != 0) {
			// Nothing to do here since bicoff is divisble by 10
			// Hence nums[k] * (bicoff % 10) == 0
		} else if (pow2 == 0 && pow5 != 0) {
			int bicoffmod10 = (bicoffCoprime10 * 5) % 10;
			sum += ((bicoffmod10 * nums[k]) % 10);
		} else if (pow2 != 0 && pow5 == 0) {
			int bicoffmod10 = (bicoffCoprime10 * pow2mod10[pow2 % 4]) % 10;
			sum += ((bicoffmod10 * nums[k]) % 10);
		} else if (pow2 == 0 && pow5 == 0) {
			int bicoffmod10 = bicoffCoprime10;
			sum += ((bicoffmod10 * nums[k]) % 10);
		}

		if (k == n) {
			return sum % 10;
		}

		int nLessK = n - k;
		while (nLessK % 2 == 0) {
			++pow2;
			nLessK /= 2;
		}
		while (nLessK % 5 == 0) {
			++pow5;
			nLessK /= 5;
		}
		bicoffCoprime10 = (bicoffCoprime10 * nLessK) % 10;

		int kInvMod10 = k + 1;
		while (kInvMod10 % 2 == 0) {
			--pow2;
			kInvMod10 /= 2;
		}
		while (kInvMod10 % 5 == 0) {
			--pow5;
			kInvMod10 /= 5;
		}
		bicoffCoprime10 = (bicoffCoprime10 * mod10Inv[kInvMod10 % 10]) % 10;
	}
	return sum % 10;
    }
};