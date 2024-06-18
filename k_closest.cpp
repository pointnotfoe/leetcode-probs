/*
973. K Closest Points to Origin
Solved
Medium
Topics
Companies
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 <= xi, yi <= 104

*/
/*Runtime
140
ms
Beats
73.93%
of users with C++
Memory
65.98
MB
Beats
82.90%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        int size = points.size();
        if (!size || !k)
        {
            return result;
        }
        int dis;
        priority_queue<pair<int, int>> max_heap;
        for (int i = 0; i < size; i++)
        {
            dis = pow(points[i][0], 2) + pow(points[i][1], 2);
            if (max_heap.size() < k)
            {
                max_heap.push({dis, i});
            }
            else if (max_heap.top().first > dis)
            {
                max_heap.pop();
                max_heap.push({dis, i});
            }
        }
        while (max_heap.size())
        {
            result.push_back(points[max_heap.top().second]);
            max_heap.pop();
        }
        return result;
    }
};
//check others here too https://leetcode.com/problems/k-closest-points-to-origin/solutions/221532/c-stl-quickselect-priority-queue-and-multiset/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};