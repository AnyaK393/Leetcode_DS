class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Initialize an m x n grid filled entirely with obstacles '#'
        vector<string> grid(m, string(n,'#'));
        // Open the entire first row
        grid[0]=string(n, '.');

        // Open the entire last column
        for(int i=0;i<m;i++){
            grid[i][n-1]='.';
        }
        return grid;
    }
};