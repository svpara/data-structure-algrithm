
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> tree(n);
        vector<int> newParent = parent;
        vector<int> ans(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> lastSeen(26, -1);

        // DFS to find closest matching ancestor
        function<void(int)> dfs = [&](int u) {

            int ch = s[u] - 'a';

            int old = lastSeen[ch];

            if (old != -1) {
                newParent[u] = old;
            }

            lastSeen[ch] = u;

            for (int v : tree[u]) {
                dfs(v);
            }

            lastSeen[ch] = old;
        };

        dfs(0);

        // Build modified tree
        vector<vector<int>> newTree(n);

        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        function<int(int)> calculate = [&](int u) {
            int size = 1;

            for (int v : newTree[u]) {
                size += calculate(v);
            }

            return ans[u] = size;
        };

        calculate(0);

        return ans;
    }
};



