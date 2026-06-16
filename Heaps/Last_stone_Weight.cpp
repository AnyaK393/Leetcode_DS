#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq; //max heap 8 first 2nd 7 

        for(int stone : stones){
            pq.push(stone);
        }

        while(pq.size() > 1){

            int num1 = pq.top();
            pq.pop();

            int num2 = pq.top();
            pq.pop();

            if(num1 != num2){
                pq.push(num1 - num2);
            }
        }

        if(pq.empty()){
            return 0;
        }

        return pq.top();
    }
};