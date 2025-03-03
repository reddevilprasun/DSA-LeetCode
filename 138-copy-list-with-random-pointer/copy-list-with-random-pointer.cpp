/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //use map to store the pair of oldNode and newNode address
    //for connecting to the random pointers
    unordered_map<Node*, Node*> m;
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL; //edge case

        Node* newHead = new Node(head->val);
        m[head] = newHead;
        Node* newTemp = newHead;
        Node* oldTemp = head->next;
        while (oldTemp != NULL) {
            Node* newNode = new Node(oldTemp->val);
            m[oldTemp] = newNode;
            newTemp->next = newNode;
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }
        newTemp = newHead;
        oldTemp = head;
        while (oldTemp != NULL) {
            if (!oldTemp->random) {
                newTemp->random = NULL;
            } else {
                newTemp->random = m[oldTemp->random];
            }
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }
        return newHead;
    }
};