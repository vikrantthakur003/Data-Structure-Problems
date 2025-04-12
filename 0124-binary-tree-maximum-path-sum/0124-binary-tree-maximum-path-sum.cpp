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
    int maxSum = INT_MIN;
    int helper(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int leftMaxSumPath = max(0, helper(root->left));
        int rightMaxSumPath = max(0,helper(root->right));

        maxSum = max(maxSum, leftMaxSumPath + rightMaxSumPath + root->val);

        return root->val + max(leftMaxSumPath, rightMaxSumPath);
    }
    int maxPathSum(TreeNode* root) {
       helper(root);
        return maxSum;
    }
};