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
    TreeNode* findTargetNode(TreeNode* root, int start){
        if(root == nullptr){
            return nullptr;
        }

        if(root->val == start){
            return root;
        }
        TreeNode* leftSide = findTargetNode(root->left, start);
        if(leftSide){
            return leftSide;
        } 
        TreeNode* rightSide = findTargetNode(root->right, start);
        if(rightSide){
            return rightSide;
        }

        return nullptr;
    }

    void parentNodeMapping(TreeNode* root, map<TreeNode*, TreeNode*> &parentNodes){
        queue<TreeNode* > q;
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
    int amountOfTime(TreeNode* root, int start) {
        if(root == nullptr){
            return -1;
        }

        map<TreeNode*, TreeNode*> parentNodeMap;
        unordered_map<TreeNode*, bool> visited;
        parentNodeMapping(root, parentNodeMap);
        TreeNode* targetNode = findTargetNode(root, start);

        queue<TreeNode*> q;
        int infectedTime = 0; // Burning Time
        q.push(targetNode);
        visited[targetNode] = true;

        while(!q.empty()){
            int queueSize = q.size();
            bool isContinueBurning = false;
            
            while(queueSize--){
                TreeNode* frontNode = q.front();
                q.pop();

                TreeNode* parentNode = parentNodeMap[frontNode];
                if(parentNode && !visited[parentNode]){
                    visited[parentNode] = true;
                    q.push(parentNode);
                    isContinueBurning = true;
                }

                if(frontNode->left && !visited[frontNode->left]){
                    q.push(frontNode->left);
                    visited[frontNode->left] = true;
                    isContinueBurning = true;
                }

                if(frontNode->right && !visited[frontNode->right]){
                    q.push(frontNode->right);
                    visited[frontNode->right] = true;
                    isContinueBurning = true;
                }
            }
            if(isContinueBurning){
                infectedTime++;
            }
        }

        return infectedTime;
    }
};