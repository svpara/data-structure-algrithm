class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        // prefixGcd[i] stores the gcd of nums[i] and the running maximum
        // value seen so far (from index 0 up to i)
        vector<int> prefixGcd(n);

        int maxSoFar = 0; // tracks the maximum element encountered while iterating

        for (int i = 0; i < n; i++) {
            int current = nums[i];
            maxSoFar = max(maxSoFar, current);   // update the running maximum
            prefixGcd[i] = gcd(current, maxSoFar); // gcd of current element and running max
        }

        // Sort the computed gcd values in ascending order so that we can
        // pair the smallest with the largest later
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        // Pair elements from both ends (two-pointer style):
        // smallest with largest, second smallest with second largest, etc.
        // Accumulate the gcd of each pair into the answer.
        for (int i = 0; i < n / 2; i++) {
            ans += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }

        return ans;
    }
};
