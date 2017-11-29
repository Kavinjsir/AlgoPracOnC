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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        stack<TreeNode*> record;
        record.push(root);
        while(!record.empty()){
            TreeNode* tmp = record.top();
            record.pop();
            res.push_back(tmp->val);
            if(tmp->right)
                record.push(tmp->right);
            if(tmp->left)
                record.push(tmp->left);
        }
        return res;
    }
};