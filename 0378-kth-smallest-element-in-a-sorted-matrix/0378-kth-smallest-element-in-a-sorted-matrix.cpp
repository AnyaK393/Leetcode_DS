class Solution {
private:
    // Helper function to count elements less than or equal to 'target'
    int countLessOrEqual(const vector<vector<int>>& matrix, int target, int n) {
        int count = 0;
        int row = n - 1; // Start from the bottom-left corner
        int col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                // If the current element is <= target, then all elements 
                // above it in the same column are also <= target.
                count += (row + 1);
                col++; // Move to the next column
            } else {
                row--; // Move up to find smaller elements
            }
        }
        return count;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        // The search space is defined by actual element values, not matrix indices
        int low = matrix[0][0];          // Smallest element
        int high = matrix[n - 1][n - 1]; // Largest element
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count how many elements in the matrix are <= mid
            if (countLessOrEqual(matrix, mid, n) >= k) {
                ans = mid;      // mid could be our answer, save it
                high = mid - 1; // Try to find a smaller value in the left half
            } else {
                low = mid + 1;  // Look for a larger value in the right half
            }
        }
        return ans;
    }
};