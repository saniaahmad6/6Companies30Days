class Solution {
public:
    double dis(double x1,double y1,double x2, double y2){
        return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    }
    int numberOfBoomerangs(vector<vector<int>>& p) {
        unordered_map <double,int> m;
        int cnt=0,n=p.size();
        if (n<=2) return 0;
        for (int i=0;i<n;i++){
            unordered_map <double,int> m;
            for (int j=0;j<n;j++){
                if (i!=j){
                    double currdis=dis(p[i][0],p[i][1],p[j][0],p[j][1]);
                    m[currdis]++;
                    if (m[currdis]==2) cnt+=2;
                    else if (m[currdis]>2) cnt = cnt+ (m[currdis]-1)*2;

                }
            }
        }
        return cnt;
    }
};
