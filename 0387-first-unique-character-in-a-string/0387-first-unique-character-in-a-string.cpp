class Solution {
public:
    int firstUniqChar(string s) {

        // Store frequency of every character
        unordered_map<char, int> freq;

        // Count each character
        for(char c : s) {
            freq[c]++;
        }

        // Find the FIRST character with frequency 1
        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};