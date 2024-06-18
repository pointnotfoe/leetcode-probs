/*
https://leetcode.com/problems/interval-list-intersections/description/
986. Interval List Intersections
Solved
Medium
Topics
Companies
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

Example 1:


Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: []
 

Constraints:

0 <= firstList.length, secondList.length <= 1000
firstList.length + secondList.length >= 1
0 <= starti < endi <= 109
endi < starti+1
0 <= startj < endj <= 109 
endj < startj+1
*/

/*
Runtime
20
ms
Beats
78.69%
of users with C++
Memory
22.20
MB
Beats
65.36%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int first = 0, second = 0;
        int first_size = firstList.size();
        int second_size = secondList.size();
        int inter_start, inter_end;
        int first_start, first_end;
        int second_start, second_end;
        while(first < first_size && second < second_size)
        {
            first_start = firstList[first][0];
            first_end = firstList[first][1];
            second_start = secondList[second][0]; 
            second_end = secondList[second][1];
            if (first_start >= second_start && first_start <= second_end || 
                second_start >= first_start && second_start <= first_end)
            {
                inter_start = max(first_start, second_start);
                inter_end = min(first_end, second_end);
                //cout << first << ", " << second << ": {" << inter_start<< ", " << inter_end << "}" << endl;
                result.push_back({inter_start, inter_end});
            }
            if (first_end <= second_end)
            {
                first++;
            }
            if (second_end <= first_end)
            {
                second++;
            }
        }
        return result;
    }
};


/*https://leetcode.com/problems/interval-list-intersections/solutions/646988/c-easy-6-lines-two-pointer-100/
*/
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> v;
        int i=0,j=0;
        while(i<A.size() && j<B.size()){
            int l=max(A[i][0], B[j][0]);
            int u=min(A[i][1], B[j][1]);
            if(l<=u) v.push_back({l,u});
            if(A[i][1] < B[j][1])   i++;
            else j++;
        }
        return v;
    }
    
/*https://leetcode.com/problems/interval-list-intersections/solutions/231108/o-n-merge-sort/
*/
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    for (auto i = 0, j = 0; i < A.size() && j < B.size();) {
        if (A[i][1] < B[j][0])
            ++i;
        else if (B[j][1] < A[i][0])
            ++j;
        else {
            res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            if (A[i][1] < B[j][1])
                ++i;
            else
                ++j;
        }
    }
    return res;
} 

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    for (auto i = 0, j = 0; i < A.size() && j < B.size(); A[i][1] < B[j][1] ? ++i : ++j) {
        auto start = max(A[i][0], B[j][0]);
        auto end = min(A[i][1], B[j][1]);
        if (start <= end) 
            res.push_back({start, end});
    }
    return res;    
}