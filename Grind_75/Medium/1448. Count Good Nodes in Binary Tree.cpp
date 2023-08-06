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
    int goodNodes(TreeNode* root) {
        int count = 0; 
        int max = root->val;
        search(root, max, count); 
        return count;
    }

    void search(TreeNode* root, int max, int& count) {
        if (root == NULL) return;
        if (root->val >= max) {
            count += 1;
            max = root->val;
        } 

        search(root->left, max, count);
        search(root->right, max, count);
    }
};