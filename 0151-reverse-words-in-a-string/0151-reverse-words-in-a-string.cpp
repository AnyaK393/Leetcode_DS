class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        // reverse the entire string (eulb si yks eht)
        reverse(s.begin(), s.end());
        // now lets figure out words 
        for(int i=0;i<n;i++){
            string word="";
            while(i<n && s[i]!= ' '){
                word+=s[i];
                i++;
            }
            //now reverse the words 
            reverse(word.begin(), word.end());
            if(word.length()> 0){
                ans+= " "+word;
            }
        }
        return ans.substr(1);

    }
};