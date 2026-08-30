class Solution {
 public:
  int countOfPairs(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kMax = 1000;
    const int n = nums.size();
    int ans = 0;
    // dp[i][num] := the number of valid ways to fill the arrays up to index i
    // with arr1[i] = num
    vector<vector<int>> dp(n, vector<int>(kMax + 1));

    for (int num = 0; num <= nums[0]; ++num)
      dp[0][num] = 1;

    for (int i = 1; i < n; ++i) {
      int ways = 0;
      int prevNum = 0;
      
      for (int num = 0; num <= nums[i]; ++num) {
        if (prevNum <= min(num, num - (nums[i] - nums[i - 1]))) {
          ways = (ways + dp[i - 1][prevNum]) % kMod;
          ++prevNum;
        }
        dp[i][num] = ways;
      }
    }

    for (int i = 0; i <= kMax; ++i)
      ans = (ans + dp[n - 1][i]) % kMod;

    return ans;
  }
};