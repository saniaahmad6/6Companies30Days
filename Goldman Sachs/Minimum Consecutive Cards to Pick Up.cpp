class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set <int> s;
        int ans=INT_MAX;
        int n=cards.size();
        int lastmatch=-1;
        int l=0,r=-1;
        while (r<n){
            r++;
            if (r==n) break;
            if (s.find(cards[r])!=s.end()){
                lastmatch=cards[r];
            }
            while (s.find(lastmatch)!=s.end() ){
                s.erase(cards[l]);
                ans=min(r-l+1,ans);
                lastmatch=cards[r];
                l++;
                // ans=min(r-l+1,ans);
            }
            
            s.insert(cards[r]);
            
            
        }
        if (ans==INT_MAX) return -1;
        return ans;
    }
};
