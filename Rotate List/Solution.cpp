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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL)
            return head;
        else{
            ListNode* nextistail, *tail,*tmp;
            int count = 1;
            tmp = head;
            while(tmp->next!= NULL){
                count ++;
                tmp = tmp->next;
            }
            k = k%count;
            if(k == 0 || head == NULL || head->next == NULL)
            return head;
            
            tmp = head;
            while(tmp->next->next!=NULL){
                tmp = tmp->next;
            }
            nextistail = tmp;
            tail = nextistail->next;
            nextistail->next = NULL;
            tail->next = head;
            return rotateRight(tail, k-1);
            
        }
    }
};
