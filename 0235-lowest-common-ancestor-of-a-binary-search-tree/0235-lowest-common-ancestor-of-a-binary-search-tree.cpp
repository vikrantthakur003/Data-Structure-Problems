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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode* leftSide = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSide = lowestCommonAncestor(root->right, p, q);

        if(leftSide == nullptr && rightSide){
            return rightSide;
        } else if(leftSide && rightSide == nullptr){
            return leftSide;
        } else if(leftSide == nullptr && rightSide == nullptr) {
            return nullptr;
        } else {
            return root;
        }
    }
};