class Solution {
public:
    bool checkValidString(string s) {

        // minBalance = minimum possible '(' balance
        // maxBalance = maximum possible '(' balance
        int minBalance = 0;
        int maxBalance = 0;

        for(int i = 0; i < s.length(); i++) {

            // Case 1: '('
            if(s[i] == '(') {
                minBalance++;
                maxBalance++;
            }

            // Case 2: ')'
            else if(s[i] == ')') {
                minBalance--;
                maxBalance--;
            }

            // Case 3: '*'
            else {
                // '*' can be ')'  -> minimum balance decreases
                minBalance--;

                // '*' can be '('  -> maximum balance increases
                maxBalance++;
            }

            // If even the maximum possible balance is negative,
            // we definitely have too many ')'
            if(maxBalance < 0) {
                return false;
            }

            // Balance cannot actually be negative.
            // So reset minimum to 0.
            if(minBalance < 0) {
                minBalance = 0;
            }
        }

        // If balance can be exactly 0, valid
        return minBalance == 0;
    }
};