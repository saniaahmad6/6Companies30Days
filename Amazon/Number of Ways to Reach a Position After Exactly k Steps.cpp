class Solution {
public:
    int ans=0;
    int mod=(int)1e9+7;
    int solve(int x,int d,int k,vector <vector <int>> &dp){
        if (k<0) return 0;
        if (x==d && k==0){
            return 1;
        }
        if (dp[x+2000][k]!=-1) return dp[x+2000][k];
        int w1=solve(x+1,d,k-1,dp);
        int w2=solve(x-1,d,k-1,dp);
        return dp[x+2000][k]=(w1%mod+w2%mod)%mod;
    }
    int numberOfWays(int sp, int ep, int k) {
        vector <vector <int>> dp(4001,vector <int> (2001,-1)); 
        return solve(sp,ep,k,dp);
        
    }
};
