#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of each task
        unordered_map<char, int> freq;

        for(char task : tasks) {
            freq[task]++;
        }

        // Step 2: Max Heap storing frequencies
        priority_queue<int> pq;

        for(auto it : freq) {
            pq.push(it.second);
        }

        int time = 0;

        // Step 3: Process tasks
        while(!pq.empty()) {

            vector<int> temp;

            // One cycle has n + 1 positions
            for(int i = 0; i <= n; i++) {

                if(!pq.empty()) {

                    int f = pq.top();
                    pq.pop();

                    f--;

                    if(f > 0) {
                        temp.push_back(f);
                    }
                }

                time++;

                // If no tasks remain anywhere, stop
                if(pq.empty() && temp.empty()) {
                    break;
                }
            }

            // Put remaining tasks back into heap
            for(int f : temp) {
                pq.push(f);
            }
        }

        return time;
    }
};