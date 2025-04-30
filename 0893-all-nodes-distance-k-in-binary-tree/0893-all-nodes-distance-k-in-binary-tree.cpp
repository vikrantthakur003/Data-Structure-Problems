/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentMapping(TreeNode* root, map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        while(!q.empty()){
            int queueSize = q.size();

            while(queueSize--){
                TreeNode* frontNode = q.front();
                q.pop();

                if(frontNode->left){
                    q.push(frontNode->left);
                    parent[frontNode->left] = frontNode;
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                    parent[frontNode->right] = frontNode;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k <= 0){
            return {target->val};
        }
        map<TreeNode*, TreeNode*> parent;
        map<TreeNode*, bool> visited;

        parentMapping(root, parent);
        int level = 0;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        while(!q.empty()){
            int queueSize = q.size();
            while(queueSize--){
            TreeNode* frontNode = q.front();
            q.pop();

            TreeNode* parentNode = parent[frontNode];
            if(parentNode && !visited[parentNode]){
                q.push(parentNode);
                visited[parentNode] = true;
            }

            if(frontNode->left && !visited[frontNode->left]){
                q.push(frontNode->left);
                visited[frontNode->left] = true;
            }

            if(frontNode->right && !visited[frontNode->right]){
                 q.push(frontNode->right);
                visited[frontNode->right] = true;
            }
        }
        level++;

        if(level == k){
            break;
        }
        }

        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};