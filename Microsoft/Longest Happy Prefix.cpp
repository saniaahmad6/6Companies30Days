class Solution {
public:
    
    string longestPrefix(string s) {
        // longest prefix which is also a suffix : LPS array
        int len=0,i=1;
        int m=s.size();
        int lps[m];
        lps[0]=0;
        while (i<m){
            if (s[i]==s[len]){
                lps[i]=++len;
                i++;
            }
            else{
                if (len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
        string ans =s.substr(0,len);
        return ans;
    }
};
