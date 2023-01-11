class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int n=arr.size();
        if (n<=2) return false;
        int mmin=INT_MAX,smin=INT_MAX;
        for (int i=0;i<=n-1;i++){
            if (arr[i]<=mmin) {
                mmin =arr[i];
            }
            else if (arr[i]<=smin){
                smin =arr[i];
            }
            else return true;
        }
        return false;
    }
};
