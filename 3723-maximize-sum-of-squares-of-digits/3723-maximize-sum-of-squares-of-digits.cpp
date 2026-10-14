class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If even filling every digit with 9 cannot reach the target sum,
        // there is no valid number, so return an empty string.
        if (num * 9 < sum) {
            return "";
        }

        // To maximize the number, place as many 9s as possible at the front.
        // nineCount: how many full 9s we can use.
        // remainder: the leftover digit value after using the 9s.
        int nineCount = sum / 9;
        int remainder = sum % 9;

        // Start the answer with nineCount consecutive '9' characters.
        string ans(nineCount, '9');

        // If there is a leftover value, append it as the next digit.
        if (remainder > 0) {
            ans += char('0' + remainder);
        }

        // Pad the rest of the number with '0's to reach exactly num digits.
        ans += string(num - ans.size(), '0');

        return ans;
    }
};
