#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int totalSum=0;
       for(int i=0;i<nums.size();i++){
            totalSum+= nums[i];
       } 

       int leftSum=0;
       for(int i=0;i<nums.size();i++){
        int rightSum= totalSum-leftSum-nums[i];
            if(rightSum==leftSum){
                return i;
            }
            leftSum+=nums[i];
       }
       return -1;
    }
};