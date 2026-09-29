class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Total path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Start must be '(' and end must be ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        auto dfs = [&](this auto&& dfs, int r, int c, int balance) -> bool {

            // Same state already checked
            if (visited[r][c][balance])
                return false;

            visited[r][c][balance] = true;

            // Update balance using current cell
            if (grid[r][c] == '(')
                balance++;
            else
                balance--;

            // Invalid prefix
            if (balance < 0)
                return false;

            // Number of cells/moves remaining
            int remaining = (m - 1 - r) + (n - 1 - c);

            // Not enough ')' left to make balance zero
            if (balance > remaining)
                return false;

            // Destination
            if (r == m - 1 && c == n - 1)
                return balance == 0;

            // Down
            if (r + 1 < m) {
                if (dfs(r + 1, c, balance))
                    return true;
            }

            // Right
            if (c + 1 < n) {
                if (dfs(r, c + 1, balance))
                    return true;
            }

            return false;
        };

        return dfs(0, 0, 0);
    }
};