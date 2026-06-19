#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int perimeter = 0;

        // Traverse every cell
        for (int i = 0; i < grid.size(); i++) {

            for (int j = 0; j < grid[0].size(); j++) {

                // Process only land cells
                if (grid[i][j] == 1) {

                    // Every land cell contributes 4 sides
                    perimeter += 4;

                    // Check the right neighbor
                    if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
                        perimeter -= 2;
                    }

                    // Check the down neighbor
                    if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }

        return perimeter;
    }
};