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
    void getPostorderValue(TreeNode* root, vector<int> &postorder){
        if(root == nullptr){
            return;
        }

        getPostorderValue(root->left, postorder);
        getPostorderValue(root->right, postorder);

        postorder.push_back(root->val);
    }

    void iterativePostorderTraversal(TreeNode* root, vector<int> &postorder){
        if(root == nullptr){
            return;
        }

        stack<TreeNode*> st;
        TreeNode* currentNode = root;
        TreeNode* lastVisitedNode = nullptr;

        while(currentNode != nullptr || !st.empty()){
            // first process all leftNode of Tree
            if(currentNode != nullptr){
                st.push(currentNode);

                currentNode = currentNode->left;
            } else{
                // If leftNode doesn't exists then get top node of stack and check right node exits or not;
                TreeNode* topNode = st.top();
                if(topNode->right != nullptr && topNode->right != lastVisitedNode){
                    currentNode = topNode->right;
                } else{
                    // if left node and right node both are don't exits then push topNode in vector 
                    postorder.push_back(topNode->val);
                    st.pop();
                    lastVisitedNode = topNode;
                }
            }
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        // getPostorderValue(root, postorder);
        iterativePostorderTraversal(root, postorder);
        return postorder;
    }
};