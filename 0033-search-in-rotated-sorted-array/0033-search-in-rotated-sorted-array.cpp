class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            // target found
            if(nums[mid] == target) {
                return mid;
            }


            // left half is sorted
            if(nums[start] <= nums[mid]) {

                // target lies in left sorted part
                if(target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                }

                // go right
                else {
                    start = mid + 1;
                }
            }


            // right half is sorted
            else {

                // target lies in right sorted part
                if(target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                }

                // go left
                else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};