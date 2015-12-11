/*
Reverse a singly linked list.
反转单向链表；
一般可以用迭代式或者递归式，但。。我没理解
所以用栈的方法，利用先进后出的特点进行反转

注意最开始要判断if(head == NULL || head->next == NULL)  return head; 
第一次提交的时候就没有注意，导致不能过[]的case；

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
    ListNode* reverseList(ListNode* head) {
        //注意判断链表为空，或是只有一个元素的情况；
        if(head == NULL || head->next == NULL)  return head; 
        stack<ListNode*> s;//用栈“先进后出”的特点实现链表的反转
        //先将元素一个个压入栈中；
        while(head!=NULL){
            s.push(head);
            head=head->next;
        }
        
        //取出栈s中的第一个元素即是原来链表的最后一个元素
        ListNode* root=s.top();
        s.pop();
        ListNode* tmp=root;
        while(!s.empty()){
            tmp->next=s.top();
            tmp=tmp->next;
            s.pop();
        }
        //最后一个元素的next应该为空
        tmp->next=NULL;
        return root;
    }
};