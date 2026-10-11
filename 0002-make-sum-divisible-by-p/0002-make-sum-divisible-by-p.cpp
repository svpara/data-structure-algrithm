class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;

        for (int x : nums) {
            total = (total + x) % p;
        }

        int target = total;
        if (target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0;
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;

            int need = (prefix - target + p) % p;

            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }

            mp[prefix] = i;
        }

        return ans == n ? -1 : ans;
    }
};