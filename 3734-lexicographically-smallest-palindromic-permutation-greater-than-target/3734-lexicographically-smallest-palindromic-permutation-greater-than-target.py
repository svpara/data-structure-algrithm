
from collections import Counter

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        half = n // 2

        count = Counter(s)

        # Check palindrome possibility
        odd = 0
        middle = ""

        for ch in count:
            if count[ch] % 2 == 1:
                odd += 1
                middle = ch

        if odd > 1:
            return ""

        # Frequency of characters for left half
        freq = [0] * 26

        for ch in count:
            freq[ord(ch) - ord('a')] = count[ch] // 2

        target_half = target[:half]

        # Check if target_half can be used directly
        remaining = freq[:]
        possible = True

        for ch in target_half:
            x = ord(ch) - ord('a')

            if remaining[x] == 0:
                possible = False
                break

            remaining[x] -= 1

        # Target itself can be converted to palindrome
        if possible:
            left = target_half
            palindrome = left + middle + left[::-1]

            if palindrome > target:
                return palindrome

        # Find smallest half greater than target_half
        for i in range(half - 1, -1, -1):

            remaining = freq[:]
            valid = True

            # Keep prefix same as target
            for j in range(i):
                x = ord(target_half[j]) - ord('a')

                if remaining[x] == 0:
                    valid = False
                    break

                remaining[x] -= 1

            if not valid:
                continue

            current = ord(target_half[i]) - ord('a')

            # Choose smallest character greater than target[i]
            for x in range(current + 1, 26):

                if remaining[x] > 0:
                    remaining[x] -= 1

                    left = target_half[:i] + chr(x + ord('a'))

                    # Fill remaining characters in sorted order
                    for c in range(26):
                        while remaining[c] > 0:
                            left += chr(c + ord('a'))
                            remaining[c] -= 1

                    return left + middle + left[::-1]

        return ""

