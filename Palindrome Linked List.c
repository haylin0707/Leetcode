/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 由于给定的数据结构是单链表，要访问链表的尾部元素，必须从头开始遍历。
 为了方便判断，我们可以申请一个辅助栈结构来存储链表的内容，
 第一次遍历将链表节点值依次入栈，第二次遍历比较判断是否为回文。
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* p=head;
        stack<int> s;
        while(p!=NULL){
            s.push(p->val);//将p的值压进去
            p=p->next;
        }
        while(head!=NULL){
            if(head->val!=s.top()){
                return false;
                //从链表头开始比较，看和栈顶是否一致
            }
            else{
                head=head->next;
                s.pop();
            }
        }
        return true;
    }
};