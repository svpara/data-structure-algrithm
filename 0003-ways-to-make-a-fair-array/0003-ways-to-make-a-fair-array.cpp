class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int totalEven = 0, totalOdd = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                totalEven += nums[i];
            else
                totalOdd += nums[i];
        }

        int leftEven = 0, leftOdd = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rightEven = totalEven - leftEven;
            int rightOdd = totalOdd - leftOdd;

            if (i % 2 == 0)
                rightEven -= nums[i];
            else
                rightOdd -= nums[i];

            if (leftEven + rightOdd == leftOdd + rightEven)
                count++;

            if (i % 2 == 0)
                leftEven += nums[i];
            else
                leftOdd += nums[i];
        }

        return count;
    }
};