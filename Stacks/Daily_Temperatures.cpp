#include<iostream>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> answer(temperatures.size(), 0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); i++) {

            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {

                int prevIndex = st.top();
                st.pop();

                answer[prevIndex] = i - prevIndex;
            }

            st.push(i);
        }

        return answer;
    }
};