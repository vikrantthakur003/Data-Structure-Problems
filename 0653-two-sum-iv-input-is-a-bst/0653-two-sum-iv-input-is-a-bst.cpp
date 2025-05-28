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
        int start = 0;
        int end = array.size() - 1;

        if(array.size() == 1){
            return false;
        }

        while(start < end){
            int sum = array[start] + array[end];
            cout<<sum<<endl;
            if(sum == k){
                return true;
            } else if(sum > k){
                end--;
            } else {
                start++;
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