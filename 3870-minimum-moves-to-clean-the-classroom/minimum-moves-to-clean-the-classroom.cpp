class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startR = -1, startC = -1;
        int litterCount = 0;
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        
        // Locate 'S' and assign an ID to each litter cell 'L'
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    litterId[r][c] = litterCount++;
                }
            }
        }
        
        // If there is no litter to collect, 0 moves are needed
        if (litterCount == 0) return 0;
        
        int targetMask = (1 << litterCount) - 1;
        
        // bestEnergy[r][c][mask] stores the maximum remaining energy seen at this state
        // Initialized to -1 (unvisited)
        vector<vector<vector<int>>> bestEnergy(
            m, vector<vector<int>>(n, vector<int>(1 << litterCount, -1))
        );
        
        // Queue elements: {row, col, mask, current_energy}
        queue<tuple<int, int, int, int>> q;
        
        q.push({startR, startC, 0, energy});
        bestEnergy[startR][startC][0] = energy;
        
        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            while (levelSize--) {
                auto [r, c, mask, curEnergy] = q.front();
                q.pop();
                
                // If all litter has been collected, return total moves
                if (mask == targetMask) {
                    return moves;
                }
                
                // If we ran out of energy and didn't reach the target, cannot move further
                if (curEnergy <= 0) {
                    continue;
                }
                
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    
                    // Boundary and obstacle check
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                        continue;
                    }
                    
                    int nextEnergy = curEnergy - 1;
                    int nextMask = mask;
                    
                    // Check for litter
                    if (classroom[nr][nc] == 'L') {
                        nextMask |= (1 << litterId[nr][nc]);
                    }
                    
                    // Check for reset station
                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }
                    
                    // Prune if we have visited this cell with the same mask and >= energy
                    if (nextEnergy > bestEnergy[nr][nc][nextMask]) {
                        bestEnergy[nr][nc][nextMask] = nextEnergy;
                        q.push({nr, nc, nextMask, nextEnergy});
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};