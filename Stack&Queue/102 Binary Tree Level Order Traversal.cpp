/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            TreeNode* tmp = q.front().first;
            int l = q.front().second;
            q.pop();
            if(l == res.size())
                res.push_back(vector<int>());
            res[l].push_back(tmp->val);
            if(tmp->left)
                q.push(make_pair(tmp->left, l + 1));
            if(tmp->right)
                q.push(make_pair(tmp->right, l + 1));
        }
        return res;
    }
};