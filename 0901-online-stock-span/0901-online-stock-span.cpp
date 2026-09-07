class StockSpanner {
public:
    vector<int> price;   // Store all stock prices
    stack<int> s;        // Stack stores indices

    StockSpanner() {
    }

    int next(int p) {

        // Add current price
        price.push_back(p);

        // Current index
        int i = price.size() - 1;

        // Remove all previous prices that are
        // smaller than or equal to current price
        while(s.size() > 0 && price[s.top()] <= price[i]) {
            s.pop();
        }

        int ans;

        // If stack is empty, current price is greater
        // than all previous prices
        if(s.empty()) {
            ans = i + 1;
        }
        else {
            // s.top() is the nearest previous
            // greater price
            ans = i - s.top();
        }

        // IMPORTANT:
        // Push current index AFTER calculating answer
        // but BEFORE returning
        s.push(i);

        return ans;
    }
};