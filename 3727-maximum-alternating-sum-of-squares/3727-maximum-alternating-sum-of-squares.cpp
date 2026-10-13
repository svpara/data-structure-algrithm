class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // Step 1: Square every element in the array.
        // Each value x is replaced with x * x.
        for (int& num : nums) {
            num = num * num;
        }

        // Step 2: Sort the squared values in ascending order.
        // After sorting, the smaller squares come first and
        // the larger squares come last.
        ranges::sort(nums);

        long long answer = 0;

        // The first half (smaller values) will be subtracted,
        // and the second half (larger values) will be added.
        long long half = nums.size() / 2;

        // Step 3: Subtract the smaller half of the squared values.
        for (int i = 0; i < half; ++i) {
            answer -= nums[i];
        }

        // Step 4: Add the larger half of the squared values.
        // Note: if the array length is odd, the middle element
        // is included in this (added) half.
        for (int i = half; i < nums.size(); ++i) {
            answer += nums[i];
        }

        // Step 5: Return the maximum alternating sum obtained.
        return answer;
    }
};
