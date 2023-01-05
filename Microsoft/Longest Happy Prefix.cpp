class Solution {
public:
    int gcd(int a,int b){
        if (b==0) return a;
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& arr) {
        sort(nums.begin(),nums.end());
        int res=arr[0];
        int size=arr.size();
        if (size==1 && nums.size()==1) {
            int rem= arr[0]%nums[0];
            if (rem==0) return 0;
            else return -1;
        }
        if (size>1){
            for (int i=1 ; i<=size-1;i++){
            res=gcd(res,arr[i]);
            if (res==1) break;
            }
        }
        for (int i=1 ; i<=size-1;i++){
            res=gcd(res,arr[i]);
            if (res==1) break;
        }
        int gcd_=res,del=0;
        
        int n=nums.size();
        cout<<res<<endl;
        if (nums[0]>gcd_) return -1;
        int i=0;
        while(nums[i]<gcd_){
                
                if (gcd_ % nums[i] !=0) {
                    cout<<nums[i]<<" ";
                    del++;
                }
                else if (gcd_%nums[i]==0) break;
                i++;
        }


        return del;
    }
};
