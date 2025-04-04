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
    pair<bool,TreeNode*> findans(TreeNode* l , TreeNode* r , TreeNode* root){
        if(root == NULL){
            return {false, NULL};
        }
        if(root == l || root == r){
            return {true, NULL};
        }

        pair<bool,TreeNode*>ans1 = findans(l,r,root->left);
        pair<bool,TreeNode*>ans2 = findans(l,r,root->right);

        if(ans1.first && ans2.first){
            return {true, root};
        }
        else if(ans1.first && ans1.second != NULL){
            return ans1;
        }
        else if(ans2.first && ans2.second != NULL){
            return ans2;
        }
        else if(ans1.first || ans2.first){
            return {true, NULL};
        }
        else{
            return {false,NULL};
        }
        

    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*>v;
        vector<TreeNode*>v1;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int t = q.size();
            v1.clear();
            while(t--){
                auto top = q.front();
                q.pop();
                v1.push_back(top);
                
                if(top->left != NULL){
                    q.push(top->left);
                }

                if(top->right != NULL){
                    q.push(top->right);
                }
            }

            if(v1.size() > 0){
                v = v1;
            }
        }

        if(v.size() == 1){
            return v[0];
        }
        else{
            pair<bool, TreeNode*>ans = findans(v[0],v[v.size()-1], root);
            return ans.second;
        }
        
    }
};