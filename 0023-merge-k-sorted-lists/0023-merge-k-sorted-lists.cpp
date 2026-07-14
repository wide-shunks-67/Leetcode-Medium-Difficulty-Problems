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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(ListNode* head: lists){
            while(head){
                pq.push(head->val);
                head=head->next;
            }
        }
        if(pq.empty()){
            return NULL;
        }
        ListNode* head= new ListNode(pq.top());
        pq.pop();
        ListNode* curr= head;
        while(!pq.empty()){
            curr->next= new ListNode(pq.top());
            pq.pop();
            curr=curr->next;
        }
        return head;
    }
};