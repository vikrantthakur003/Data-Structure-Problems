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
    int ans = -1;
    void findSmallestValue(TreeNode* root, int k){
        if(root==nullptr){
            return;
        }
        if(k<=0){
            ans = root->val;
            return;
        }
        findSmallestValue(root->left, k - 1);
        findSmallestValue(root->right, k - 1);
    }
    void findInorder(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        findInorder(root->left, ans);
        ans.push_back(root->val);
        findInorder(root->right, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        findInorder(root, ans);

        return ans[k - 1];
    }
};