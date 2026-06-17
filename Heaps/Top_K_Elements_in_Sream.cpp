#include<iostream>
#include<vector>

using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        // Store k
        this->k = k;

        // Process initial numbers
        for (int num : nums) {
            pq.push(num);

            // Keep only k largest elements
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        // Insert new element
        pq.push(val);

        // Keep heap size at k
        if (pq.size() > k)
            pq.pop();

        // Root is the kth largest
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */