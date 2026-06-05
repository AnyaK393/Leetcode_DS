#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
        {
            return false;
        }

        unordered_map<char,int> freq;
        unordered_map<char,int> window;

        for(char ch : s1)
        {
            freq[ch]++;
        }

        int k = s1.size();

        for(int i = 0; i < k; i++)
        {
            window[s2[i]]++;
        }

        if(freq == window)
        {
            return true;
        }

        for(int i = k; i < s2.size(); i++)
        {
            window[s2[i-k]]--;

            if(window[s2[i-k]] == 0)
            {
                window.erase(s2[i-k]);
            }

            window[s2[i]]++;

            if(freq == window)
            {
                return true;
            }
        }

        return false;
    }
};