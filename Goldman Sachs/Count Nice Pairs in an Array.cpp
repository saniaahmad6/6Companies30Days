class Solution {
public:
    int rev(int n){//log10n
        int ans=0;
        while (n){
            int dig= n%10;
            ans =ans *10 +dig;
            n/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n= nums.size();
        int mod=(int)1e9+7;
        int cnt=0;
        unordered_map <int,int> m;
        for (int i=0;i<n;i++){
            if (m[nums[i]-rev(nums[i])]) cnt=((cnt)%mod + (m[nums[i]-rev(nums[i])])%mod)%mod;
            m[nums[i]-rev(nums[i])]++;
        }
        return cnt%(mod);
    }
};
