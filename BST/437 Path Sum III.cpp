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
    
private:
    int findPath(TreeNode* node, int num){
        if(node == NULL)
            return 0;
        int res = 0;
        if(node->val == num)
            res += 1;
        res += findPath(node->left, num - node->val);
        res += findPath(node->right, num - node->val);
        return res;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        int res = findPath(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
};