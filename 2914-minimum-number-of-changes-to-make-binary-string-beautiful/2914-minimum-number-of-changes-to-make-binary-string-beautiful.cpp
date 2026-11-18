class Solution {
public:
    int minChanges(string s) {
        int n=s.length();

        char ch=s[0];
        int count=0;

        int changes=0;

        for(int i=0;i<n;i++){
            if(s[i]==ch){//if previous matches the curr ch 
                count++;
                continue;
            }
            //if curr ch is not equal to s[i]
            if(count %2==0){ //if previous subtsring is even
                count=1; //start new subsetring
            }
            else{ // if previous sibstring is not not even 
                //change s[i] to make even subtrsing 
                changes++;
                count=0; //
            }
            ch= s[i];
        }
        return changes;
    }
};