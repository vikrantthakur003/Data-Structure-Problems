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
    void getInorderValue(TreeNode* root, vector<int>&inorder){
        if(root==nullptr){
            return;
        }
        
        getInorderValue(root->left, inorder);
        inorder.push_back(root->val);
        getInorderValue(root->right, inorder);
    }
    void iterativeInorderTraversal(TreeNode* root, vector<int> &inorder){
          if(root == nullptr){
            return;
        }
        stack<TreeNode*> st;
        TreeNode* currentNode = root;

        while(currentNode != nullptr || !st.empty()){

           while(currentNode != nullptr){
            st.push(currentNode);

            currentNode = currentNode->left;
           }
            currentNode = st.top();
            st.pop();

            inorder.push_back(currentNode->val);
            currentNode = currentNode->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        // getInorderValue(root, inorder);

        iterativeInorderTraversal(root, inorder);

        return inorder;
    }
};