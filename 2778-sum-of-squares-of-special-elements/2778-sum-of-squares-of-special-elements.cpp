class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
      
        // Initialize the result variable to store sum of squares
        int result = 0;
      
        // Iterate through all possible divisors of n (1-indexed)
        for (int i = 1; i <= n; ++i) {
            // Check if i is a divisor of n
            if (n % i == 0) {
                // If i divides n, add the square of the element at position (i-1)
                // Note: i is 1-indexed, but array is 0-indexed, hence nums[i-1]
                result += nums[i - 1] * nums[i - 1];
            }
        }
      
        // Return the sum of squares of elements at divisor positions
        return result;
    }
};
