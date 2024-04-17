/**https://leetcode.com/explore/learn/card/recursion-i/250/principle-of-recursion/1681/
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
    void recrSwapPairs(ListNode** head_ptr) {
        if (!head_ptr)
            return;
        ListNode* head = *head_ptr;  
        if (!head || !head->next)
            return;      
        ListNode* next = head->next;
        head->next = next->next;
        next->next = head;
        *head_ptr = next;
        recrSwapPairs(&head->next);
        
    }
    ListNode* swapPairs(ListNode* head) {
        recrSwapPairs(&head);
        return head;
    }
};