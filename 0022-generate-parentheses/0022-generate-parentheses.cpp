class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate("", n, ans);
        return ans;
    }

    void generate(string current, int n, vector<string>& ans) {
        if ((int)current.length() == 2 * n) {
            if (isValid(current)) ans.push_back(current);
            return;
        }
        generate(current + "(", n, ans);
        generate(current + ")", n, ans);
    }

    bool isValid(string s) {
        int balanced = 0;
        for (char ch : s) {
            if (ch == '(') balanced++;
            else balanced--;
            if (balanced < 0) return false;
        }
        return balanced == 0;
    }
};