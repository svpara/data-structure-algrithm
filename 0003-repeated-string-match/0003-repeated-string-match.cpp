class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int count = 0;

        // Repeat until length is at least b
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check after minimum required repetitions
        if (repeated.find(b) != string::npos)
            return count;

        // Sometimes one extra repetition is required
        repeated += a;
        count++;

        if (repeated.find(b) != string::npos)
            return count;

        return -1;
    }
};