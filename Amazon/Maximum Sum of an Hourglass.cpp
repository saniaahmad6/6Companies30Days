class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int maxi=INT_MIN;
        int m=grid.size();
        int n=grid[0].size();
        for (int i=0;i<m-2;i++){
            for (int j=0;j<n-2;j++){
                //at i,j
                int curr=0;
                for (int c=j;c<j+3;c++){
                    curr+=grid[i][c];
                    curr+=grid[i+2][c];
                }
                curr+=grid[i+1][j+1];
                maxi=max(curr,maxi);
            }
        }
        return maxi;
    }
};
