class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int sum = nums[0];

        // Find sequential prefix sum
        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        // Store all numbers for quick lookup
        unordered_set<int> s(nums.begin(), nums.end());

        // Find smallest missing integer >= sum
        while(s.count(sum)) {
            sum++;
        }

        return sum;
    }
};