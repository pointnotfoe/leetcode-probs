/*https://leetcode.com/problems/lru-cache/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1
146. LRU Cache
Solved
Medium
Topics
premium lock icon
Companies
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
Accepted
23 / 23 testcases passed
pointnotfoe
pointnotfoe
submitted at Jun 18, 2025 23:56

Editorial

Solution
Runtime
51
ms
Beats
95.45%
Analyze Complexity
Memory
173.16
MB
Beats
71.45%
Analyze Complexity

*/

class LRUCache {
public:
    LRUCache(int capacity):_capacity(capacity) {
        
    }
    
    int get(int key) {
        
        if (cache_map.find(key) != cache_map.end())
        {
            // cache.erase(key);
            q.splice(q.begin(), q, cache_map[key]);
            // cache_map[key]
            return q.front().second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if (cache_map.find(key) != cache_map.end())
        {
            // cache.erase(key);
            q.splice(q.begin(), q, cache_map[key]);
            q.front().second = value;
        }
        else 
        {
            if(cache_map.size() >= _capacity)
            {
                cache_map.erase(cache_map.find(q.back().first));
                q.pop_back();
            }
            q.push_front(make_pair(key, value));
            cache_map[key] = q.begin();
        }
        
    }
private:
    int _capacity;
    typedef list<pair<int,int>> dll;
    dll q;
    unordered_map<int, dll::iterator> cache_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */