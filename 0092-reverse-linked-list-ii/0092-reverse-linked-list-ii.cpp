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
       ListNode*rev(ListNode*head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*nex=NULL;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode *curr = head, *prev = NULL;
        while(count != left){
            prev = curr;
            curr = curr->next;
            count++;
            
        }
        ListNode *start = curr;
        while(count != right){
            curr = curr->next;
            count++;
        }
        ListNode *rem = curr->next;
        curr->next = NULL;
        ListNode *newHead = rev(start);
        if (prev!=NULL){
            prev->next = newHead;

        }
        curr = newHead;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = rem;
        if(left == 1){
            return newHead;
        }
        else{
            return head;
        }
        
    }
};