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
class cmp{
    public:
    bool operator()(ListNode *x,ListNode *y){
        return (x->val>y->val);
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         ListNode* curr = NULL; 
        
        int n = lists.size();
        
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0; i<n; i++){
            ListNode* temp = lists[i];
            if(temp != NULL)
                    pq.push(temp);
        }
        
        ListNode *dummy=new ListNode(0);
        ListNode *tail=dummy;
        
        while(!pq.empty()){
            ListNode *top=pq.top();
            pq.pop();
            tail->next=top;
            tail=tail->next;
            if(top->next)
                pq.push(top->next);
        }   
        return dummy->next;
    }
};