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
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool checkSortedArray(vector<int> &array){
        for(int i=1;i<array.size();i++){
            bool isLargest = array[i] > array[i-1];
            if(!isLargest){
                return false;
            }
        }

        return true;
    }

    bool isBST(TreeNode* root, long maxValue, long minValue){
        if(root == nullptr){
            return true;
        }
        if(root->val <= minValue || root->val >= maxValue){
            return false;
        }
        return isBST(root->left, root->val, minValue) &&  isBST(root->right, maxValue, root->val);
    }
    bool isValidBST(TreeNode* root) {
        // vector<int> ans;
        // inorder(root, ans);

        // return checkSortedArray(ans);

        return isBST(root, LONG_MAX, LONG_MIN);
    }
};