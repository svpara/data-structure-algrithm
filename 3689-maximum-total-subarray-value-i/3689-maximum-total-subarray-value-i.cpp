class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minVal = nums[0], maxVal = nums[0];
        // Manually track the minimum and maximum values.
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        // The best subarray value, taken k times.
        return 1LL * k * (maxVal - minVal);
    }
};
