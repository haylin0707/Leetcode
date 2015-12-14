/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
由于是已经排好序的，所以只要比较和前一个数字是否相等即可；
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p=head;
        if(head==NULL || head->next==NULL) return head;
        while(p!=NULL && p->next!=NULL){
            if(p->val==p->next->val){
                p->next=p->next->next;//两个值不相等，则删除下个节点
            }
            else{
                p=p->next;
            }
        }
        return head;
    }
};