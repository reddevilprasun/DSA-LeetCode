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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)//base case
            return head;
        ListNode *first = head, *sec = head->next, *prev = NULL;
        while (first && sec) {
            ListNode* next = sec->next;
            sec->next = first;
            first->next = next;
            if (!prev) //In the staring prev will be the new head
                head = sec;
            else
                prev->next = sec;
            prev = first;
            first = next;
            if (next)
                sec = next->next;
            else
                sec = NULL;
        }
        return head;
    }
};