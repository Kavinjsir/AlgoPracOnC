//My solution:

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
    bool has(TreeNode* root, int sum){
        if(root == NULL)
            return sum == 0;
        if(root->left == NULL && root->right == NULL)
            return root->val == sum;
        bool l = false, r = false;
        if(root->left)
            l = has(root->left, sum - root->val);
        if(root->right)
            r = has(root->right, sum - root->val);
        return (l || r);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;      
        return has(root, sum);
    }
};

//Standard Solution
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return root->val == sum;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};