class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> ans;

        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {

                    if (i == j || j == k || i == k)
                        continue;

                    if (digits[i] == 0)  // first digit cannot be 0
                        continue;

                    if (digits[k] % 2 != 0)  // last digit must be even
                        continue;

                    int num = digits[i] * 100 +
                              digits[j] * 10 +
                              digits[k];

                    ans.insert(num);
                }
            }
        }

        return ans.size();
    }
};