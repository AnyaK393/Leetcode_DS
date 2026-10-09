#include <string>
#include <iostream>

class Solution {
public:
    int minInsertions(std::string s) {
        int res = 0;
        int need = 0;
        
        for (char c : s) {
            if (c == '(') {
                need += 2;
                // If need is odd, we must insert a ')' immediately
                if (need % 2 != 0) {
                    res++;
                    need--;
                }
            } else {
                need--;
                // If need drops below 0, we encountered an unexpected ')'
                if (need < 0) {
                    res++;     // Insert a '(' to match it
                    need += 2; // We inserted '(' which gives +2 need, balancing out the -1
                }
            }
        }
        
        // Add any remaining closing parentheses needed
        return res + need;
    }
};
