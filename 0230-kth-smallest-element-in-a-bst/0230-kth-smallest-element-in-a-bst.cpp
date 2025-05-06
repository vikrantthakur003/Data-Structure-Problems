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
    int countNodes = 0;
    int ans = 0;
    void findInorder(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        findInorder(root->left, ans);
        ans.push_back(root->val);
        findInorder(root->right, ans);
    }
    void findSmallest(TreeNode* root, int k){
        if(root == nullptr || countNodes >= k){
            return;
        }

        findSmallest(root->left, k);
        countNodes++;
        if(countNodes == k){
            ans = root->val;
            return;
        }
        findSmallest(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> ans;
        // findInorder(root, ans);

        // return ans[k - 1];

        findSmallest(root, k);
        return ans;
    }
};