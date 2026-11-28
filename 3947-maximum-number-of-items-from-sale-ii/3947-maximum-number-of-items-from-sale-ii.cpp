#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   long long maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        // Step 1: Count frequency of each factor
        vector<int> freq(n + 1, 0);

        for (auto &item : items) {
            freq[item[0]]++;
        }

        // Step 2: Count multiples of every factor
        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
        }

        // Step 3: Calculate free-copy limits
        vector<int> freeLimit(n);

        for (int i = 0; i < n; i++) {
            freeLimit[i] = cnt[items[i][0]] - 1;
        }

        // Step 4: Find minimum price
        long long minPrice = LLONG_MAX;

        for (auto &item : items) {
            minPrice = min(minPrice, (long long)item[1]);
        }

        // Step 5: Sort items by price
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return items[a][1] < items[b][1];
        });

        // Step 6: Greedily purchase bonus copies
        long long remaining = budget;
        long long bonusCopies = 0;

        for (int i : order) {

            long long price = items[i][1];
            long long limit = freeLimit[i];

            if (price > 2 * minPrice) {
                break;
            }

            long long canBuy = min(
                limit,
                remaining / price
            );

            bonusCopies += canBuy;
            remaining -= canBuy * price;

            if (canBuy < limit) {
                break;
            }
        }

        // Step 7: Buy cheapest items with remaining budget
        long long purchased = remaining / minPrice;

        return 2 * bonusCopies + purchased;
    }
};
