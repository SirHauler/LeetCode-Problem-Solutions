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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<int> result;
        if (root == NULL) return {}; 
        nodes.push(root);
        while(!nodes.empty()) {
            int rem = nodes.size(); 
            while (rem > 0) {
                TreeNode* curr = nodes.front();
                nodes.pop(); 
                if (rem == 1) {
                    result.push_back(curr->val); 
                }
                if (curr->left) nodes.push(curr->left);
                if (curr->right) nodes.push(curr->right); 
                rem--;
            }
        }

        return result;
    }
};