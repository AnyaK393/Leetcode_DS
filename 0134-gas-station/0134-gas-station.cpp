class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int Totalgas=0;
        int TotalCost=0;

        for(int val: gas){
            Totalgas+=val;
        }
        for(int val: cost){
            TotalCost+=val;
        }
        if(Totalgas< TotalCost){
            return -1;
        }

        //for always unique soln
        int currgas=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            currgas+= gas[i]-cost[i];

            if(currgas<0){
                start=i+1;
                currgas=0;
            }

        }
        return start;
    }
};