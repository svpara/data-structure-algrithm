class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // Get board dimensions
        int rows = board.size();
        int cols = board[0].size();
      
        // Direction vectors for exploring 4 adjacent cells (up, right, down, left)
        int directions[5] = {-1, 0, 1, 0, -1};
      
        // DFS function to mark connected 'O' cells starting from border
        function<void(int, int)> depthFirstSearch = [&](int row, int col) {
            // Check boundaries and if current cell is 'O'
            if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O') {
                return;
            }
          
            // Mark current 'O' as temporary '.' to indicate it's connected to border
            board[row][col] = '.';
          
            // Explore all 4 adjacent cells
            for (int k = 0; k < 4; ++k) {
                depthFirstSearch(row + directions[k], col + directions[k + 1]);
            }
        };
      
        // Process left and right borders - mark all 'O's connected to borders
        for (int i = 0; i < rows; ++i) {
            depthFirstSearch(i, 0);           // Left border
            depthFirstSearch(i, cols - 1);    // Right border
        }
      
        // Process top and bottom borders (excluding corners already processed)
        for (int j = 1; j < cols - 1; ++j) {
            depthFirstSearch(0, j);           // Top border
            depthFirstSearch(rows - 1, j);   // Bottom border
        }
      
        // Final pass: convert marked cells and flip surrounded regions
        for (auto& row : board) {
            for (auto& cell : row) {
                if (cell == '.') {
                    // Restore border-connected 'O's back to 'O'
                    cell = 'O';
                } else if (cell == 'O') {
                    // Flip surrounded 'O's to 'X'
                    cell = 'X';
                }
            }
        }
    }
};
