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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;

        // estimate list's length
        ListNode* node = head;
        while (node != nullptr) {
            node = node->next;
            length++;
        }

        if (length == n) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }

        // go to n'th element
        node = head;
        for (int i = 0; i < length - n - 1; i++) {
            node = node->next;
        }

        // remove n'th element
        ListNode* toDelete = node->next;
        if (toDelete != nullptr) {
            node->next = toDelete->next;
            delete toDelete;
        }

        return head;
    }
};
