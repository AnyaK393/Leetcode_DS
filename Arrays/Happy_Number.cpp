#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getNext(int n){
        int sum=0;

        while(n>0){
            int digit= n%10;
            sum+= digit* digit;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        
        while(true){
            if(n==1)
                return true;
            if(st.find(n)!=st.end())
                return false;

            st.insert(n);
            n=getNext(n);
        }
    }
};