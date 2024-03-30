/*
2402 https://leetcode.com/problems/meeting-rooms-iii/submissions/1205940364/
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

 

Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 
Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 

Constraints:

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.
[[12,44],[27,37],[48,49],[46,49],[24,44],[32,38],[21,49],[13,30],]
[[12,44],[13,30],[21,49],[24,44],[27,37],[32,38],[46,49],[48,49],]
meeting 0[12,44],
    sched at [12,44], in 0
meeting 1[13,30],
    sched at [13,30], in 1
meeting 2[21,49],
    sched at [21,49], in 2
meeting 3[24,44],
    sched at [24,44], in 3
meeting 4[27,37],
    used size: 4, next ending at 30 in room 1
    sched at [27,67], in 1
meeting 5[32,38],
    used size: 4, next ending at 44 in room 0
    sched at [32,82], in 0
meeting 6[46,49],
    used size: 4, next ending at 44 in room 3
    sched at [46,49], in 3
meeting 7[48,49],
    used size: 4, next ending at 49 in room 2
    sched at [48,98], in 2
room 0 used 2times 
room 1 used 2times 
room 2 used 2times 
room 3 used 2times
 
Runtime
2613
ms
Beats
5.01%
of users with C++
Memory
636.86
MB
Beats
5.09%
of users with C++
*/

class Solution {
public:
    // void print2Darr(vector<vector<int>>& meetings)
    // {
    //     cout <<"[";
    //     for (auto & meet: meetings)
    //     {
    //         cout << "[" << meet[0] <<","<<meet[1]<<"],";
    //     }
    //     cout <<"]" <<endl;

    // }
    static bool myfunction (vector<int> i,vector<int> j) { return (i[0]<j[0]); }
    int mostBooked(int n, vector<vector<int>>& meetings) {

        priority_queue<pair<unsigned int,unsigned int>, vector<pair<unsigned int,unsigned int>>, greater<pair<unsigned int,unsigned int>>> min_heap_used;
        priority_queue<int, vector<int>, greater<int>> min_heap_free;
        // print2Darr(meetings);
        std::sort (meetings.begin(), meetings.end(), myfunction);
        // print2Darr(meetings);
        vector<int> use_cnt(n,0);
        for (int i =1; i < n; i++)
        {
            min_heap_free.push(i);
        }
        min_heap_used.push({meetings[0][1], 0});
        use_cnt[0]++;
        int mostBooked = 0;
        // cout << "meeting "<< 0 << " [" << meetings[0][0] <<","<<meetings[0][1]<<"],"<< endl;
        // cout << "    sched at [" << meetings[0][0] <<","<<meetings[0][1]<<"], in "<< 0<< endl;
        for (int sched = 1; sched < meetings.size(); sched++)
        {
            //if there is a free room and next available used room is delayed
            //grab the free room
            unsigned int start = meetings[sched][0];
            unsigned int end = meetings[sched][1];
            
            // cout << "meeting "<< sched << " [" << meetings[sched][0] <<","<<meetings[sched][1]<<"],"<< endl;
            if (min_heap_used.size())//see if any room can be or needs to be freed
            {
                auto next_ending = min_heap_used.top();
                //if no free rooms and no meeting has ended then offset the meeting time
                if (min_heap_free.size() == 0 && next_ending.first > start)
                {
                    end += (next_ending.first - start);
                }
                while(min_heap_used.size() && 
                      (next_ending.first <= start) || min_heap_free.size() == 0)
                {
                    // cout << "    used size: "<<min_heap_used.size() << ", next ending at "<<next_ending.first<< 
                    // " in room "<<next_ending.second << endl;
                    min_heap_used.pop();
                    min_heap_free.push(next_ending.second);
                    if (min_heap_used.size())
                    {    
                        next_ending = min_heap_used.top();
                    }

                }
            }
            auto free_room = min_heap_free.top();
            min_heap_free.pop();
            use_cnt[free_room]++;
            min_heap_used.push({end, free_room});
            // cout << "    sched at [" << start <<","<<end<<"], in "<< free_room<< endl;
        }
        for (int room = 0; room < n; room++)
        {
            // cout << "room "<< room << " used " << use_cnt[room] << " times \n";
            if (use_cnt[room] > use_cnt[mostBooked])
            {
                mostBooked = room;
            }
        }
        return mostBooked;
    }
};

/*
Runtime
192
ms
Beats
99.97%
of users with C++
Memory
104.14
MB
Beats
34.42%
of users with C++

from submissions
*/
const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
    typedef pair<long long, long long> Meeting;
    typedef pair<int, long long> RoomTaken;

    template <typename T>
    class SortByEndTime {
    public:
        bool operator()(const T& a, const T& b) {
            return a.second > b.second;
        }
    };
    
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<Meeting> mp;
        mp.reserve(meetings.size());
        for(int i = 0; i < meetings.size(); ++i)
            mp.push_back({meetings[i][0], meetings[i][1]});
        
        // sort for start times
        sort(mp.begin(), mp.end(), [](const Meeting& a, const Meeting& b) {
            return a.first < b.first;
        });

        vector<int> roomUsage(n, 0);
        priority_queue<int, vector<int>, greater<int>> roomQueue;
        for(int i = 0; i < n; ++i)
            roomQueue.push(i);
        
        // room, endtime
        priority_queue<RoomTaken, vector<RoomTaken>, SortByEndTime<RoomTaken>> takenPQ;

        long long time = mp[0].first;
        int delayed = 0;
        int most = 0, mostUsed = 0;
        for(int i = 0; i < mp.size(); ) {
            auto& meeting = mp[i];
            time = max(time, meeting.first);

            while(!takenPQ.empty() && takenPQ.top().second <= time) {
                auto& top = takenPQ.top();
                // free up room
                //cout << "freed up room: " << top.first << endl;
                roomQueue.push(top.first);
                takenPQ.pop();
            }

            // we have free rooms left
            if (roomQueue.size() > 0) {
                auto freeRoom = roomQueue.top();
                roomQueue.pop();
                roomUsage[freeRoom]++;
                if (roomUsage[freeRoom] >= most) {
                    most = roomUsage[freeRoom];
                }
                //time = max(time, meeting.first);
                takenPQ.push({freeRoom, time + meeting.second - meeting.first});
                //cout << freeRoom << " taken from " << time << " until " << time + meeting.second - meeting.first << endl;
                ++i;
            } else {
                // wait until any room gets empty
                time = takenPQ.top().second;
                //cout << "jump to time: " << time << endl;
                while(!takenPQ.empty() && takenPQ.top().second == time) {
                    auto& top = takenPQ.top();
                    // free up room
                    //cout << "freed up room: " << top.first << endl;
                    roomQueue.push(top.first);
                    takenPQ.pop();
                }
            }
        }

        mostUsed = 0;
        for(int i = 0; i < roomUsage.size(); ++i) {
            if (roomUsage[i] == most) {
                return i;
            }
        }

        return mostUsed;
    }
};