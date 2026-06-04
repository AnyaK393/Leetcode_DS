#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string word : strs)
        {
            string key = word;

            sort(key.begin(), key.end());

            mp[key].push_back(word);
        }

        vector<vector<string>> result;

        // loop through map here
        for(auto pair : mp){
            result.push_back(pair.second);
        }

        return result;
    }
};