class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        vector<vector<int>> mapStore(26);
        for(int i=0; i<n; i++) {
            mapStore[s[i]-'a'].push_back(i);
        }
        
        int cnt = 0;
        for(int k=0; k<words.size(); k++) {
            string t = words[k];
            int m = t.length();
            int x = -1;
            bool flag = true;
            
            for(auto c: t) {
                auto it = upper_bound(mapStore[c-'a'].begin(), mapStore[c-'a'].end(), x);
                if(it == mapStore[c-'a'].end())
                    flag = false;
                else
                    x = *it;
                
                if(flag == false)
                    break;
            }
            if(flag)
                cnt++;
        }
        return cnt;
    }
};
