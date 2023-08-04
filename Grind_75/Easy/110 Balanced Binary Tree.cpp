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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;

        search(root, balanced); 

        return balanced; 
    }

    int search(TreeNode* root, bool& balanced) {

        if (root == nullptr) {
            return 1;
        }
        
        int left = search(root->left, balanced); 
        int right = search(root->right, balanced);

        if (abs(left - right) > 1) {
            balanced = false;
        }

        return max(left, right) + 1;
        
    }
};