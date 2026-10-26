class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Direction vectors for moving up, right, down, left
        // Using pairs: (-1,0), (0,1), (1,0), (0,-1)
        vector<int> directions = {-1, 0, 1, 0, -1};

        // Recursive lambda function to perform DFS and calculate island sum
        // Uses explicit this parameter (C++23 feature) for recursive lambda
        auto depthFirstSearch = [&](this auto&& depthFirstSearch, int row, int col) -> long long {
            // Store current cell value as the starting sum
            long long islandSum = grid[row][col];
          
            // Mark current cell as visited by setting it to 0
            grid[row][col] = 0;
          
            // Explore all 4 adjacent directions
            for (int dir = 0; dir < 4; ++dir) {
                int nextRow = row + directions[dir];
                int nextCol = col + directions[dir + 1];
              
                // Check if the next cell is within bounds and contains a non-zero value
                if (nextRow >= 0 && nextRow < rows && 
                    nextCol >= 0 && nextCol < cols && 
                    grid[nextRow][nextCol] != 0) {
                    // Recursively add the sum of connected cells
                    islandSum += depthFirstSearch(nextRow, nextCol);
                }
            }
          
            return islandSum;
        };

        int islandCount = 0;
      
        // Iterate through each cell in the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If cell is non-zero (part of an unvisited island)
                if (grid[i][j] != 0) {
                    // Calculate the sum of the entire island
                    long long currentIslandSum = depthFirstSearch(i, j);
                  
                    // If the island sum is divisible by k, increment counter
                    if (currentIslandSum % k == 0) {
                        ++islandCount;
                    }
                }
            }
        }
      
        return islandCount;
    }
};
