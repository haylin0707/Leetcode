/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
将两个有序的链表组合成一个；
相当于有两个指针，一次比较大小；
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        //创建一个新链表
        ListNode *result=new ListNode(0);
        ListNode *head=result;
        while(l1 && l2){
            if(l1->val<l2->val){
                result->next=l1;
                l1=l1->next;
            }
            else{
                result->next=l2;
                l2=l2->next;
            }
            result=result->next;
        }
        while(l1){
            result->next=l1;
            l1=l1->next;
            result=result->next;
        }
        while(l2){
            result->next=l2;
            l2=l2->next;
            result=result->next;
        }
        //if(l1) result->next=l1;
        //if(l2) result->next=l2;
        return head->next;
    }
