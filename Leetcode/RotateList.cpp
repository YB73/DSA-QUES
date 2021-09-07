class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)
            return head;
        ListNode* current = head;
        int count = 0;
        vector<int> res;
        while(current!=NULL){
            count++;
            res.push_back(current->val);
            current = current->next;
        }
        k = k%count;
        vector<int> ans;
        for(int i = count-k;i<count;i++){
            ans.push_back(res[i]);
        }
        for(int i = 0;i<count-k;i++){
            ans.push_back(res[i]);
        }
        current = head;
        int i = 0;
        while(current!=NULL){
            current->val = ans[i++];
            current = current->next;
        }
        return head;
        
    }
};


