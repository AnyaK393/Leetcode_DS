#include <vector>
#include <algorithm>

bool isBadVersion(int version)
{
    // dummy implementation
    return version >= 4;
}

using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {

        int left = 1;
        int right = n;

        while(left < right)
        {
            int mid = left + (right - left) / 2;

            if(isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};