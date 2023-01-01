//Leetcode 396

class Solution {
public:
    
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN,sum=0,fn=0;
        for (int i=0;i<n;i++){
            fn+=i*nums[i];
            sum+=nums[i];
        }
        ans=max(fn,ans);
        for (int i=1;i<n;i++){
            fn = fn + sum - n* nums[n-i]; 
            ans=max(fn,ans);
        }
        return ans;
    }
};
