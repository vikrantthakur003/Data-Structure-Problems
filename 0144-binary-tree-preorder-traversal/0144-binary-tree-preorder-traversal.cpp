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
    void iterativePreorderTraversal(TreeNode* root, vector<int> &preorder){
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

    void morriseTraversal(TreeNode* root, vector<int> &ans){

        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* leftChild = curr->left;
                while(leftChild->right != nullptr && leftChild->right != curr){
                    leftChild = leftChild->right;
                }

                if(leftChild->right == nullptr){
                    leftChild->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                } else {
                    leftChild->right = nullptr;
                    curr = curr->right;
                }
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderArray;
        // preOrderTraversal(root, preorderArray);
        // iterativePreorderTraversal(root, preorderArray);
        morriseTraversal(root, preorderArray);
        return preorderArray;
    }
};