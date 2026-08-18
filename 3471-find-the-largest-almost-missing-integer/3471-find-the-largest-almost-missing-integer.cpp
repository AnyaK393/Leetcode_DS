class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        // Case 1: k == n
        if(k == n) {

            int maximum = -1;

            for(int i = 0; i < n; i++) {
                maximum = max(maximum, nums[i]);
            }

            return maximum;
        }

        // Case 2: k == 1
        else if(k == 1) {

            unordered_map<int, int> mp;

            for(int i = 0; i < n; i++) {
                mp[nums[i]]++;
            }

            int maximum = -1;

            for(auto it : mp) {
                if(it.second == 1) {
                    maximum = max(maximum, it.first);
                }
            }

            return maximum;
        }

        // Case 3: 1 < k < n
        else {

            int start = nums[0];
            int end = nums[n - 1];

            // Check if start appears anywhere else
            for(int i = 1; i < n; i++) {
                if(nums[i] == start) {
                    start = -1;
                    break;
                }
            }

            // Check if end appears anywhere else
            for(int i = 0; i < n - 1; i++) {
                if(nums[i] == end) {
                    end = -1;
                    break;
                }
            }

            return max(start, end);
        }
    }
};