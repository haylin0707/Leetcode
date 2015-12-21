/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
 *  可以将A,B两个链表看做两部分，交叉前与交叉后。

    交叉后的长度是一样的，因此交叉前的长度差即为总长度差。

    只要去除这些长度差，距离交叉点就等距了。

    为了节省计算，在计算链表长度的时候，顺便比较一下两个链表的尾节点是否一样，

    若不一样，则不可能相交，直接可以返回NULL
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *a=headA;
        ListNode *b=headB;
        int lenA=1;
        int lenB=1;//分别记录两个长度
        while(a->next!=NULL){
            a=a->next;
            lenA++;
        }
        
        while(b->next!=NULL){
            b=b->next;
            lenB++;
        }
        if(a!=b) return NULL;//说明两个最后没有重合的部分
        
        a=headA;
        b=headB;
        
        //使得长度长的那一段走到和短的那一段到重合点距离相等的位置
        if(lenA>lenB){
            for(int i=0;i<lenA-lenB;i++){
                a=a->next;
            }
        }
        else if(lenA<lenB){
            for(int i=0;i<lenB-lenA;i++){
                b=b->next;
            }
        }
        
        //两者同时往前走，走到重合点处相等
        while(a!=b){
            a=a->next;
            b=b->next;
        }
        return a;
    }
};