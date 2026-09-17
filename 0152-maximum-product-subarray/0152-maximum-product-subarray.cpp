class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    // that are used to the store the 00 value
    int dpMin = nums[0];  // the minimum so far
    int dpMax = nums[0];  // the maximum so far

    for (int i = 1; i < nums.size(); ++i) {
    // set to the value amd size
      const int num = nums[i];
      const int prevMin = dpMin;  // dpMin[i - 1]
      const int prevMax = dpMax;  // dpMax[i - 1]
      if (num < 0) {
        dpMin = min(prevMax * num, num);
        // that arte used the minimum value are the used
        dpMax = max(prevMin * num, num);
      } else {
        dpMin = min(prevMin * num, num);
        // that are uased prevous exam are used
        dpMax = max(prevMax * num, num);
      }
      ans = max(ans, dpMax);
    }

    return ans;
  }
};


