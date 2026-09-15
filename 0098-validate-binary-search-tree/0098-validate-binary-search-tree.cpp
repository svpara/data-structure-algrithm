class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
/// this is a private a method for a define a class///
private:
    bool validate(TreeNode* node, long long low, long long high) {
        // that is set to the null pointer///
        if (node == nullptr)
            return true;
        // that is a value is very low
        if (!(low < node->val && node->val < high))
            return false;

        return validate(node->left, low, node->val) &&
               validate(node->right, node->val, high);
            // that can be can be return from a a user 
    }
};