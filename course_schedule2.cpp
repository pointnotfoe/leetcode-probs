/*
207. Course Schedule
Solved
Medium
Topics
Companies
Hint
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

/*
Runtime
14
ms
Beats
75.40%
of users with C++
Memory
18.56
MB
Beats
22.86%
of users with C++
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0)
            return true;
        if (prerequisites.size() <= 0)
            return true;
        unordered_map<int, list<int>> depend;
        unordered_map<int, int> depend_count;
        for (auto & pair : prerequisites)
        {
            depend[pair[1]].push_back(pair[0]);
            depend_count[pair[0]]++;
            depend_count[pair[1]];
        }
        queue<int> fifo;
        for (int course = 0; course < numCourses; course++)
        {
            depend_count[course];//incase course is not in dependency list
            if (depend_count[course] == 0)
            {
                fifo.push(course);
            }
        }
        // for (auto &[course, needs] : depend)
        // {
        //     if (needs.size() == 0)
        //     {
        //         fifo.push(course)
        //     }
        // }
        int courses = 0;
        while (fifo.size())
        {
            courses++;
            int course = fifo.front();
            fifo.pop();
            auto &depend_list = depend[course];
            while (depend_list.size())
            {
                int dependent_course = depend_list.front(); 
                depend_list.pop_front();
                if (0 == --depend_count[dependent_course])
                    fifo.push(dependent_course);
            }
        }
        return courses == numCourses;
    }
};

//https://leetcode.com/problems/course-schedule/solutions/162743/java-c-python-bfs-topological-sorting-o-n-e/
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(n);
        vector<int> degree(n, 0), bfs;
        for (auto& e : prerequisites)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        return bfs.size() == n;
    }
    
//fastest
class Solution {
public:

    bool dfs(int x, vector<int>& visited, vector<vector<int>> &graph)
    {
        visited[x]=1;
        bool t = false;
        for(int i=0;i<graph[x].size();i++)
        {
            if(visited[graph[x][i]]==0)
                t = t || dfs(graph[x][i],visited,graph);
            
            if(visited[graph[x][i]]==1)
                return true;
            if(visited[graph[x][i]]==2)
                continue;
        }
        visited[x]=2;
        return t;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=prerequisites.size();
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses,0);

        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                if(dfs(i,visited,graph))
                    return false;
            }
        }
        return true;


    }
};