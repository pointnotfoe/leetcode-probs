/*
378. Kth Smallest Element in a Sorted Matrix
Solved
Medium
Topics
Companies
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
 

Follow up:

Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.
*/
/*
//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/1322101/c-java-python-maxheap-minheap-binary-search-picture-explain-clean-concise/
Runtime
64
ms
Beats
8.39%
of users with C++
Memory
24.18
MB
Beats
7.02%
of users with C++
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> min_heap;
        for (int r = 0; r < min(k, m); r++)
        {
            min_heap.push({matrix[r][0], r, 0});
        }
        for (int i = 1; i <= k; i++)
        {
            auto top = min_heap.top();
            min_heap.pop();
            int r = top[1];
            int c = top[2];
            ans = top[0];
            if (c+1 < n)
            {
                min_heap.push({matrix[r][c+1], r, c+1});
            }
        }
        return ans;
    }
};

//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/1322101/c-java-python-maxheap-minheap-binary-search-picture-explain-clean-concise/
// class Solution { // 20 ms, faster than 98.92%
// public:
//     int m, n;
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
//         int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;
//         while (left <= right) {
//             int mid = (left + right) >> 1;
//             int cnt_le = countLessOrEqual(matrix, mid);
//             cout << left << " " << right << " " << mid << " " << cnt_le << " " << k << endl;
//             if (cnt_le >= k) {
//                 ans = mid;
//                 right = mid - 1; // try to looking for a smaller value in the left side
//             } else left = mid + 1; // try to looking for a bigger value in the right side
//         }
//         return ans;
//     }
//     int countLessOrEqual(vector<vector<int>>& matrix, int x) {
//         int cnt = 0, c = n - 1; // start with the rightmost column
//         for (int r = 0; r < m; ++r) {
//             while (c >= 0 && matrix[r][c] > x) --c;  // decrease column until matrix[r][c] <= x
//             cnt += (c + 1);
//         }
//         return cnt;
//     }
// };

//from solutions
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    // idea of kth smallest:
    // mid is kth smallest, iff
    // - num(elem < mid) < k
    // - num(elem < mid + 1) >= k
    // we can use these 2 condition to clap the elem x using BS
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size(), l = m[0][0], r = m[n - 1][n - 1];
        int mid;
        while (l <= r) {
            if (l == r)
                break;
            mid = l + ((r - l) >> 1);
            int t1 = ComputeLess(mid, n, m);
            int t2 = ComputeLess(mid + 1, n, m);
            if (k <= t1) {
                // mid is too big
                r = mid - 1;
            } else if (t2 < k) {
                // mid is too small
                l = mid + 1;
            } else {
                // t1 < k <= t2
                if (t1 == t2) { // == k
                    // mid is not in m because t1==t2
                    // we have k elem < mid, so still too many, and mid can be
                    // excluted
                    r = mid - 1;
                } else {
                    // Must be mid, why? because:
                    // because t1 < k <= t2, that means by including
                    // number mid we go from t1 < k (just enough or not enough)
                    // to t2 >= k (too many). The only delta is mid, and mid
                    // is in m. So must be mid.
                    return mid;
                }
            }
        }
        return l;
    }

    // strictly less
    int ComputeLess(int x, int n, const vector<vector<int>>& m) {
        int i = n - 1, j = 0, total = 0;
        while (0 <= i && i < n && 0 <= j && j < n) {
            if (x > m[i][j]) {
                total += (i + 1);
                ++j;
            } else {
                --i;
            }
        }
        // cout << "num less than " << x << " is " << total << "\n";
        return total;
    }
};