class Solution {
public:
    int findIntegers(int n) {
        int cnt =0;
        int N=31;
        vector <int> dp (N+1,0);
        dp[0]=1;
        dp[1]=2;dp[2]=3;
        
        for (int i=3;i<=31;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        int msbpos =log2(n); //msbpos...0
        int prev=0;
        int ans=0;
        while (msbpos>=0){
            if ((n & (1<<msbpos))){ //this bit is 1
                ans+=dp[msbpos];
                if (prev==1) return ans;
                 prev=1;
            }
            else {
                prev =0;
            }
            msbpos--;
        }
        return ans+1;
    }
};
