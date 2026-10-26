#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long dfs(int i, int j, vector<vector<int>>& grid) {
        long long sum = grid[i][j];
        grid[i][j] = 0; // Mark as visited
        
        for (const vector<int> &dir : directions) {
            int i_ = i + dir[0]; // Calculate neighbor's row index
            int j_ = j + dir[1]; // Calculate neighbor's column index
            
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                sum += dfs(i_, j_, grid);
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid); // Fixed argument passing syntax
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count; // Returns the total number of valid islands
    }
};
