class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int left = 0;
        int ans = 0;

        unordered_map<int, int> freq;

        for(int right = 0; right < nums.size(); right++) {

            freq[nums[right]]++;

            // Shrink window if frequency exceeds k
            while(freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            // Current valid window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};