class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        // prefix[i] = maximum from index 0 to i
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i-1], nums[i]);
        }

        // suffix[i] = minimum from index i to n-1
        suffix[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--) {
            suffix[i] = min(suffix[i+1], nums[i]);
        }

        // Find first stable index
        for(int i = 0; i < n; i++) {
            int instability = prefix[i] - suffix[i];

            if(instability <= k) {
                return i;
            }
        }

        return -1;
    }
};