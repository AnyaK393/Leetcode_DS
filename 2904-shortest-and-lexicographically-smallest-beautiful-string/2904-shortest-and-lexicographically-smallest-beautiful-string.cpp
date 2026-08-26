class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        // Store the INDEX of every '1'
        // Example: s = "00111010"
        // ones = [2, 3, 4, 6]
        vector<int> ones;

        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                ones.push_back(i);
            }
        }

        // If total number of 1s is less than k,
        // it is impossible to make a substring
        // containing exactly k ones.
        if(ones.size() < k) {
            return "";
        }

        string ans = "";

        // Take every group of k consecutive 1s.
        //
        // ones[i]       = position of first 1
        // ones[i+k-1]   = position of kth 1
        //
        // The substring between these two positions
        // contains exactly k ones.
        for(int i = 0; i + k - 1 < ones.size(); i++) {

            int st = ones[i];
            int end = ones[i + k - 1];

            // Create substring from first 1 to kth 1
            string curr = s.substr(st, end - st + 1);

            // If this is our first valid substring
            // OR current substring is shorter
            // OR same length but lexicographically smaller,
            // update answer.
            if(ans == "" ||
               curr.size() < ans.size() ||
               (curr.size() == ans.size() && curr < ans)) {

                ans = curr;
            }
        }

        return ans;
    }
};