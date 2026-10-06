class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int n=s.length();
        int ans=0;  // Number of unmatched ')' brackets
        for(int i=0;i<n;i++){
            if(s[i]=='('){   // Case 1: opening bracket
                st.push(s[i]);
            }
            else if(!st.empty() && st.top() == '('){  // Case 2: closing bracket
                st.pop();
            }
            else{ // No '(' available to match ')' // So we need to ADD one '('
                ans++;
            }
        }
        ans+= st.size();
        return ans;
    }
};