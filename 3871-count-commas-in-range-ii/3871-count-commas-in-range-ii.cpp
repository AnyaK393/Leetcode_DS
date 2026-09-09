class Solution {
public:
    long long countCommas(long long n) {

        long long ans = 0;

        // Start from the first number that contains a comma
        long long start = 1000;

        // Numbers starting from 1000 have 1 comma
        long long commas = 1;

        while(start <= n) {

            // This range ends just before the next 1000 times bigger number
            long long end = start * 1000 - 1;

            // If n comes before the normal end of the range,
            // stop the range at n
            end = min(end, n);

            // Number of values in this range
            long long count = end - start + 1;

            // Every number in this range has the same number of commas
            ans += count * commas;

            // Move to the next digit range
            start *= 1000;
            commas++;
        }

        return ans;
    }
};