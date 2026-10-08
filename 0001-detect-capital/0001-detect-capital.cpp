class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();

        // Case 1: All letters are uppercase
        bool allUpper = true;
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                allUpper = false;
                break;
            }
        }

        // Case 2: All letters are lowercase
        bool allLower = true;
        for (char c : word) {
            if (c >= 'A' && c <= 'Z') {
                allLower = false;
                break;
            }
        }

        // Case 3: Only first letter is uppercase
        bool firstUpper = (word[0] >= 'A' && word[0] <= 'Z');
        bool restLower = true;

        for (int i = 1; i < n; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                restLower = false;
                break;
            }
        }

        return allUpper || allLower || (firstUpper && restLower);
    }
};