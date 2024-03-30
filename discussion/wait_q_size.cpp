/**
 * @file wait_q_size.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
/*
//https://leetcode.com/discuss/interview-question/4699215/amazon-OA
One of the serersis assigned to serve customer requests. There are n customer requests placed sequentially in a queue, where the i^th request has a maximum waiting time denoted by wait[i]. That is, if the ith request is not served within wait[i] seconds, then the request expiresand it is removed from the queue. The server processes the request following the First In First Out (FIFO )principle. The 1st reguest is processed first, and the n^th request is served last. At each second, the first request in the queue is processed. At the next second, the processed request and any expired requests are removed from the queue.

Given the maximum waiting time of each requestdenoted by the array wait, find the number of requestspresent in the queue at every second until it is empty.
Note:

If a request is served at some time instant t, it will becounted for that instant and is removed at the nextinstant.
*The first request is processed at time = 0. A requestexpires without being processed when time = wait[il. ltmust be processed while time < wait[il. See the examplebelow for wait[3].
The initial queue represents all requests at time = Ointhe order they must be processed.

Example
The number of reguests is n = 4 and their maximum wait times are wait =[2 2 3 1].

time=0 seconds, the 1st request is served. Thenumber of requests in the queue is 4. queue =[1, 2 3,4]
time=1 second, request 1 is removed because it isprocessed, request 4(wait[3]- 1)is removed because time =wait[3]=1 which exceeds its maximum waitingtime. Also, request 2 is served. The number of reguests in the queue at time = 1 seconds is 2. queue =[2, 3].
time=2 seconds, request 2 is removed because it is processed, request 3 is served, The number of requests in the queue is 1. queue -[3].time=3 seconds, request 3 is removed because it is processed. The number of requests in the queue is0. queue =[empty].
The answer is [4, 2,1, 0]
*/
void print_map(map<int,vector<int>> m)
{
    for(auto x: m)
    {
        cout<<"{"<<x.first<<": ";
        for(auto y: x.second)
            cout<<y<<" ";
        cout<<"}, ";  
    }
    cout<<endl;  
}
vector<int> find_requests_reddit(const vector<int>& wait) 
{    
    int n = wait.size();
    vector<int> result;
    map<int,vector<int>> m;
    for(int i = 0; i < n; i++){
        m[wait[i]].push_back(i); /// O(n)
    }
    int count = n;
    int last_count = -1;
    for(int i = 0; i < n, count > 0; i++){
        // cout << "i " << i << "count " << count ;
        // print_map(m);
        if (last_count != count)
        {
            result.push_back(count);
            last_count = count;
        }
        int curr_req = wait[i];
        if(curr_req > i){
            m[curr_req].erase(m[curr_req].begin());
            count--;
        }
        if(m.find(i+1) != m.end()){
            count -= m[i+1].size();
            m.erase(i+1);
        }
    }
    if(count == 0) result.push_back(count);
    return result;
}

//mine
void print_q(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q)
{
    while(!q.empty())
    {
        cout << "{" << q.top().first << " "<< q.top().second<< "} ";
        q.pop();
    }
    cout << endl;
}
//doesn't work because cant delete randomly from heap for e.g. for wait[i] time much higher then what. count will be off
vector<int> find_requests_mine(const vector<int>& wait) 
{    
    int n = wait.size();
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    for(int i = 0; i < n; i++){
        min_heap.push(make_pair(wait[i], i));//nlogn
    }
    int cur_time = 0;
    int count = min_heap.size();
    int offset = 0;
    while (count > 0) {
        while (min_heap.size()) {
            // cout << cur_time << endl;
            // print_q(min_heap);
            auto curr = min_heap.top();
            if (curr.first <= cur_time || curr.second < cur_time) {
                min_heap.pop();
            }
            else
            {
                break;
            }
        }
        ///if wait time of current one is bigger then
        if (wait[cur_time] > cur_time + 2)
        {
            offset++;
        }
        count = min_heap.size() - offset;
        result.push_back(count);
        
        cur_time++;
    }
    return result;
}

vector<int> find_requests_mine_multimap(const vector<int>& wait) 
{    
    int n = wait.size();
    vector<int> result;
    multimap<int, int> mymm;
    for(int i = 0; i < n; i++){
        mymm.insert(make_pair(wait[i], i));//nlogn
    }
    int cur_time = 0;
    int count = mymm.size();
    int offset = 0;
    while (count > 0) {
        result.push_back(count);
        auto range_itr = mymm.equal_range(wait[cur_time]);
        for(auto it=range_itr.first; it!=range_itr.second; ++it){
        {
            if (it->second == cur_time) {
                mymm.erase(it);
            }
        }
        range_itr = mymm.equal_range(cur_time + 1);
        for(auto it=range_itr.first; it!=range_itr.second; ++it)
        {
            mymm.erase(it);
        }
        
    }
    return result;
}

//https://leetcode.com/discuss/interview-question/4699215/amazon-OA/2248904
int main() { 
    //calculate time taken by find_requests
    vector<int> test = {2,2,3,1, 10, 5, 5, 7, 9};
    cout << test.size() << " Input: ";
    for(int i: test) cout << i << " ";
    cout << endl;
    {
    auto start = chrono::high_resolution_clock::now();
    vector<int> result = find_requests_mine(test);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    chrono::duration<double, std::nano> ms_double = stop - start;
    cout << "Time taken by find_requests_mine: " << duration.count() << " nanoseconds. " << ms_double.count() << " nanoseconds" << endl;
    
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    cout << string(50, '=') <<endl;
    }
    
    {
    auto start = chrono::high_resolution_clock::now();
    vector<int> result = find_requests_reddit(test);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    chrono::duration<double, std::nano> ms_double = stop - start;
    cout << "Time taken by find_requests_reddit: " << duration.count() << " nanoseconds. " << ms_double.count() << " nanoseconds" << endl;
    
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << string(50, '=') <<endl;
    }
    return 0; 
    
}