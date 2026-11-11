class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Strategy 1: Buy each item separately, no combined purchases.
        // Pay cost1 for every item of type 1 and cost2 for every item of type 2.
        long long buySeparately = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        // Strategy 2: Use only combined purchases to cover both demands.
        // Each combined purchase provides one of each type, so we need
        // max(need1, need2) combined purchases to satisfy the larger demand.
        long long buyAllCombined = 1LL * costBoth * max(need1, need2);

        // Strategy 3: Combine the overlapping portion, then buy the remainder.
        // Use combined purchases for the common amount min(need1, need2),
        // then buy the leftover of each type separately.
        int minNeed = min(need1, need2);
        long long buyMixed = 1LL * costBoth * minNeed
            + 1LL * (need1 - minNeed) * cost1
            + 1LL * (need2 - minNeed) * cost2;

        // Return the cheapest of the three strategies.
        return min({buySeparately, buyAllCombined, buyMixed});
    }
};
