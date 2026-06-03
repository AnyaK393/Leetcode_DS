#include<iostream>
#include<vector>
#include<string.h>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
             mp[t[i]]--;
        }

        for(auto pair : mp){
            if(pair.second != 0)
                return false;
        }
        //in maps every key value pair is called pair
        //key->first
        //value->second 
        return true;
    }
};