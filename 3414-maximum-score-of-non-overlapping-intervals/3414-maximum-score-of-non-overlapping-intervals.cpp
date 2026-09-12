class Solution {
public:

    struct Node {
        int l, r, idx;
        long long w;
    };

    struct State {
        long long score = 0;
        vector<int> ids;
    };

    // Returns true if a is better than b
    bool better(State &a, State &b) {

        // First: maximize weight
        if(a.score != b.score)
            return a.score > b.score;

        // If weight is same:
        // choose lexicographically smaller index vector
        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<Node> a(n);

        // Store original index
        for(int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                i,
                intervals[i][2]
            };
        }

        // Sort by starting point
        sort(a.begin(), a.end(), [](Node &x, Node &y) {
            if(x.l != y.l)
                return x.l < y.l;

            if(x.r != y.r)
                return x.r < y.r;

            return x.idx < y.idx;
        });

        // Store all starting points
        vector<int> starts(n);

        for(int i = 0; i < n; i++) {
            starts[i] = a[i].l;
        }

        // next[i] = first interval whose start > a[i].r
        vector<int> nxt(n);

        for(int i = 0; i < n; i++) {

            int j = upper_bound(
                starts.begin(),
                starts.end(),
                a[i].r
            ) - starts.begin();

            nxt[i] = j;
        }

        // dp[i][k]
        // Best answer using intervals from i onwards
        // with at most k intervals
        vector<array<State, 5>> dp(n + 1);

        // Build DP from right to left
        for(int i = n - 1; i >= 0; i--) {

            for(int k = 1; k <= 4; k++) {

                // OPTION 1: Don't take current interval
                State skip = dp[i + 1][k];

                // OPTION 2: Take current interval
                State take = dp[nxt[i]][k - 1];

                take.score += a[i].w;

                // Add original index
                take.ids.push_back(a[i].idx);

                // We need indices in increasing order
                sort(take.ids.begin(), take.ids.end());

                // Choose the better option
                if(better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].ids;
    }
};