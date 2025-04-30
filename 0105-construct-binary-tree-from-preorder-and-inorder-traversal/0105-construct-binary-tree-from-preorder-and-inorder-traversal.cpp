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
    int searchElement(vector<int> array, int element){
        for(int i=0;i<array.size();i++){
            if(array[i] == element){
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTreeUsingTraversal(vector<int>& preorder, vector<int> &inorder, int &preIndex, int startIndex, int endIndex, int n){
        if(preIndex >= n || startIndex > endIndex){
            return nullptr;
        }

        int rootNode = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootNode);
        int rootPosition = searchElement(inorder, rootNode);

        root->left = buildTreeUsingTraversal(preorder, inorder, preIndex, startIndex, rootPosition - 1, n);
        root->right = buildTreeUsingTraversal(preorder, inorder, preIndex, rootPosition + 1, endIndex, n);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIndex = 0;
        return buildTreeUsingTraversal(preorder, inorder, preIndex, 0, n - 1, n);
    }
};