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
    vector<int> postorderTraversal(TreeNode* root) {
        unordered_set<TreeNode*> visited;
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
            if(visited.find(tmp) != visited.end()){
                res.push_back(tmp->val);
                record.pop();
            } else if(tmp->right){
                cur = tmp->right;
                record.push(cur);
                visited.insert(tmp);
            } else {
                record.pop();
                res.push_back(tmp->val);
            }
        }
        return res;
    }
};