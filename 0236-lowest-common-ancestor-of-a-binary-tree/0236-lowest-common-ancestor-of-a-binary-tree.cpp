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
    void getPathToNode(TreeNode* root, TreeNode* targetNode, vector<TreeNode*>& temp){
        if(root == nullptr){
            return;
        }

        temp.push_back(root);

        if(root == targetNode){
            return;
        }
        getPathToNode(root->left, targetNode, temp);
        getPathToNode(root->right, targetNode, temp);

        temp.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }

        if(root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode* leftSide = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSide = lowestCommonAncestor(root->right, p, q);

        if(leftSide == nullptr && rightSide == nullptr){
            return nullptr;
        } else if(leftSide == nullptr && rightSide != nullptr){
            return rightSide;
        } else if(leftSide != nullptr && rightSide == nullptr){
            return leftSide;
        } else {
            return root;
        }
        
        // vector<TreeNode*> firstNode;
        // getPathToNode(root, p, firstNode);

        // vector<TreeNode*> secondNode;
        // getPathToNode(root, q, secondNode);

        //  int i = 0;
        // TreeNode* lca = nullptr;
        
        // while (i < firstNode.size() && i < secondNode.size()) {
        //     if (firstNode[i] == secondNode[i]) {
        //         lca = firstNode[i];
        //     } else {
        //         break;
        //     }
        //     i++;
        // }
        
        // return lca;


    }
};