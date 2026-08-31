class Solution {
public:
    int maxVowels(string s, int k) {
        // Lambda function to check if a character is a vowel
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
      
        // Count vowels in the first window of size k
        int currentVowelCount = count_if(s.begin(), s.begin() + k, isVowel);
      
        // Initialize the maximum vowel count with the first window
        int maxVowelCount = currentVowelCount;
      
        // Slide the window through the string
        for (int i = k; i < s.size(); ++i) {
            // Add new character entering the window and remove the one leaving
            currentVowelCount += isVowel(s[i]) - isVowel(s[i - k]);
          
            // Update maximum if current window has more vowels
            maxVowelCount = max(maxVowelCount, currentVowelCount);
        }
      
        return maxVowelCount;
    }
};
