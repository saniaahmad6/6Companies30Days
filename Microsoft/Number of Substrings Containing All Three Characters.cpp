class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0,end=s.size()-1;
        unordered_map <char,int> m;
        int ans=0;
        while (right<=end){
            while (!(m['a'] && m['b'] && m['c']) && right<=end){
                m[s[right]]++;
                right++;
            }
            while (m['a'] && m['b'] && m['c']){
                ans+=1 + (end-right+1);
                m[s[left]]--;
                left++;
            }
            

        }
        return ans;
    }
};
