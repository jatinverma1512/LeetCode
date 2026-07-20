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
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;    // vese iss check ki need nhi h kyuki upar base case likh diya h
        for(int i=0; i<2; i++){
            if(temp == NULL) return head;
            temp = temp->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i=0; i<2; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = swapPairs(curr);
        return prev;
    }
};