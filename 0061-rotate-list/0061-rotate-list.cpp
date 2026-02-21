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
        if(head==NULL)return NULL;
        int len=1;
        ListNode* tail= head;
        while(tail->next!=nullptr){
            tail= tail->next;
            len++;
        }
        tail->next= head;
        k=k%len;
        int index= len-k - 1;
        ListNode* curr= head;
        while(index--){
            curr = curr->next;
        }
        ListNode* newhead= curr->next;
        curr->next= NULL;
        return newhead;
    }
};