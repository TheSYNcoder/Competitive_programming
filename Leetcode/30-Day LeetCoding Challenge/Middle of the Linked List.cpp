/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * temp = head ;ListNode* temp2 = head ; 
        while(temp2 &&  temp2->next != NULL){
            temp = temp ->next;
            temp2 = temp2 -> next -> next;
        }
        return temp;
        
    }
};
