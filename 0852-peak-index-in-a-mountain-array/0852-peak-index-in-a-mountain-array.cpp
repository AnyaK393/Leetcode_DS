class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int n = arr.size();

        int start = 1;
        int end = n - 2;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            // mid is the peak
            if(arr[mid-1] < arr[mid] &&
               arr[mid] > arr[mid+1]) {

                return mid;
            }

            // Increasing slope → peak is on the right
            else if(arr[mid-1] < arr[mid]) {
                start = mid + 1;
            }

            // Decreasing slope → peak is on the left
            else {
                end = mid - 1;
            }
        }

        return -1;
    }
};