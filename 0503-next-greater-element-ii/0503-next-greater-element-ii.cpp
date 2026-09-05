class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // Answer array of size n, initially filled with -1
        vector<int> ans(n, -1);

        // Stack stores indices of elements
        stack<int> s;

        // Traverse array twice because the array is circular
        // i = 2*n-1 means we simulate going around the array twice
        for(int i = 2*n-1; i >= 0; i--) {

            // Remove all elements from stack that are
            // smaller than or equal to current element
            // because they cannot be the next greater element
            while(!s.empty() && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }

            // If stack is not empty, top is the next greater element
            if(!s.empty()) {
                ans[i % n] = nums[s.top()];
            }

            // Push current index into stack
            s.push(i % n);
        }

        return ans;
    }
};