class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    pair<int, int> dfs(TreeNode* root, int& ans) {
        if (root == nullptr)
            return {0, 0};

        const auto [leftSum, leftCount] = dfs(root->left, ans);
        const auto [rightSum, rightCount] = dfs(root->right, ans);

        // Calculate sum and count
        const int sum = root->val + leftSum + rightSum;
        const int count = 1 + leftCount + rightCount;

        // Check average
        if (sum / count == root->val)
            ++ans;

        return {sum, count};
    }
};