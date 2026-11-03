class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int maxValue = 0; // Track the maximum element in the array
        int sum = 0;      // Track the sum of all elements

        // Single pass to compute both the maximum value and the total sum
        for (int num : nums) {
            maxValue = max(maxValue, num);
            sum += num;
        }

        // Incrementing n-1 elements by 1 is equivalent (in relative terms)
        return maxValue * n - sum;
    }
};

