/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

依然是双指针思想，两个指针相隔n-1，每次两个指针向后一步，当后面一个指针没有后继了，前面一个指针就是要删除的节点。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        //设定两个指针，相差n-1，若前面的指针走到了最头上，后面的指针所指的数为需要删除的点。
        //这就需要我们提前要存储删除这点的前一个数
        ListNode *forward=head;
        ListNode *back=head;
        ListNode *tmp=NULL;
        for(int i=0;i<n-1;i++){
            forward=forward->next;//Forward指针走到指定位置
        }
        while(forward->next!=NULL){
            tmp=back;//存储要删除节点的前一个位置
            forward=forward->next;
            back=back->next;
        }
        if(tmp==NULL){
            head=back->next;
            //这一步是为了防止没有经过上面while循环，tmp依旧为NULL情况
            //例如：[1,2],n=2,应该的[2]
        }
        else{
            tmp->next=back->next;//删除back所在节点
        }
        return head;
    }
};