class Solution {
public:
    int minimizeSum(vector<int>& nums) {
       int n=nums.size();

       sort(nums.begin(), nums.end());

        //low =0
        //high
       return min({
        nums[n-2]-nums[1], //highest and lowest changed
        nums[n-3]-nums[0],//highest changed to middle 
        nums[n-1]-nums[2] //lowest chnaged to middle 
       }) ;


    }
};