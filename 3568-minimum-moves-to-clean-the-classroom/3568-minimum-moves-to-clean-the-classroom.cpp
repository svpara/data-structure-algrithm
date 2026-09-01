class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size();
        int cols = classroom[0].size();
      
        // Store the index of each light ('L') in the grid
        vector<vector<int>> lightIndex(rows, vector<int>(cols, 0));
        int startRow = 0, startCol = 0;
        int lightCount = 0;
      
        // Find starting position and count lights
        for (int i = 0; i < rows; ++i) {
            string& currentRow = classroom[i];
            for (int j = 0; j < cols; ++j) {
                char cell = currentRow[j];
                if (cell == 'S') {
                    // Mark starting position
                    startRow = i;
                    startCol = j;
                } else if (cell == 'L') {
                    // Assign index to each light
                    lightIndex[i][j] = lightCount;
                    lightCount++;
                }
            }
        }
      
        // If no lights to turn off, return 0
        if (lightCount == 0) {
            return 0;
        }
      
        // 4D visited array: [row][col][energy][light_mask]
        // light_mask uses bits to represent which lights are still on
        vector<vector<vector<vector<bool>>>> visited(rows, 
            vector<vector<vector<bool>>>(cols, 
                vector<vector<bool>>(energy + 1, 
                    vector<bool>(1 << lightCount, false))));
      
        // BFS queue: stores (row, col, current_energy, light_mask)
        queue<tuple<int, int, int, int>> bfsQueue;
      
        // Initial state: all lights are on (all bits set to 1)
        int allLightsOn = (1 << lightCount) - 1;
        bfsQueue.emplace(startRow, startCol, energy, allLightsOn);
        visited[startRow][startCol][energy][allLightsOn] = true;
      
        // Direction vectors for 4-directional movement (up, right, down, left)
        vector<int> directions = {-1, 0, 1, 0, -1};
      
        int moves = 0;
      
        // BFS to find minimum moves
        while (!bfsQueue.empty()) {
            int levelSize = bfsQueue.size();
          
            // Process all nodes at current level
            while (levelSize--) {
                auto [currentRow, currentCol, currentEnergy, lightMask] = bfsQueue.front();
                bfsQueue.pop();
              
                // Check if all lights are turned off
                if (lightMask == 0) {
                    return moves;
                }
              
                // Skip if no energy left
                if (currentEnergy <= 0) {
                    continue;
                }
              
                // Try all 4 directions
                for (int dir = 0; dir < 4; ++dir) {
                    int nextRow = currentRow + directions[dir];
                    int nextCol = currentCol + directions[dir + 1];
                  
                    // Check if next position is valid and not a wall
                    if (nextRow >= 0 && nextRow < rows && 
                        nextCol >= 0 && nextCol < cols && 
                        classroom[nextRow][nextCol] != 'X') {
                      
                        // Calculate energy for next position
                        // Recharge stations ('R') restore energy to max
                        int nextEnergy = (classroom[nextRow][nextCol] == 'R') ? 
                                        energy : currentEnergy - 1;
                      
                        // Update light mask if stepping on a light
                        int nextLightMask = lightMask;
                        if (classroom[nextRow][nextCol] == 'L') {
                            // Turn off the light at this position
                            nextLightMask &= ~(1 << lightIndex[nextRow][nextCol]);
                        }
                      
                        // Add to queue if this state hasn't been visited
                        if (!visited[nextRow][nextCol][nextEnergy][nextLightMask]) {
                            visited[nextRow][nextCol][nextEnergy][nextLightMask] = true;
                            bfsQueue.emplace(nextRow, nextCol, nextEnergy, nextLightMask);
                        }
                    }
                }
            }
            moves++;
        }
      
        // No solution found
        return -1;
    }
};
