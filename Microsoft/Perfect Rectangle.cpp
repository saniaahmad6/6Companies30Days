class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<long long, int> m;
        const long long n=1000000;
        for(vector<int>& x:rectangles){
            int x1=x[0];
            int y1=x[1];
            int x2=x[2];
            int y2=x[3];
            m[x1*n+y1]++;
            m[x1*n+y2]--;
            m[x2*n+y1]--;
            m[x2*n+y2]++;
        }
        int n_mark=0;
        for(auto ptr=m.begin();ptr!=m.end();ptr++)
            if(ptr->second!=0){
                if(abs(ptr->second)!=1) return false;
                n_mark++;
            }
        return n_mark==4;
    }
};
