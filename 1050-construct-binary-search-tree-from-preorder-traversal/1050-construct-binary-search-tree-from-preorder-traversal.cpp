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
    int findValue(vector<int> inorder, int target){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* makeBST(vector<int> &preorder, int &index, vector<int> &inorder, int startIndex,int endIndex, int n){
        if(index >= n || startIndex > endIndex){
            return nullptr;
        }
        int rootValue = preorder[index++];
        int rootIndex = findValue(inorder, rootValue);
        TreeNode* root = new TreeNode(rootValue);

        root->left = makeBST(preorder, index, inorder, startIndex, rootIndex - 1, n);
        root->right = makeBST(preorder, index, inorder, rootIndex + 1, endIndex, n);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for(int i=0;i<preorder.size();i++){
            inorder.push_back(preorder[i]);
        }

        sort(inorder.begin(), inorder.end());
        int index = 0;
        int n = inorder.size();
        return makeBST(preorder, index, inorder, 0, n-1, n);
    }
};