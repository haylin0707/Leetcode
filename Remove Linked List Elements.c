/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//以后在链表循环的条件还是用p->next!=NULL判断！！！！！！！！！
class Solution {
 public:
     ListNode* removeElements(ListNode* head, int val) {
         if (head == NULL) return NULL;
         ListNode *cur = head, *next = head->next;
         while (next != NULL) {
             if (next->val == val) {
                 cur->next = next->next;
                 //delete next;
                 next = cur->next;
             } else {
                 cur = cur->next;
                 next = next->next;
             }
         }
         if (head->val == val) {
             //出现头结点值和val相等
             //[1,1] val=1
             cur = head;
             head = head->next;
             //delete cur;
         }
         return head;
     }
 };
 
  /*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        ListNode* p=head;
        ListNode* pre=NULL;
        if(head->val==val){
            
            head=head->next;
            p=head;
        } 
        while(p!=NULL){
            
            if(p->val!=val){
                pre=p;
                p=p->next;
            }
            else{
                pre->next=p->next;
                p=p->next;
            }
        }
        return head;
    }
};
*/
//上面的答案是错的！！！