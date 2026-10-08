class Solution {
public:
    string maskPII(string s) {

        // ---------------- EMAIL ----------------
        if (s.find('@') != string::npos) {

            int pos = s.find('@');

            string name = s.substr(0, pos);
            string domain = s.substr(pos + 1);

            // Convert everything to lowercase
            for (char &c : name)
                c = tolower(c);

            for (char &c : domain)
                c = tolower(c);

            return string(1, name[0]) + "*****" +
                   string(1, name.back()) + "@" + domain;
        }

        // ---------------- PHONE ----------------
        string digits;

        // Keep only digits
        for (char c : s) {
            if (isdigit(c))
                digits += c;
        }

        int countryCode = digits.length() - 10;

        // Last 4 digits
        string lastFour = digits.substr(digits.length() - 4);

        string ans;

        if (countryCode == 0) {
            ans = "***-***-" + lastFour;
        }
        else {
            ans = "+";

            // Add country code stars
            for (int i = 0; i < countryCode; i++) {
                ans += '*';
            }

            ans += "-***-***-" + lastFour;
        }

        return ans;
    }
};