/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* slow;
    ListNode* fast;
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return false;
        slow = fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        if(!hasCycle(head)) return NULL;
        slow = head;
        while (fast != NULL && fast->next != NULL) {
            if (slow == fast) return slow;
            slow = slow->next;
            fast = fast->next;
        }
        return NULL;
    }
};