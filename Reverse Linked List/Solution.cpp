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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        else{
            ListNode *now, *next1, *next2, *tmp;
            now = head;
            next1 = now->next;
            now->next = NULL;
          //  next2 = next1->next;
            while(next1!=NULL){
                tmp = next1->next;
                next1->next = now;
                now = next1;
                next1 = tmp;
            }
            return now;
            
        }
    }
};
