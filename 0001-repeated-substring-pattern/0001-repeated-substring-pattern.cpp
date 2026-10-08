class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int len = 1; len <= n / 2; len++) {
            if (n % len != 0)
                continue;

            bool ok = true;

            for (int i = len; i < n; i++) {
                if (s[i] != s[i % len]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return true;
        }

        return false;
    }
};