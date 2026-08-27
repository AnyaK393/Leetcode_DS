class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // Map each number to its next greater element
        unordered_map<int, int> mp;

        stack<int> s;

        // Traverse nums2 from right to left
        for(int i = nums2.size() - 1; i >= 0; i--) {

            // Remove elements that are smaller than
            // or equal to nums2[i]
            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            // If stack is empty, there is no greater element
            if(s.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                // Top is the nearest greater element
                mp[nums2[i]] = s.top();
            }

            // Current element can be the next greater
            // element for elements on its left
            s.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;

        for(int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};