class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // If already sorted, no operations are needed
        if(is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // A reversed string of length 2 cannot be sorted
        // because sorting the entire string is not allowed
        if(n == 2) {
            return -1;
        }

        // Find the smallest and largest characters
        char min_char = *min_element(s.begin(), s.end());
        char max_char = *max_element(s.begin(), s.end());

        // If the smallest is already first OR largest is already last
        // one operation is enough
        if(s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }

        // Check whether the smallest or largest character
        // appears between the first and last positions
        for(int i = 1; i < n - 1; i++) {
            if(s[i] == min_char || s[i] == max_char) {
                return 2;
            }
        }

        // Smallest is at the end and largest is at the beginning
        // with neither appearing in the middle
        return 3;
    }
};