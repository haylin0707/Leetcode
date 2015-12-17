/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
单链表中两两调换
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *cur=head;//指向原数组的指针
        ListNode *newlist=new ListNode(0);//创建一个新的数组
        ListNode *helper=newlist;//指向新数组的指针
        while(cur && cur->next){
            ListNode *nextnext=cur->next->next;//下一次调换位置时，指针所指的原数组的位置
            helper->next=cur->next;
            helper=helper->next;//原数组的第二个数放在新数组的第一个
            helper->next=cur;//原数组的第一个数放在新数组的第二个
            helper=helper->next;//把新数组的指针移到第二个位置
            helper->next=NULL;//新数组的末尾暂时没有数，指向NULL
            cur=nextnext;//原数组的指针则移动到之前保存的nextnext出，进行下一次迭代
        }
        if(cur) helper->next=cur;//如果原数组还有数，相当于原数组的个数为奇数，则新数组的最后一个数应该指向这个剩下的数；
        return newlist->next;
    }
};