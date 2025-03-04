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
        // check if k Node exist
        while (count--) {
            if (temp == NULL)
                return head; // if not return Head
            temp = temp->next;
        }
        prevNode = reverseKGroup(temp, k); // recursively call for rest of LL
        //Reverse current group
        temp = head;
        while (k--) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
        }
        //return new Head
        return prevNode;
    }
};