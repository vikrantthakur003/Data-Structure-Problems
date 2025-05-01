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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr != nullptr){

            if(curr->left != nullptr){
                TreeNode* rightChild = curr->right;
                curr->right = nullptr;

                TreeNode* leftChild = curr->left;

                while(leftChild->right != nullptr){
                    leftChild = leftChild->right;
                }

                leftChild->right = rightChild;
                TreeNode* temp = curr;
                curr->right = curr->left;
                temp->left = nullptr;
                curr = curr->right;
            } else {
                curr = curr->right;
            }
        }
    }
};