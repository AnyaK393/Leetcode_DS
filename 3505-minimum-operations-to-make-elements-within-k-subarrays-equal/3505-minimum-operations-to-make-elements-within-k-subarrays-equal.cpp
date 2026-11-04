class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        // Step 1: Compute minimum operations to make each window of size x equal to its median
        const vector<long long> minOps = getMinOps(nums, x);
        
        // Step 2: Use Dynamic Programming to select k non-overlapping windows
        vector<vector<long long>> mem(nums.size() + 1, vector<long long>(k + 1, -1));
        return solveDP(nums, x, 0, k, minOps, mem);
    }

private:
    static constexpr long long kInf = LLONG_MAX / 2;

    long long solveDP(const vector<int>& nums, int x, int i, int k, 
                      const vector<long long>& minOps, vector<vector<long long>>& mem) {
        if (k == 0) return 0;
        if (i >= nums.size()) return kInf;
        if (mem[i][k] != -1) return mem[i][k];

        // Option 1: Skip the current element
        long long skip = solveDP(nums, x, i + 1, k, minOps, mem);

        // Option 2: Pick the window starting at index i (if it fits within the bounds)
        long long pick = kInf;
        if (i + x <= nums.size()) {
            long long nextCost = solveDP(nums, x, i + x, k - 1, minOps, mem);
            if (nextCost != kInf) {
                pick = minOps[i] + nextCost;
            }
        }

        return mem[i][k] = min(skip, pick);
    }

    vector<long long> getMinOps(const vector<int>& nums, int x) {
        vector<long long> minOps;
        multiset<int> lower;
        multiset<int> upper;
        long long lowerSum = 0;
        long long upperSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // Insert current element into the dual-multiset framework
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }

            // Evict the element going out of the sliding window
            if (i >= x) {
                int outNum = nums[i - x];
                if (auto it = lower.find(outNum); it != lower.end()) {
                    lower.erase(it);
                    lowerSum -= outNum;
                } else {
                    upper.erase(upper.find(outNum));
                    upperSum -= outNum;
                }
            }

            // Balance the multisets so that |lower| >= |upper| and |lower| - |upper| <= 1
            if (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(val);
                upperSum -= val;
                lowerSum += val;
            } else if (lower.size() - upper.size() > 1) {
                int val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                upper.insert(val);
                lowerSum -= val;
                upperSum += val;
            }

            // When a complete window of size x is formed, calculate L1 cost to the median
            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long ops = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
                minOps.push_back(ops);
            }
        }
        return minOps;
    }
};
