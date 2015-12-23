/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
题意：给定一个单链表和一个x，把链表中小于x的放到前面，大于等于x的放到后面，每部分元素的原始相对位置不变。

思路：其实很简单，遍历一遍链表，把小于x的都挂到head1后，把大于等于x的都放到head2后，最后再把大于等于的链表挂到小于链表的后面就可以了。
指针的用法：
申请新链表：ListNode* xxx=ListNode（0）
设置指向链表的头结点的指针 ListNode* cursor=xxx
返回整个新建的链表 return xxx->next;
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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        
        ListNode *small=new ListNode(0);
        ListNode *s=small;
        
        ListNode *big=new ListNode(0);
        ListNode *b=big;
        
        ListNode *p=head;
        while(p!=NULL){
            ListNode *next=p->next;//保存p的下一个节点
            if(p->val<x){
                s->next=p;
                s=s->next;
                s->next=NULL;
            }
            else{
                b->next=p;
                b=b->next;
                b->next=NULL;
            }
            p=next;
        }
       
        s->next=big->next;
        return small->next;
    }
};