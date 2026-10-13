
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // We are on the increasing slope
                left = mid + 1;
            } else {
                // We are at or beyond the peak
                right = mid;
            }
        }

        return left;
    }
};
