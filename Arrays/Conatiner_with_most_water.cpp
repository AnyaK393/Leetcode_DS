#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right= height.size()-1;
        int maxArea=0;

        while(left<right){
            int width= right-left;
            int currentArea= width *min(height[left], height[right]);

            maxArea= max(currentArea, maxArea);

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return maxArea;
    }
};