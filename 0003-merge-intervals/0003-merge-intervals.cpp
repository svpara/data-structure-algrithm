
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by their start values
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Step 2: Process each interval
        for (auto& interval : intervals) {
            // If result is empty, or intervals do not overlap
            if (result.empty() ||
                interval[0] > result.back()[1]) {
                result.push_back(interval);
            } 
            else {
                // Merge overlapping intervals
                result.back()[1] =
                    max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};
