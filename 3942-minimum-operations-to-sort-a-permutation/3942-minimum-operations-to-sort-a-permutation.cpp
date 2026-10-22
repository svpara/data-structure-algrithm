class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Locate the index of the element 0 (the smallest value, treated as the cycle's start).
        int zeroIndex = ranges::find(nums, 0) - nums.begin();

        // Check whether starting from zeroIndex and moving with the given step
        // produces a non-decreasing sequence around the circular array.
        auto isNonDecreasing = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                // Previous position in the circular traversal.
                int prevIndex = (zeroIndex + (i - 1) * step + n) % n;
                // Current position in the circular traversal.
                int currIndex = (zeroIndex + i * step + n) % n;

                // If the order breaks, this direction is not valid.
                if (nums[prevIndex] > nums[currIndex]) {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;

        // Case 1: traverse forward (step = +1).
        // Either pop from the left zeroIndex times,
        // or pop from the right while keeping a sorted prefix.
        if (isNonDecreasing(1)) {
            ans = min(ans, zeroIndex);
            ans = min(ans, n - zeroIndex + 2);
        }

        // Case 2: traverse backward (step = -1).
        // Either pop from the left side or from the right side accordingly.
        if (isNonDecreasing(-1)) {
            ans = min(ans, zeroIndex + 2);
            ans = min(ans, n - zeroIndex);
        }

        // If no valid arrangement was found, return -1.
        return ans == INT_MAX ? -1 : ans;
    }
};
