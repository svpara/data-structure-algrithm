class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return ans;

        unordered_map<string, int> need;

        for (string word : words)
            need[word]++;

        // Try every possible offset
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string, int> window;

            while (right + wordLen <= s.size()) {

                string word = s.substr(right, wordLen);
                right += wordLen;

                // Word is not required
                if (need.find(word) == need.end()) {
                    window.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                window[word]++;
                count++;

                // Too many copies of this word
                while (window[word] > need[word]) {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Found exactly wordCount words
                if (count == wordCount) {
                    ans.push_back(left);

                    // Move window forward
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};