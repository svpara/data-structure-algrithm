class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        // Total sum of all elements
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        // We need to keep a subarray whose sum is total - x
        int target = total - x;

        // If target is negative, impossible
        if (target < 0)
            return -1;

        // If target is 0, remove all elements
        if (target == 0)
            return n;

        int left = 0;
        int sum = 0;
        int maxLength = -1;

        // Sliding Window
        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // If sum becomes greater than target,
            // move left pointer
            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }

            // Found a subarray with sum = target
            if (sum == target) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        // Minimum operations = elements NOT kept
        if (maxLength == -1)
            return -1;

        return n - maxLength;
    }
};