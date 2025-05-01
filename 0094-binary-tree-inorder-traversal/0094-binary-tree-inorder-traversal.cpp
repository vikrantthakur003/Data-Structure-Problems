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

    void morrisTraversal(TreeNode* root, vector<int> &ans){
        TreeNode* curr = root;

        while(curr != nullptr){

            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // get Right most node of leftTree
                TreeNode* leftChild = curr->left;
                while(leftChild->right != nullptr){
                    leftChild = leftChild->right;
                }
                
                // link right node with root
                leftChild->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;

                // remove left link of node with root
                temp->left = nullptr;
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        // getInorderValue(root, inorder);

        // iterativeInorderTraversal(root, inorder);

        morrisTraversal(root, inorder);

        return inorder;
    }
};