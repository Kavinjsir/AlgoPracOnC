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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        stack<TreeNode*> record;
        record.push(root);
        TreeNode* cur = root;
        while(!record.empty()){
            while(cur->left){
                cur = cur->left;
                record.push(cur);
            }
            TreeNode* tmp = record.top();
            record.pop();
            res.push_back(tmp->val);
            if(tmp->right){
                cur = tmp->right;
                record.push(cur);
            }
        }
        return res;
    }
};