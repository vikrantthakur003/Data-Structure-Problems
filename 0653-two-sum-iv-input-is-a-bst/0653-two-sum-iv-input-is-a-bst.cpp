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
    void inorderTraversal(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }


    bool isExistsTarget(vector<int> &array, int k){
        int start = 0;
        int end = array.size() - 1;

        if(array.size() == 1){
            return false;
        }

        while(start < end){
            int sum = array[start] + array[end];
            cout<<sum<<endl;
            if(sum == k){
                return true;
            } else if(sum > k){
                end--;
            } else {
                start++;
            }
        }

        return false;
    }
    stack<TreeNode*> ascendingStack;
    stack<TreeNode*> descendingStack;
    void pushElements(TreeNode* node, string type){
        while(node != nullptr){
            if(type == "LEFT"){
                ascendingStack.push(node);
                node = node->left;
            } else {
                descendingStack.push(node);
                node = node->right;
            }
        }
    }

    TreeNode* next(){
        TreeNode* topNode = ascendingStack.top();
        ascendingStack.pop();
        pushElements(topNode->right, "LEFT");

        return topNode;
    }

    TreeNode* before(){
        TreeNode* topNode = descendingStack.top();
        descendingStack.pop();
        pushElements(topNode->left, "RIGHT");

        return topNode;
    }

    bool isExistsSum(TreeNode* root, int target){

        pushElements(root, "LEFT");
        pushElements(root, "RIGHT");

        TreeNode* start = next();
        TreeNode* end = before();

        while(start != end){
            int sum = start->val + end->val;

            if(sum == target){
                return true;
            } else if(sum > target){
                end = before();
            } else {
                start = next();
            }
        }

        return false;
    }


    bool findTarget(TreeNode* root, int k) {
        // vector<int> inorder;
        // inorderTraversal(root, inorder);
        // return isExistsTarget(inorder, k);
        
        return isExistsSum(root, k);
    }
};