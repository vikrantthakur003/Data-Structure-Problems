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
    void inorderTraversal(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }


    bool isExistsTarget(vector<int> &array, int k){
        unordered_map<int, int> mp;

        for(int i=0;i<array.size();i++){
            int b = k - array[i];
            if(mp[b]){
                return true;
            } else {
                mp[array[i]]++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;

        inorderTraversal(root, inorder);

        return isExistsTarget(inorder, k);
    }
};