/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "null";
        }
        queue<TreeNode*> q;
        string serializeTree = "";
        q.push(root);

        while(!q.empty()){
                TreeNode* frontNode = q.front();
                q.pop();

                if(frontNode){
                    serializeTree += to_string(frontNode->val) + ",";
                    q.push(frontNode->left);
                    q.push(frontNode->right);
                } else {
                    serializeTree += "null,";
                }
        }

        return serializeTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "null"){
            return nullptr;
        }
        queue<TreeNode*> q;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();

            // for Left Child
            getline(ss, str, ',');
            if(str != "null"){
                TreeNode* left = new TreeNode(stoi(str));
                currNode->left = left;
                q.push(left);
            }

            // For right Child
            getline(ss, str, ',');
            if(str != "null"){
                TreeNode* right = new TreeNode(stoi(str));
                currNode->right = right;
                q.push(right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));