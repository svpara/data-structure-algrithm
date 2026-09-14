class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }

        auto findFirstTrue = [&](bool findGreater) -> int {
            int left = 0;
            int right = n - 1;
            int firstTrueIndex = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                bool feasible;
                if (findGreater) {
                    feasible = nums[mid] > target;
                } else {
                    feasible = nums[mid] >= target;
                }

                if (feasible) {
                    firstTrueIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            return firstTrueIndex;
        };

        int firstIdx = findFirstTrue(false);
        if (firstIdx == -1 || nums[firstIdx] != target) {
            return {-1, -1};
        }

        int afterLastIdx = findFirstTrue(true);
        int lastIdx;
        if (afterLastIdx == -1) {
            lastIdx = n - 1;
        } else {
            lastIdx = afterLastIdx - 1;
        }

        return {firstIdx, lastIdx};
    }
};