class Solution {
public:
    // Helper function to maintain the Max-Heap property
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;       // Initialize largest as root
        int left = 2 * i + 1;  // Left child index
        int right = 2 * i + 2; // Right child index

        // Check if left child exists and is greater than root
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        // Check if right child exists and is greater than the largest so far
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        // If the largest element is not the root, swap and continue heapifying
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build the Max-Heap from the input array
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Step 2: Extract elements from the heap one by one
        for (int i = n - 1; i > 0; i--) {
            // Move current root (maximum element) to the end of the unsorted boundary
            swap(nums[0], nums[i]);

            // Call max heapify on the reduced heap to restore heap structure
            heapify(nums, i, 0);
        }

        return nums;
    }
};
