// brute force approach
//check every number with its next number
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(nums[i]==nums[j])
            return true;
    }
}

// unordered set approach only stores unique elemnts 
//loop through array num if seen before return true or add in unordered set s 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> s;

        for(int i=0;i<nums.size();i++)
        {
            int current = nums[i];

            if(s.find(current) != s.end())
            {
                return true;
            }

            s.insert(current);
        }

        return false;
    }
};