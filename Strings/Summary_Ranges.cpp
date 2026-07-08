#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;

        for (int i = 0; i < nums.size(); i++) {

            int start = nums[i];

            while (i < nums.size() - 1 && nums[i] + 1 == nums[i + 1]) {
                i++;
            }

            if (start == nums[i]) {
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }

        return ans;
    }
};