class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        int i = 0;
        int j = 0;

        int currSum = 0;

        // BestMinLenTillIdx[j] =
        // smallest valid subarray length found from index 0 to j
        vector<int> BestMinLenTillIdx(n, INT_MAX);

        int BestMinLen = INT_MAX;
        int result = INT_MAX;

        while(j < n) {

            currSum += arr[j];

            // Shrink window while sum is too large
            while(i <= j && currSum > target) {
                currSum -= arr[i];
                i++;
            }

            // We found a subarray with target sum
            if(currSum == target) {

                int len = j - i + 1;

                // Check if there is a previous non-overlapping
                // subarray ending before i
                if(i > 0 && BestMinLenTillIdx[i - 1] != INT_MAX) {
                    result = min(
                        result,
                        len + BestMinLenTillIdx[i - 1]
                    );
                }

                // Keep the smallest target-sum subarray found so far
                BestMinLen = min(BestMinLen, len);
            }

            // Store best answer till current index
            BestMinLenTillIdx[j] = BestMinLen;

            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};