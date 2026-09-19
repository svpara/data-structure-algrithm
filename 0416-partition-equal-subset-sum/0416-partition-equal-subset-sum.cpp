class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Calculate the total sum of all elements
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
      
        // If total sum is odd, we cannot partition into two equal subsets
        if (totalSum % 2 == 1) {
            return false;
        }
      
        int n = nums.size();
        int targetSum = totalSum / 2;  // Target sum for each subset
      
        // dp[i][j] represents whether we can achieve sum j using first i elements
        bool dp[n + 1][targetSum + 1];
        memset(dp, false, sizeof(dp));
      
        // Base case: we can always achieve sum 0 with 0 elements
        dp[0][0] = true;
      
        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            int currentNum = nums[i - 1];
          
            for (int j = 0; j <= targetSum; ++j) {
                // Two choices for each element:
                // 1. Don't include current element: dp[i-1][j]
                // 2. Include current element (if possible): dp[i-1][j-currentNum]
                dp[i][j] = dp[i - 1][j] || (j >= currentNum && dp[i - 1][j - currentNum]);
            }
        }
      
        // Return whether we can achieve targetSum using all n elements
        return dp[n][targetSum];
    }
};
