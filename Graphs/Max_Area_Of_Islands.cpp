#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        // Base Case
        if (row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[0].size() ||
            grid[row][col] == 0)
        {
            return 0;
        }

        // Mark as visited
        grid[row][col] = 0; //change 1 to 0 to mark visited 

        // Count current cell + all connected cells
        return 1 +
               dfs(grid, row - 1, col) +
               dfs(grid, row + 1, col) +
               dfs(grid, row, col - 1) +
               dfs(grid, row, col + 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};