class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // 1. Find the pivot
        int pivot = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // No pivot → array is in descending order
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. Find rightmost element greater than pivot
        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // 3. Reverse elements after pivot
        int i = pivot + 1;
        int j = n - 1;

        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};