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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        int count = k;
        while (count--) {
            if (temp == NULL)
                return head;
            temp = temp->next;
        }
        prevNode = reverseKGroup(temp, k);
        temp = head;
        while (k--) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
        }
        return prevNode;
    }
};