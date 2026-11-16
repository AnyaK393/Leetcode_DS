class Solution {
public:
    string digitSum(string s, int k) {
        // Step 1: Repeat the process until the string length is k or smaller.
        // Once s.length() <= k, no further grouping is needed.
        while (s.length() > k) {
            
            // Create an empty string to store the results of the current round.
            string next_s = "";
            
            // Step 2: Loop through the string, jumping 'k' steps at a time.
            // 'i' marks the starting index of each new group of size k.
            for (int i = 0; i < s.length(); i += k) {
                
                // Variable to hold the sum of digits for the current group.
                int sum = 0;
                
                // Step 3: Iterate through the characters inside the current group.
                // 'j < i + k' ensures we only take up to k characters.
                // 'j < s.length()' prevents going out of bounds if the last group has fewer than k characters.
                for (int j = i; j < i + k && j < s.length(); ++j) {
                    
                    // Convert the character (e.g., '3') into its actual integer value (3)
                    // by subtracting the ASCII value of '0', then add it to sum.
                    sum += s[j] - '0';
                }
                
                // Step 4: Convert the calculated integer sum back into a string
                // and append it to build the string for the next round.
                next_s += to_string(sum);
            }
            
            // Step 5: Replace the old string 's' with the newly formed string 'next_s'
            // before starting the next iteration of the while loop.
            s = next_s;
        }
        
        // Step 6: Return the final string once its length is <= k.
        return s;
    }
};
