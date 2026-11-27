class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        // dp[j] represents the maximum number of items we can obtain
        // when spending exactly (or up to) j amount of budget via the
        // 0/1 knapsack selection below.
        vector<int> dp(budget + 1, 0);

        // Track the minimum price among all items so that any leftover
        // budget can be converted into extra items at the cheapest rate.
        int minPrice = INT_MAX;

        // Treat each item as a knapsack "object".
        for (const auto& item : items) {
            int factor = item[0];  // the factor value of the current item
            int price = item[1];   // the cost of choosing this item

            // Update the cheapest price seen so far.
            minPrice = min(minPrice, price);

            // Count how many items have a factor that is a multiple of
            // the current item's factor. This count is the "value"
            // gained by picking the current item.
            int count = 0;
            for (const auto& other : items) {
                if (other[0] % factor == 0) {
                    count++;
                }
            }

            // Standard 0/1 knapsack update, iterating the budget in
            // reverse so each item is used at most once in this step.
            for (int j = budget; j >= price; --j) {
                dp[j] = max(dp[j], dp[j - price] + count);
            }
        }

        // Combine the knapsack result with the conversion of any
        // remaining budget into additional items at the minimum price.
        int answer = 0;
        for (int j = 0; j <= budget; ++j) {
            answer = max(answer, dp[j] + (budget - j) / minPrice);
        }

        return answer;
    }
};
