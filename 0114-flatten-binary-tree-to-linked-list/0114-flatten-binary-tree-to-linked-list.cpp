class Solution {
 public:
  void flatten(TreeNode* root) {
    if (root == nullptr)
    // root arrey can be this value can value set to be 0 //
      return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* const left = root->left;    // flattened left
    TreeNode* const right = root->right;  // flattened right

    root->left = nullptr;
    // that are used of the left to set the null value can be set
    root->right = left;

    // Connect the original right subtree to the end of the new right subtree.
    TreeNode* rightmost = root;
    while (rightmost->right != nullptr)
      rightmost = rightmost->right;
    rightmost->right = right;
  }
};