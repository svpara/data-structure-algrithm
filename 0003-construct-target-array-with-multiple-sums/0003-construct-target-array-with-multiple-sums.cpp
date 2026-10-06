#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;

        long long sum = 0;

        for (int x : target) {
            pq.push(x);
            sum += x;
        }

        while (true) {
            long long mx = pq.top();
            pq.pop();

            long long rest = sum - mx;

            // We reached the starting array
            if (mx == 1) {
                return true;
            }

            // No other elements
            if (rest == 0) {
                return false;
            }

            // The largest element must have been created
            if (mx <= rest) {
                return false;
            }

            // Special case: rest = 1
            // Previous value must be 1
            if (rest == 1) {
                pq.push(1);
                sum = 2;
                continue;
            }

            long long prev = mx % rest;

            // Cannot become 0
            if (prev == 0) {
                return false;
            }

            sum = rest + prev;
            pq.push(prev);
        }
    }
};