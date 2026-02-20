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
        
        ListNode* slow= head;
        ListNode* fast= head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        
        ListNode* prev= NULL;
        while(slow!=NULL){
            ListNode* next= slow->next;
            slow->next= prev;
            prev= slow;
            slow= next;
        }
        ListNode* p1= head, *p2= prev;
        while(p2){
            if(p1->val!=p2->val)return false;
            p1=p1->next;
            p2= p2->next;
        }
        return true;
    }
};