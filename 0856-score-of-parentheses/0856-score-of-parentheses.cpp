class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();

        stack<int> st;
        int score = 0;

        for(int i = 0; i < n; i++) {

            // If we see '('
            if(s[i] == '(') {

                // Save the score before entering
                // this new parenthesis group
                st.push(score);

                // Start calculating the score
                // inside this new group
                score = 0;
            }

            else {  // s[i] == ')'

                // Case 1: "()"
                // An empty pair has score 1
                if(s[i-1] == '(') {

                    score = st.top() + 1;
                }

                // Case 2: "(A)"
                // Score becomes 2 * score of A
                else {

                    score = st.top() + 2 * score;
                }

                // Remove the previous saved score
                st.pop();
            }
        }

        return score;
    }
};

//apprach 2;
/*class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int depth=0;
        int score=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
            }
            else{ //s[i]==')'
                depth--;

                if(s[i-1]=='('){ //'()'
                    score+= 1<<depth;
                }
            }
        }
        return sscore;
    }
};*/