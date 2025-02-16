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
    vector<vector<int>>result;
    void findLevelOrderValues(TreeNode* root){
        if(root == nullptr){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                TreeNode* frontNode = q.front();
                q.pop();
                temp.push_back(frontNode->val);

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            result.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        findLevelOrderValues(root);
        return result;
    }
};