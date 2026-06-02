//Brute force approach 
/*#include <vector>
#include <algorithm>

using namespace std;

for(int i=0;i<n;i++)
{
    int sum = 0;

    for(int j=i;j<n;j++)
    {
        sum += nums[j];
        maxSum = max(maxSum,sum);
    }
}*/

// 
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = 0;
        int maxSum = nums[0];

        for(int i=0;i<nums.size();i++)
        {
            // add current element
            currentSum+=nums[i];
            // update maxSum
            maxSum = max(maxSum, currentSum);
            // reset if currentSum becomes negative
            if(currentSum<0){
                currentSum=0;
            }
        }

        return maxSum;
    }
};