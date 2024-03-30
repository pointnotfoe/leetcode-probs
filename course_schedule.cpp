/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/course-schedule-ii/
Runtime: 11 ms, faster than 15.45% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 11.1 MB, less than 29.96% of C++ online submissions for Search in Rotated Sorted Array.
*/

/*
Runtime: 60 ms, faster than 8.43% of C++ online submissions for Course Schedule II.
Memory Usage: 15.6 MB, less than 12.47% of C++ online submissions for Course Schedule II.
*/
//adapted from platform solution 
class Solution {
public:
    //adjacency list, all the courses for which first is a requirement
    unordered_map<int, vector<int>> adj;
    //num of prerequisites for a course
    unordered_map<int,int> indegree;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<int> result;
        //if no pre reqs then take the courses directly
        if (numCourses > 0 && prereq.size() == 0)
        {
            for (int i = 0; i < numCourses; i++)
                result.push_back(i);
            return result;
        }
        if (numCourses < 1 || prereq.size() < 1)
        {
            return result;
        }
        //for each pair of course and pre req
        for (auto v : prereq)
        {
            adj[v[1]].push_back(v[0]);//v[1] is a pre req for v[0]
            indegree[v[0]]++;//increase the course depencdency
            //add the prereq if not there, can probably just use indegree[v[1]]
            if (indegree.find(v[1]) == indegree.end())
            {
                indegree[v[1]] = 0;
            }
        }
        //e.g. numCourses = 3, prereq = [[0,1]]
        if (adj.size() < numCourses)
        {
            for (int i = 0; i < numCourses; i++)
            {
                if (indegree.find(i) == indegree.end())
                {
                    indegree[i] = 0;
                }
            }
        }
        stack<int> lifo;
        //gather all base courses i.e. ones with 0 prereqs
        for (auto i : indegree)
        {
            if (i.second == 0)
            {
                lifo.push(i.first);
            }
        }
        while(!lifo.empty())
        {
            int node = lifo.top();
            lifo.pop();
            result.push_back(node);
            auto V = adj[node];
            for (auto E : V)
            {
                //decrease dependency as we came here from one of its prereqs
                indegree[E]--;
                //add this to be processed
                if (indegree[E] == 0)
                {
                    lifo.push(j);
                }
            }
        }
        if (result.size() == numCourses)
            return result;
        else
            return {};
    }
};