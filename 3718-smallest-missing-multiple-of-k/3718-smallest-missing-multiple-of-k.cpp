class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> s;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(nums[i] % k == 0) {
                s.insert(nums[i]);
            }
        }

        int multiple = k;

        while(s.find(multiple) != s.end()) {
            multiple += k;
        }

        return multiple;
    }
};