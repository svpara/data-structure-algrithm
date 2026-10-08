class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t;

        // Remove '-' and convert lowercase to uppercase
        for (char c : s) {
            if (c != '-') {
                t += toupper(c);
            }
        }

        string ans;
        int count = 0;

        // Build groups from right to left
        for (int i = t.size() - 1; i >= 0; i--) {
            if (count == k) {
                ans += '-';
                count = 0;
            }

            ans += t[i];
            count++;
        }

        // We built the answer backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};