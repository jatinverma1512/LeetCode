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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next == NULL) return head;

        ListNode* temp = head;
        int len = 1;
        while(temp->next != NULL){
            temp = temp->next;
            len++;
        }

        //make it circular
        temp->next = head;

        k = k%len;
        int jump = len - k - 1;

        temp = head;
        while(jump){
            temp = temp->next;
            jump--;
        }

        ListNode* newhead = temp->next;
        temp->next = NULL;

        return newhead;
    }
};