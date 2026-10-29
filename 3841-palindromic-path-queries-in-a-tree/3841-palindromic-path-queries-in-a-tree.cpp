class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, sz;
    vector<int> seg;
    string s;
    int timer = 0;

    int getMask(char c) {
        return 1 << (c - 'a');
    }

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        int maxSize = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int childSize = dfs(v, u);
            sz[u] += childSize;

            if (childSize > maxSize) {
                maxSize = childSize;
                heavy[u] = v;
            }
        }

        return sz[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1) {
            decompose(heavy[u], h);
        }

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;

            decompose(v, v);
        }
    }

    void build(int node, int l, int r,
               vector<int>& values) {
        if (l == r) {
            seg[node] = values[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, values);
        build(node * 2 + 1, mid + 1, r, values);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r,
                int idx, int value) {
        if (l == r) {
            seg[node] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, value);
        else
            update(node * 2 + 1, mid + 1, r, idx, value);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r,
              int ql, int qr) {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr) ^
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int pathMask(int u, int v) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(
                1, 0, n - 1, pos[head[u]], pos[u]
            );

            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);

        return mask;
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        this->s = s;
        timer = 0;

        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sz.assign(n, 0);

        dfs(0, -1);
        decompose(0, 0);

        vector<int> values(n);

        for (int i = 0; i < n; i++)
            values[pos[i]] = getMask(s[i]);

        seg.assign(4 * n, 0);
        build(1, 0, n - 1, values);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                this->s[u] = c;

                update(
                    1, 0, n - 1, pos[u], getMask(c)
                );
            } else {
                int v;
                ss >> v;

                int mask = pathMask(u, v);

                ans.push_back(
                    mask == 0 ||
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};