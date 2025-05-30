/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* mid = nullptr;
    TreeNode* prev = nullptr;

    // case 1: inorder -> 1, 3, 2 (in this case first = 3, and last = 2)
    // case 2: inorder -> 1, 25, 7, 18, 5 (in this case first = 25, mid = 7, last = 5)
    void inorderTraversal(TreeNode* root){
        if(root == nullptr){
            return;
        }
        inorderTraversal(root->left);

        if(prev && root->val < prev->val){ 
            // for the first mode
            if(first == nullptr){
                first = prev;
                mid = root;
            } else {
                second = root;
            }
        }

        prev = root;
        

        inorderTraversal(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorderTraversal(root);

        if(first && second){
            swap(first->val, second->val);
        } else if(first && mid) {
            swap(first->val, mid->val);
        }

    }
};