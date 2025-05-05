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
        int maxi=0;
        int findleft(TreeNode* root){
            if(root==NULL) return 0;
            int left = findleft(root->left);
            int right = findleft(root->right);
            return 1+max(left,right);
        }
        int findright(TreeNode* root){
            if(root == NULL) return 0;
            int right = findright(root->right);
            int left = findright(root->left);
            return 1+max(left,right);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            if(root==NULL) return 0;
            int lh = findleft(root->left);
            int rh = findright(root->right);
            maxi = max(maxi,lh+rh);
            diameterOfBinaryTree(root->left);
            diameterOfBinaryTree(root->right);
            return maxi;
        }
    };
