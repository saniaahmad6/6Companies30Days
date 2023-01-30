class Solution {
public:
    #define M 1000000007
    #define ll long long
    
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> prev_smallest(n); //prev. smallest ele idx for ith ele of nums
        vector<int> next_smallest(n); //next smallest ele idx for ith ele of nums
        vector<ll> prefix(n); // prefix sum to get the sum from any ith to jth idx
        prefix[0]=nums[0];
        
        //calculate prefixSum
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+ nums[i];
        }
        
        stack<pair<int,int>> st1, st2; // st1->next smallest | st2->prev_smallest
        st1.push({-1,n}); 
        st2.push({-1,-1});
        
        //find next_smallest's element index for every ele of nums
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && st1.top().first>=nums[i]){
                st1.pop();
            }
            
            next_smallest[i]=st1.top().second;
            st1.push({nums[i],i});
        }
        
        //find prev_smallest's element index for every ele of nums
        for(int i=0;i<n;i++){
            while(!st2.empty() && st2.top().first>=nums[i]){
                st2.pop();
            }
            
            prev_smallest[i]=st2.top().second; //index
            st2.push({nums[i],i});
        }
        
        ll ans=INT_MIN; 
        
        //calculate max min-product
        for(int i=0;i<n;i++){
        // as we have stored the index -1 ->if no prev smallest,
        // and index n ->if no next smallest.    
            
            int left=prev_smallest[i]+1; //left index of subarray 
            int right=next_smallest[i]-1; //right index of subarray 
            
            //find subarray sum using prefix sum
            ll subArraySum= left==0 ? prefix[right] : (prefix[right]-prefix[left-1]);
            
            //take the max min-product everytime
            ans=max(ans, nums[i]*subArraySum);
        }
        
        return ans%M;
    }
};
