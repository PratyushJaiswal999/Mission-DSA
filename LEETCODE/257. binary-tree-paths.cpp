class Solution {
    void generatePaths(TreeNode* root, vector<string>& ans, string temp) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }

        temp += to_string(root->val) + "->";
        generatePaths(root->left, ans, temp);
        generatePaths(root->right, ans, temp);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        generatePaths(root, ans, "");
        return ans;
    }
};
