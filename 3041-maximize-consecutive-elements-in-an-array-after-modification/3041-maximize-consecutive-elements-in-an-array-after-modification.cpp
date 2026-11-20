#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // Max value in nums is 10^6, and we can increment it by 1
        int max_val = nums.back() + 2;
        vector<int> dp(max_val, 0);
        
        int ans = 0;
        for (int x : nums) {
            // 1. Try incrementing x -> x + 1 (extends sequence ending at x)
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            
            // 2. Try keeping x -> x (extends sequence ending at x - 1)
            dp[x] = max(dp[x], dp[x - 1] + 1);
            
            ans = max({ans, dp[x], dp[x + 1]});
        }
        
        return ans;
    }
};
