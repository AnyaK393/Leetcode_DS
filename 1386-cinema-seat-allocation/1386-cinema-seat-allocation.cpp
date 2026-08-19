class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        for(auto seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Only seats 2 to 9 matter
            if(col >= 2 && col <= 9) {
                mp[row] |= (1 << col);
            }
        }

        // Initially every row can fit 2 families
        int answer = 2 * (n - mp.size());

        for(auto it : mp) {

            int mask = it.second;

            bool left  = !(mask & (1 << 2)) &&
                         !(mask & (1 << 3)) &&
                         !(mask & (1 << 4)) &&
                         !(mask & (1 << 5));

            bool right = !(mask & (1 << 6)) &&
                         !(mask & (1 << 7)) &&
                         !(mask & (1 << 8)) &&
                         !(mask & (1 << 9));

            bool middle = !(mask & (1 << 4)) &&
                          !(mask & (1 << 5)) &&
                          !(mask & (1 << 6)) &&
                          !(mask & (1 << 7));

            if(left && right)
                answer += 2;
            else if(left || right || middle)
                answer += 1;
        }

        return answer;
    }
};