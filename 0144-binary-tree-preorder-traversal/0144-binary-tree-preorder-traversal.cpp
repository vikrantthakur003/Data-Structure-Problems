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
    void preOrderTraversal(TreeNode* root, vector<int> &preorder){
        if(root== nullptr){
            return;
        }
        preorder.push_back(root->val);
        preOrderTraversal(root->left, preorder);
        preOrderTraversal(root->right, preorder);
    }
    void itrativePreorderTraversal(TreeNode* root, vector<int> &preorder){
        if(root == nullptr){
            return;
        }
        stack<TreeNode*>st;
        st.push(root);

        while(!st.empty()){
            TreeNode* frontNode = st.top();
            preorder.push_back(frontNode->val);
            st.pop();

            if(frontNode->right){
                st.push(frontNode->right);
            } 
            if(frontNode->left){
                st.push(frontNode->left);
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderArray;
        // preOrderTraversal(root, preorderArray);
        itrativePreorderTraversal(root, preorderArray);
        return preorderArray;
    }
};