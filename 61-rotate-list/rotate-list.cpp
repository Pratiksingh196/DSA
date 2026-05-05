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
        if(!head || !head->next ) return head;

        int len = 1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            len++;
        }

        k = k % len;
        if(k==0) return head;

        temp->next = head;

        ListNode* temp2 = head;

        int steps = len - k;
        for(int i = 1 ; i<steps ; i++){
            temp2 = temp2->next;
        }

        ListNode* newhead = temp2->next;
        temp2->next = NULL;

        return newhead;
    }
};