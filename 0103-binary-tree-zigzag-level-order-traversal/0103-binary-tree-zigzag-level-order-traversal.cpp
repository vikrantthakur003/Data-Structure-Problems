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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> zigzagOrder;
        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int queueSize = q.size();

            vector<int> tempOrder;
            while(queueSize--){
                TreeNode* frontNode = q.front();
                q.pop();

                tempOrder.push_back(frontNode->val);
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            if(leftToRight){
                zigzagOrder.push_back(tempOrder);
            } else {
                reverse(tempOrder.begin(), tempOrder.end());
                 zigzagOrder.push_back(tempOrder);
            }
            leftToRight =! leftToRight;
        }

        return zigzagOrder;
    }
};