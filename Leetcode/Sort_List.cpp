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
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        vector<int> arr;
        ListNode* curr = head;
        while(curr){
            arr.push_back(curr->val);
            curr = curr->next;
            
        }
        sort(arr.begin(), arr.end());
        curr = head;
        int i = 0;
        while(curr){
            curr->val = arr[i++];
            curr = curr->next;
        }
        return head;
    }
};
/// stored elements in a vector and then sort it and then assign the values to the list nodes 
// time complexity : O(n^2)
// space complexity : O(n)