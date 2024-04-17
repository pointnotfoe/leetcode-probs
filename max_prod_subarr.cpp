/*
152 Maximum Product Subarray
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/
/*
Wrong Answer
163 / 190 testcases passed

Editorial
Input
nums =
[1,0,-1,2,3,-5,-2]

Use Testcase
Output
30
Expected
60
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr = nums[0];
        int result = curr;
        int total = curr;
        int last_neg = curr;
        const unsigned int length = nums.size();
        for (unsigned int i = 1; i < length; ++i)
        {
            if (nums[i] < 0 && last_neg < 0)
            {
                curr = max(last_neg*nums[i], nums[i]);
                last_neg = nums[i];
            }
            else
            {
                last_neg *= nums[i];
                last_neg = last_neg ? last_neg : 1;
                curr = max(curr*nums[i], nums[i]);
            }
            result = max(result, curr);
            total *= nums[i];
        }
        result = max(result, total);
        return result;
    }
};


/*lee215
https://leetcode.com/problems/maximum-product-subarray/solutions/183483/java-c-python-it-can-be-more-simple/
*/
Also wrote in C++ version
O(N) time O(1) space

    int maxProduct(vector<int> A) {
        int n = A.size(), res = A[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * A[i];
            r =  (r ? r : 1) * A[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }
    
    /*mzchen
    https://leetcode.com/problems/maximum-product-subarray/solutions/48230/possibly-simplest-solution-with-o-n-time-complexity/
    */
    int maxProduct(int A[], int n) {
    // store the result that is the max we have found so far
    int r = A[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}