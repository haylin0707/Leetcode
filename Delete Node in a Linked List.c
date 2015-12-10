/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
这道题考察链表，注意node是将要删除的节点
1-2-3-4-5，若node为3，应为1-2-4-5；则第三个节点node-next为原来node-next-next；node-val为原来node-next-val；
注意指针使用.还是->
-> 指针变量
.  常规变量

X* px = new X(); px 是指针，防问任何变量或函数都用  px->开头
X x;    则 用 x. 开头 

这里创建的是node指针，所以用->
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
    void deleteNode(ListNode* node) {
        if(node==NULL) return;
        //注意node是需要删除的节点
        node->val=node->next->val;
        node->next=node->next->next;
    }
};