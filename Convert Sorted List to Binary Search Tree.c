/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
这题的关键是能找出当前链表的中间节点，然后再递归左右的子链表，开始的时候程序先计算链表总厂，然后传入两个前后索引指针，最后每次递归找出中间节点即可。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int listlen(ListNode* head){
        int len=0;
        ListNode* p=head;
        while(p!=NULL){
            p=p->next;
            len++;
        }
        return len;
    }
    
    TreeNode* createTree(ListNode* node, int left, int right){
        if(left>right) return NULL;
        
        int mid=(left+right)/2;//表示得到中间root节点的位置
        ListNode *p = node;
         
        for(int i = left; i < mid; i++)
             p = p->next;//中间节点
        
        //分别构造左右子树
        TreeNode *leftNode = createTree(node, left, mid - 1);
        TreeNode *rightNode = createTree(p->next, mid + 1, right);
         
        TreeNode *tNode = new TreeNode(p->val);
     
        tNode->left = leftNode;
        tNode->right = rightNode;
        
        return tNode; 
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int len = listlen(head);
        return createTree(head, 0, len - 1);

    }
};