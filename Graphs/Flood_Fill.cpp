#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:

    void dfs(vector<vector<int>>& image, int row, int col, int oldColor, int newColor)
    {
        // Base Case
        if (row < 0 || row >= image.size() ||
            col < 0 || col >= image[0].size() ||
            image[row][col] != oldColor)
        {
            return;
        }

        // Change current cell to new color
        image[row][col] = newColor;

        // Explore 4 directions
        dfs(image, row - 1, col, oldColor, newColor);
        dfs(image, row + 1, col, oldColor, newColor);
        dfs(image, row, col - 1, oldColor, newColor);
        dfs(image, row, col + 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        // Store original color
        int oldColor = image[sr][sc];

        // Edge case
        if (oldColor == color)
            return image;

        // Start DFS
        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};