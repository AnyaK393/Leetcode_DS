class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.find(part)<s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};
// s.find= finds the position of the substring returns start of the substring
//s.erase= needs start and end
//start is position returned using s.find and end is lenght of the part to be removed