/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/merge-k-sorted-lists/submissions/
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/
/*
Runtime: 24 ms, faster than 69.42% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13.9 MB, less than 23.78% of C++ online submissions for Merge k Sorted Lists.
*/	

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    struct list_compare {
        bool operator()(const ListNode* x, const ListNode* y) { return x->val > y->val; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() < 1)
        {
            return nullptr;
        }
        
        priority_queue<ListNode*, vector<ListNode*>, list_compare> min_heap;
        //insert first element of each list
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                min_heap.push(lists[i]);
            }
        }
        if (min_heap.size() < 1)
        {
            return nullptr;
        }
        ListNode *head = new ListNode() , *tail;
        tail = head;
        while (min_heap.size() > 1)
        {
            ListNode *min = min_heap.top();
            min_heap.pop();
            tail->val = min->val;
            
            tail->next = new ListNode();
            tail = tail->next;
            if (min->next)
            {
                min_heap.push(min->next);
            }
        }
        
        ListNode *min = min_heap.top();
        min_heap.pop();
        tail->val = min->val;
        tail->next = min->next;
        
        return head;

    }
};