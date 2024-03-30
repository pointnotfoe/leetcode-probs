/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/sequentially-ordinal-rank-tracker/
A scenic location is represented by its name and attractiveness score, where name is a unique string among all locations and score is an integer. Locations can be ranked from the best to the worst. The higher the score, the better the location. If the scores of two locations are equal, then the location with the lexicographically smaller name is better.

You are building a system that tracks the ranking of locations with the system initially starting with no locations. It supports:

Adding scenic locations, one at a time.
Querying the ith best location of all locations already added, where i is the number of times the system has been queried (including the current query).
For example, when the system is queried for the 4th time, it returns the 4th best location of all locations already added.
Note that the test data are generated so that at any time, the number of queries does not exceed the number of locations added to the system.

Implement the SORTracker class:

SORTracker() Initializes the tracker system.
void add(string name, int score) Adds a scenic location with name and score to the system.
string get() Queries and returns the ith best location, where i is the number of times this method has been invoked (including this invocation).
 

Example 1:

Input
["SORTracker", "add", "add", "get", "add", "get", "add", "get", "add", "get", "add", "get", "get"]
[[], ["bradford", 2], ["branford", 3], [], ["alps", 2], [], ["orland", 2], [], ["orlando", 3], [], ["alpine", 2], [], []]
Output
[null, null, null, "branford", null, "alps", null, "bradford", null, "bradford", null, "bradford", "orland"]

Explanation
SORTracker tracker = new SORTracker(); // Initialize the tracker system.
tracker.add("bradford", 2); // Add location with name="bradford" and score=2 to the system.
tracker.add("branford", 3); // Add location with name="branford" and score=3 to the system.
tracker.get();              // The sorted locations, from best to worst, are: branford, bradford.
                            // Note that branford precedes bradford due to its higher score (3 > 2).
                            // This is the 1st time get() is called, so return the best location: "branford".
tracker.add("alps", 2);     // Add location with name="alps" and score=2 to the system.
tracker.get();              // Sorted locations: branford, alps, bradford.
                            // Note that alps precedes bradford even though they have the same score (2).
                            // This is because "alps" is lexicographically smaller than "bradford".
                            // Return the 2nd best location "alps", as it is the 2nd time get() is called.
tracker.add("orland", 2);   // Add location with name="orland" and score=2 to the system.
tracker.get();              // Sorted locations: branford, alps, bradford, orland.
                            // Return "bradford", as it is the 3rd time get() is called.
tracker.add("orlando", 3);  // Add location with name="orlando" and score=3 to the system.
tracker.get();              // Sorted locations: branford, orlando, alps, bradford, orland.
                            // Return "bradford".
tracker.add("alpine", 2);   // Add location with name="alpine" and score=2 to the system.
tracker.get();              // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
                            // Return "bradford".
tracker.get();              // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
                            // Return "orland".
 

Constraints:

name consists of lowercase English letters, and is unique among all locations.
1 <= name.length <= 10
1 <= score <= 105
At any time, the number of calls to get does not exceed the number of calls to add.
At most 4 * 104 calls in total will be made to add and get.
*/

//timed out

typedef pair<int, string> info;
// auto great =[] (info const& first, info const& second)
//     {
//         return first.first == second.first? first.second < second.second : first.first > second.first;
//     }; 


class SORTracker {
public:
    SORTracker() {
        //ranking();
        query_count= 0;
        
    }
    
    void add(string name, int score) {
        info temp(score,name);
        ranking.insert(temp);//log n
    }
    
    string get() {
        auto itr = ranking.begin();
        std::advance(itr, query_count);//n
        query_count++;
        return itr->second;
        
    }
    // static auto great = [] (info const& first, info const& second)
    // {
    //     return first.first == second.first? first.second < second.second : first.first > second.first;
    // };
    struct greatcomp {
		bool operator()(info const& first, info const& second) const
			{
				return first.first == second.first? first.second < second.second : first.first > second.first;
			}
	};
    multiset<info,greatcomp> ranking;
    int query_count;
};
/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
 
 
 // my heap approach timed out
 
typedef pair<int, string> info;
// auto great =[] (info const& first, info const& second)
//     {
//         return first.first == second.first? first.second < second.second : first.first > second.first;
//     }; 


class SORTracker {
public:
    SORTracker() {
        //ranking();
        query_count= 0;
        
    }
    
    void add(string name, int score) {
        info temp(score,name);
        while (min_ranking.size() && 
               (score > min_ranking.top().first || 
                (min_ranking.top().first == score && name < min_ranking.top().second)))
        {
            max_ranking.push(min_ranking.top());
            min_ranking.pop();
        }
        max_ranking.push(temp);
        while(min_ranking.size() != query_count)
        {
            min_ranking.push(max_ranking.top());
            max_ranking.pop();
        }
        
    }
    
    string get() {
        info temp = max_ranking.top();
        max_ranking.pop();
        min_ranking.push(temp);
        query_count++;
        return temp.second;
        
    }
    struct lesscomp {
        bool operator()(info const& first, info const& second) const
        {
            return first.first == second.first? first.second > second.second : first.first < second.first;
        }
    };
    struct greatcomp {
        bool operator()(info const& first, info const& second) const
        {
            return first.first == second.first? first.second < second.second : first.first > second.first;
        }
    };
    priority_queue<info,vector<info>, lesscomp> max_ranking;
    priority_queue<info,vector<info>, greatcomp> min_ranking;
    int query_count;
};
/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
 
 //https://leetcode.com/problems/sequentially-ordinal-rank-tracker/discuss/1623474/c%2B%2B-min_heap-max_heap
class SORTracker {
    using ItemType = pair<int, string>;
public:
    SORTracker() {}
    
    void add(string name, int score) {
        min_heap.emplace(-score, name); // note here it's `-score`
        auto item = min_heap.top();
        min_heap.pop();
        max_heap.emplace(std::move(item));
    }
    
    string get() {
        auto item = max_heap.top();
        max_heap.pop();
        min_heap.emplace(item);
        return item.second;
    }
private:
    std::priority_queue<ItemType, std::vector<ItemType>, std::greater<ItemType>> max_heap;  
    std::priority_queue<ItemType> min_heap;
};

//https://leetcode.com/problems/sequentially-ordinal-rank-tracker/discuss/1623288/Decrement-Iterator-(4-lines)
class SORTracker {
public:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator it = end(s);    
    void add(string name, int score) {
        auto it1 = s.insert({-score, name}).first;
        if (it == end(s) || *it1 < *it)
            --it;
    }
    string get() {
        return (it++)->second;
    }
};

//https://codeforces.com/blog/entry/11080
/*
Runtime: 504 ms, faster than 75.48% of C++ online submissions for Sequentially Ordinal Rank Tracker.
Memory Usage: 165.7 MB, less than 7.74% of C++ online submissions for Sequentially Ordinal Rank Tracker
*/
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

using info = pair<int, string>;
struct greatcomp {
    bool operator()(info const& first, info const& second) const
        {
            return first.first == second.first? first.second < second.second : 
        first.first > second.first;
        }
};
class SORTracker {
    typedef tree<
    info,//int
    null_type,
    greatcomp,//less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
public:
    SORTracker() {
        //ranking();
        query_count= 0;
        
    }
    
    void add(string name, int score) {
        info temp(score,name);
        ranking.insert(temp);//log n
    }
    
    string get() {
        auto itr = ranking.find_by_order(query_count);//ranking.begin();
        //std::advance(itr, query_count);//n
        query_count++;
        return itr->second;
        
    }
    
    //multiset<info,greatcomp> ranking;
    ordered_set ranking;

    int query_count;
};