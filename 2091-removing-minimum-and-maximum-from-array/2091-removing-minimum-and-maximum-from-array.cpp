class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        // Store the INDEX of the minimum element
        int minIdx = 0;

        // Store the INDEX of the maximum element
        int maxIdx = 0;

        // Find positions of minimum and maximum elements
        for(int i = 0; i < n; i++) {

            if(nums[i] < nums[minIdx]) {
                minIdx = i;
            }

            if(nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        // left = index of the one that occurs first
        // right = index of the one that occurs later
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);


        // OPTION 1:
        // Delete everything from the FRONT
        //
        // We need to delete up to 'right',
        // because the element at right is the last
        // one we need to remove.
        int front = right + 1;


        // OPTION 2:
        // Delete everything from the BACK
        //
        // We need to delete from the end until 'left'.
        int back = n - left;


        // OPTION 3:
        // Delete from BOTH sides
        //
        // Delete from the front up to 'left'
        // AND delete from the back after 'right'.
        int both = (left + 1) + (n - right);


        // Take the minimum of the three strategies
        return min({front, back, both});
    }
};