class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns
        int ans = 0;                // maximum time taken

        // vis[i][j] tells whether this orange has already been processed
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Queue stores:
        // {{row, column}, time}
        queue<pair<pair<int, int>, int>> q;

        // STEP 1: Put all initially rotten oranges in queue
         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {

                    // This orange is already rotten at time 0
                    q.push({{i, j}, 0});

                    // Mark it visited
                    vis[i][j] = true;
                }
            }
        }

        // STEP 2: BFS
         while(q.size() > 0) {

            // Get the front orange
            int i = q.front().first.first;     // row
            int j = q.front().first.second;    // column
            int time = q.front().second;       // time taken

            // Remove it from queue
            q.pop();

            // Keep track of maximum time
            ans = max(ans, time);

            // Check TOp

            if(i - 1 >= 0 &&
               !vis[i - 1][j] &&
               grid[i - 1][j] == 1) {

                // Fresh orange becomes rotten after 1 minute
                q.push({{i - 1, j}, time + 1});

                // Mark immediately so we don't add it again
                vis[i - 1][j] = true;
            }
            //right
            if(j + 1 < m &&
               !vis[i][j + 1] &&
               grid[i][j + 1] == 1) {

                q.push({{i, j + 1}, time + 1});

                vis[i][j + 1] = true;
            }
            //bottom
            if(i + 1 < n &&
               !vis[i + 1][j] &&
               grid[i + 1][j] == 1) {

                q.push({{i + 1, j}, time + 1});

                vis[i + 1][j] = true;
            }
            //left
            if(j - 1 >= 0 &&
               !vis[i][j - 1] &&
               grid[i][j - 1] == 1) {

                q.push({{i, j - 1}, time + 1});

                vis[i][j - 1] = true;
            }
        }


        // --------------------------------------------------
        // STEP 3: Check if any fresh orange is still left
        // --------------------------------------------------

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Fresh orange that was never visited
                // means it could not be reached by any rotten orange
                if(grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }


        return ans;
    }
};
        
  