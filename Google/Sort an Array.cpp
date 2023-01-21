class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
    void mergesort(vector <int> &nums, int low,int high){
        
        if (high>low){
            int mid=low+(high-low)/2; //0 1 3
            mergesort(nums,low,mid);//0 1 
            mergesort(nums,mid+1,high);// 3
            merge(nums,low,mid,high); //0 1 3
        }
    }
    void merge(vector <int> &nums,int low,int mid,int high){
        int n=mid-low+1,m=high-mid; 
        int l[n], r[m];
        for (int i=0;i<n;i++)
            l[i]=nums[low+i];
        for (int i=0;i<m;i++)
            r[i]=nums[mid+1+i];
        
        int j=0,i=0,k=low;
        while (i<n && j<m){
            if (l[i]<=r[j]){
                nums[k++]=l[i++];
            }
            else if (l[i]>r[j]){
                nums[k++]=r[j++];
            }
        }
        for (;i<n;i++){nums[k++]=l[i];}
        for (;j<m;j++){nums[k++]=r[j];}
    }
};
