class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            int reversePosition = 26 - (ch - 'a');

            sum += reversePosition * (i + 1);
        }

        return sum;
    }
};