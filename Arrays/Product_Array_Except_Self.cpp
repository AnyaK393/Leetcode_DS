#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);
        vector<int> answer(n);

        // Base cases
        left[0] = 1;
        right[n - 1] = 1;

        // Build left array
        for(int i = 1; i < n; i++) {
            left[i] = left[i-1]* nums[i-1];
        }

        // Build right array
        for(int i = n - 2; i >= 0; i--) {
            right[i] = right[i+1]* nums[i+1];
        }

        // Build answer
        for(int i = 0; i < n; i++) {
            answer[i] = left[i]* right[i];
        }

        return answer;
    }
};