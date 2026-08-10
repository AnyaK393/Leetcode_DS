class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m= matrix.size(); //rows
        int n= matrix[0].size(); //cols
        int srow=0, erow= m-1;
        int scol= 0, ecol=n-1;
        vector<int> ans;

        while(srow<=erow && scol<=ecol){
            //top
            for(int i= scol;i<=ecol;i++){
                ans.push_back(matrix[srow][i]);
            }
            //right
            for(int j= srow+1;j<=erow;j++){
                ans.push_back(matrix[j][ecol]);
            }
            //bottom
            for(int i= ecol-1;i>=scol;i--){
                if(srow==erow){
                    break;
                }
                ans.push_back(matrix[erow][i]);
            }
            //left
            for(int j=erow-1;j>=srow+1;j--){
                if(scol==ecol){
                    break;
                }
                ans.push_back(matrix[j][scol]);
            }
            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return ans;
    }
};