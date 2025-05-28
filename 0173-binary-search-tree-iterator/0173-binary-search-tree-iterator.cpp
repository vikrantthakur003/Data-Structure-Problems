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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushLeftNode(root);
    }
    
    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        pushLeftNode(topNode->right);
        return topNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    private: 
    void pushLeftNode(TreeNode* node){
        // if(node != nullptr){
           while(node != nullptr){
                st.push(node);
                node = node->left;
           }
        // }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */