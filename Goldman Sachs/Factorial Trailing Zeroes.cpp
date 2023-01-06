class Solution {
public:
    int trailingZeroes(int n) {
        long long int res=0; unsigned long long int x=5;
        if (n==0) return 0;
        
        while (n){
            res+=n/x;
            n/=x;
        }
        return res;
    }
};
