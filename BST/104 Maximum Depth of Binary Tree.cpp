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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));

        while(!q.empty()){
            TreeNode* t = q.front().first;
            int l = q.front().second + 1;
            q.pop();
            
            if(t->left)
                q.push(make_pair(t->left, l));
            if(t->right)
                q.push(make_pair(t->right, l));
        }
        int res = q.back().second;
        return res;
    }
};