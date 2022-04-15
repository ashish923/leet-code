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
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* c = head;
        int z =0;
        while(c){
            z++;
            c = c->next;
        }
        cout<<z;
        int k = z - n;
        if(k==0 && z==1) return NULL;
        
        if(z==n) {
            head = head->next;
            return head;
        }
        
        while(slow){
            
            k--;
            if(k==0) 
            {
                slow->next = slow->next->next;
                break;
             }
           slow = slow->next; 
            
        }
        
       return fast;
    }
};