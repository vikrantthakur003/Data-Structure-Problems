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
    void parentNodeMapping(TreeNode* root, map<TreeNode*, TreeNode*> &parentNodes){
        queue<TreeNode*> q;
        q.push(root);
        parentNodes[root] = nullptr;

        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode->left){
                parentNodes[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }

            if(frontNode->right){
                parentNodes[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k<=0){
            return {target->val};
        }
        map<TreeNode*, TreeNode*> parentNodeMap;
        unordered_map<TreeNode*, bool> visited;

        queue<TreeNode*> q;
        int lvl = 0;

        parentNodeMapping(root, parentNodeMap);

        q.push(target);
        visited[target] = true;

        while(!q.empty()){
            int queueSize = q.size();
            while(queueSize--){
                TreeNode* frontNode = q.front();
                q.pop();

                TreeNode* parentNode = parentNodeMap[frontNode];
                if(parentNode && !visited[parentNode]){
                    visited[parentNode] = true;
                    q.push(parentNode);
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
            lvl++;
            if(lvl == k){
                break;
            }
        }

        vector<int> result;
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            result.push_back(frontNode->val);
        }

        return result;
    }
};