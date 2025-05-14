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
    int findlevel(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        return max( findlevel(root->left), findlevel(root->right))+1;
    }
    void traversal(TreeNode* root, int l, vector<vector<int>>&ans){
        if(root == NULL){
            return;
        }

        ans[l].push_back(root->val);

        traversal(root->left, l+1 , ans);
        traversal(root->right, l+1 , ans);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = findlevel(root);

        vector<vector<int>>ans(level);
        // ans.resize(l);

        traversal(root,0,ans);

        return ans;
    }
};