class Solution {
public:
    int solve (int pattern, int total,vector<vector<int>>& statements,int n){
        int cnt = 0;
        for (int i=0;i<n;i++){
            if ((pattern & (1<<i)) == 0) continue; // already this bit person is bad
            cnt++;
            //validate this pattern
            for (int j= 0;j<n;j++){
                if (i==j) continue;
                if (statements[i][j] ==1 && ((pattern &(1<<j)) ==0)) return -1;
                if (statements[i][j] ==0 && ((pattern &(1<<j)) !=0)) return -1;
            }
            
        }
        return cnt;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int total=(1<<statements.size()); 
        int maxi=0;
        for (int i=0;i<total;i++){ // 0 - n-1 set patterns 
            int correctsetbits=solve(i,total,statements,statements.size());
            maxi=max(correctsetbits,maxi);
        }
        return maxi;
    }
};
