// brute force approach
// 2 loops n2 complexity take on eleemnt and add it with every elemnt in front of it 

//code 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class solution{
public:
    vector<int> twoSum(vector<int>& nums, int target)
{
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target)
            {
                return {i,j};
            }
        }
    }

    return {};
}
};



// unordered map approach
/* first checks the currents complement if present in the unordered map return the mp[compplement] and i
otherwise store the current and its index in the map */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++)
        {
            int current = nums[i];

            int complement = target - current;

            if(mp.find(complement) != mp.end())
            {
                return {mp[complement], i};
            }

            mp[current] = i;
        }

        return {};
    }
};
