class Solution {
public:
    bool isAnagram(string s, string t) {
        // Early return if strings have different lengths
        if (s.size() != t.size()) {
            return false;
        }
      
        // Create a frequency counter for 26 lowercase English letters
        vector<int> charFrequency(26, 0);
      
        // Process both strings simultaneously
        for (int i = 0; i < s.size(); ++i) {
            // Increment count for character in string s
            ++charFrequency[s[i] - 'a'];
            // Decrement count for character in string t
            --charFrequency[t[i] - 'a'];
        }
      
        // Check if all frequency counts are zero
        // If they are, both strings contain the same characters with same frequencies
        return all_of(charFrequency.begin(), charFrequency.end(), 
                     [](int count) { return count == 0; });
    }
};
