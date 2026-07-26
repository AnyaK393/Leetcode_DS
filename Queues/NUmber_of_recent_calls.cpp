#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t); // Add the current ping.

        while(q.front()<t-3000){ 
            q.pop(); // Remove pings that are older than the last 3000 ms.
        }
        return q.size();// Remaining pings are within [t - 3000, t].
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */