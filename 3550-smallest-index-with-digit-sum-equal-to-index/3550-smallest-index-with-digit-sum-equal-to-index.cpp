class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int num = nums[i];
            int sum = 0;

            // Get sum of digits of nums[i]
            while(num > 0) {
                int lastdigit = num % 10;
                sum += lastdigit;
                num = num / 10;
            }

            // Check digit sum == index
            if(sum == i) {
                return i;
            }
        }

        return -1;
    }
};