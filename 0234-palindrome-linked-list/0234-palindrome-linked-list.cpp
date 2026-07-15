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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //find middle
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        slow->next = NULL;

        ListNode* left = head;
        ListNode* right = prev;
        while(left && right){
            if(left->val != right->val){
                return false;
            }
            else{
                left= left->next;
                right = right->next;
            }
        }
        return true;
    }
};