class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end()); // now sorted 
        vector <int> dp (n,1);
        vector <int> hash(n,0);
        int maxi=dp[0],last=0;
        for (int i=1;i<n;i++){
            hash[i]=i;
            for (int prev=0;prev<i;prev++){
                if (nums[i]%nums[prev]==0 && dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            if (dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
            
        }
        vector <int> ans;
        ans.push_back(nums[last]);
        while (hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
        }
        return ans;
    }
};
