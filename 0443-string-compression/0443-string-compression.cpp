class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();
        int idx=0;

        for(int i=0;i<n;i++){
            char ch= chars[i]; //select first character
            int count =0;
            while(i<n && chars[i]==ch){ //till next character is same as previous
                count++; 
                i++;
            }
            if(count==1){ //only one occurence of character just save the character 
                chars[idx++]= ch; 
            } 
            else{
                chars[idx++]= ch; //store character
                string str= to_string(count); //then the count (string to int)
                for(char dig : str){
                    chars[idx++]=dig; //store the digit in the next position
                }
            }
                
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};