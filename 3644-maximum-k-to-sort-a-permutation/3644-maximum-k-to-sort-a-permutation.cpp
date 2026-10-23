class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        // Initialize result with -1 (all bits set to 1 in binary)
        int result = -1;

        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); ++i) {
            // Check if current element is not at its sorted position
            // (assuming 0-indexed array where nums[i] should equal i in sorted order)
            if (i != nums[i]) {
                // Perform bitwise AND operation with the misplaced element
                result &= nums[i];
            }
        }

        // Return the maximum between result and 0
        // This ensures non-negative output (returns 0 if result is negative)
        return max(result, 0);
    }
};
