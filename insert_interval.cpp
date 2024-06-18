/*https://leetcode.com/problems/insert-interval/description/
57. Insert Interval
Solved
Medium
Topics
Companies
Hint
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/

/*
Runtime
13
ms
Beats
45.63%
of users with C++
Memory
20.77
MB
Beats
14.08%
of users with C++
*/
class Solution {
public:
    enum search_state
    {
        STATE_INIT,
        STATE_START,
        STATE_END
    };
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() < 1)
        {
            return {newInterval};
        }
        if (newInterval.size() < 1)
        {
            return intervals;
        }
        vector<vector<int>> result;
        search_state state = STATE_INIT;
        int start;
        int end;
        for (auto &current : intervals)
        {
            start = current[0];
            end = current[1];
            if (state == STATE_INIT)
            {
                if (newInterval[0] <= start || newInterval[0] <= end)
                {
                    if (newInterval[1] < start || newInterval[1] <= end)
                    {
                        state = STATE_END;
                        if (newInterval[1] < start)
                        {
                            result.push_back({newInterval[0], newInterval[1]});
                        }
                        else
                        {
                            start = min(start, newInterval[0]);
                            end = max(end, newInterval[1]);
                        }
                        result.push_back({start, end});
                    }
                    else
                    {
                        state = STATE_START;
                    }
                    newInterval[0] = min(start, newInterval[0]);
                }
                else
                {
                    result.push_back({start, end});
                }
            }
            else if (state == STATE_START)
            {
                if (newInterval[1] <= start)
                {
                    state = STATE_END;
                    if (newInterval[1] == start)
                    {
                        result.push_back({newInterval[0], end});
                    }
                    else
                    {
                        result.push_back({newInterval[0], newInterval[1]});
                        result.push_back({start, end});
                    }
                }
                else if (newInterval[1] <= end)
                {
                    result.push_back({newInterval[0], max(newInterval[1], end)});
                    state = STATE_END;
                }
            }
            else
            {
                result.push_back({start, end});
            }
        }
        if (state == STATE_START || state == STATE_INIT)
        {
            result.push_back({newInterval[0], max(newInterval[1], end)});
        }
        return result;
    }
};


/*
99.16% faster | proper explaination| c++ solution| O(N)

kritika_12
1882
27406
Jul 09, 2021
C++
C
Here 3 cases will arive:

Non Overlapping intervals before given newInterval -> push into the ans vector
Overlapping of intervals and newInterval update new interval
starting point of newInterval will be min of the interval starting point
or starting point of newInterval
Ending point will be the max of interval ending point or newInterval end point.
Non overlapping intervals after the newintervals have been merged -> push ito ans vector
Time complexity - O(N)
space complexity - O(1)

Also, please do not use sorting algo here because we have already provided with sorted list.
*/
class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        //case 1: no overlapping case before the merge intervals
		//compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }                           
		//case 2: overlapping case and merging of intervals
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // case 3: no overlapping of intervals after newinterval being merged
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};