#include <string>

class Solution {
private:
    // Helper function to map Roman characters to their integer values
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

public:
    int romanToInt(std::string s) {
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // If the current value is less than the next value, subtract it
            if (i + 1 < n && getValue(s[i]) < getValue(s[i + 1])) {
                total -= getValue(s[i]);
            } else {
                // Otherwise, add it
                total += getValue(s[i]);
            }
        }
        
        return total;
    }
};
