#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_factor = 0;
        
        // 1. Find the maximum factor value (bounded by n)
        for (const auto& item : items) {
            max_factor = max(max_factor, item[0]);
        }
        
        // 2. Count frequency of each factor
        vector<int> freq(max_factor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }
        
        // 3. Precompute valid freebie partners for each factor f: O(N log N)
        vector<int> valid_partners(max_factor + 1, 0);
        for (int f = 1; f <= max_factor; ++f) {
            if (freq[f] == 0) continue;
            for (int multiple = f; multiple <= max_factor; multiple += f) {
                valid_partners[f] += freq[multiple];
            }
            valid_partners[f]--; // Exclude the item itself (j != i)
        }
        
        // 4. Sort items by price ascending to prioritize cheapest 2-for-1 deals
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        long long min_price = items[0][1];
        long long total_items = 0;
        long long rem_budget = budget;
        
        // 5. Greedily buy bonus copies while price < 2 * min_price
        for (const auto& item : items) {
            int f = item[0];
            long long price = item[1];
            
            if (price >= 2 * min_price) break; // Cheaper to buy min_price twice
            
            long long max_bonus_copies = valid_partners[f];
            if (max_bonus_copies > 0 && rem_budget >= price) {
                long long can_buy = min(max_bonus_copies, rem_budget / price);
                total_items += can_buy * 2; // 1 purchased + 1 free per copy
                rem_budget -= can_buy * price;
            }
        }
        
        // 6. Spend remaining budget on the single cheapest item
        total_items += rem_budget / min_price;
        
        return (int)total_items;
    }
};
