class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) {
            return {-1, -1}; // Target does not exist at all
        }
        int last = findBound(nums, target, false);
        return {first, last};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1; // Defaults to -1 if target is never found

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid; // Record the index, then keep searching
                if (isFirst) {
                    right = mid - 1; // Keep looking to the left for an earlier match
                } else {
                    left = mid + 1;  // Keep looking to the right for a later match
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return bound;
    }
};
