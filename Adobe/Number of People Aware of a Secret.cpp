class Solution {
public:
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
       vector <long long> dp(n,0);
       long long mod=(int)1e9 +7;
       dp[0]=1;
       long long curr = 0;
       for (int i=1;i<n;i++){
           int s =(i>=delay) ? dp[i-delay] : 0;
           int f =(i>=forget) ? dp [i-forget] :0;
            curr = (curr + s -f +mod) %mod;
            dp[i]=curr;
       }
       long long ans=0;
       for (int i=n-forget;i<n;i++){
           ans=(ans +dp[i])%mod;
       }
       return (int)ans;
    }
};
