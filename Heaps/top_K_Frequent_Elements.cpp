#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count the frequency of each number
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        // Step 2: Min heap storing {frequency, number}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Step 3: Traverse the frequency map
        for (auto it : mp) {

            int num = it.first;
            int freq = it.second;

            // Push {frequency, number}
            pq.push({freq, num});

            // Keep only k most frequent elements
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 4: Extract numbers from the heap
        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};