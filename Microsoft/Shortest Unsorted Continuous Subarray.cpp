class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 0;
        int i=0,j=n-1,start=0,end=0;
        for (int i=0;i<n-1;){
            if (nums[i]<=nums[i+1]) i++;
            else {start=i; break;}
        }
        for (int i=n-2;i>=0;){
            if (nums[i]<=nums[i+1]) i--;
            else {end=i+1; break;}
        }
        if (end==start) return 0;
        int mini=*min_element(nums.begin()+start,nums.begin()+end+1);
        int maxi=*max_element(nums.begin()+start,nums.begin()+end+1);
        while (start-1>=0 && nums[start-1]>mini) start--;
        while (end+1 <=n-1 && nums[end+1]<maxi) end++;
        return end-start+1;
    }
};
