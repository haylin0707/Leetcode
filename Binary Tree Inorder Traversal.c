/*Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
求树的中序排列；
Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
     #表示是终止节点没有值；
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;//树节点的值
 *     TreeNode *left;//树的左儿子
 *     TreeNode *right;//树的右儿子
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> result;//返回树的中序的结果
        stack <TreeNode *> s;//创建一个栈s，有TreeNode格式
        TreeNode *p=root;
        while(!s.empty() || p!=NULL){
            while(p!=NULL){
                s.push(p);
                p=p->left;
                //依次将左儿子放进栈中
            }
            if(!s.empty()){
                p=s.top();
                s.pop();
                //栈顶弹出，将对应的值放入result中；
                result.push_back(p->val);
                p=p->right;//遍历右子树；
            }
        }
        return result;
    }
};