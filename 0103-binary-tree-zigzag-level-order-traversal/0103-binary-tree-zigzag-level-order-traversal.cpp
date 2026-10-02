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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
      
        // Handle empty tree case
        if (!root) {
            return result;
        }
      
        // Initialize queue for BFS traversal
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
      
        // Flag to track traversal direction (1 = left-to-right, 0 = right-to-left)
        bool isLeftToRight = true;
      
        // Process tree level by level
        while (!nodeQueue.empty()) {
            vector<int> currentLevel;
            int levelSize = nodeQueue.size();
          
            // Process all nodes at current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
              
                // Add current node's value to level result
                currentLevel.push_back(currentNode->val);
              
                // Add children to queue for next level processing
                if (currentNode->left) {
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodeQueue.push(currentNode->right);
                }
            }
          
            // Reverse the level values if traversing right-to-left
            if (!isLeftToRight) {
                reverse(currentLevel.begin(), currentLevel.end());
            }
          
            // Add current level to final result
            result.push_back(currentLevel);
          
            // Toggle direction for next level
            isLeftToRight = !isLeftToRight;
        }
      
        return result;
    }
};
