/*
Author: pointnotfoe
Leetcode: https://leetcode.com/problems/non-overlapping-intervals/
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104


Input: [[0,2],[1,3],[2,4],[3,5],[4,6]]	
Output: 2
Example 2:

Runtime: 787 ms, faster than 27.27% of C++ online submissions for Non-overlapping Intervals.
Memory Usage: 115.2 MB, less than 8.04% of C++ online submissions for Non-overlapping Intervals.
Next challenges:
*/

class Solution {
public:
    
  struct endCompare {//sort by max heap
    bool operator()(const vector<int> &x, const vector<int> &y) { return x[1] < y[1]; }
  };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return 0;
    }

    // sort the intervals by start time, earlies meeting first
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &x, const vector<int> &y) { return x[0] < y[0]; });

    int conflict_count = 0;
    priority_queue<vector<int>, vector<vector<int>>, endCompare> maxHeap;
    for (auto interval : intervals) {
      // remove all intervals that have ended
      while (!maxHeap.empty() && interval[0] >= maxHeap.top()[1]) {
        maxHeap.pop();
      }
      // add the current interval into the maxHeap
      maxHeap.push(interval);
      // if size is bigger then 1 that means we have a conflict
        //remove the top interval since that has the furthest end time
        if (maxHeap.size() > 1)
        {
            maxHeap.pop();//remove the top conflicting interval
            conflict_count++;
        }
    }

    return conflict_count;    
    }
};