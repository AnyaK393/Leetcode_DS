class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int min_val = INT_MAX;

        // Find the sum and the minimum value in a single loop
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(nums[i] < min_val){
                min_val = nums[i];
            }
        }
        
        // Formula: Total Sum - (Number of elements * Minimum Element)
        return sum - ((long long)nums.size() * min_val);
    }
};
