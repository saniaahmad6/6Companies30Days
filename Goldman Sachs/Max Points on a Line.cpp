class Solution {
public:
    double line(double x1,double y1,double x2,double y2){
        double m;
        if ((x2-x1)!=0){
            m = (y2-y1)/ (x2-x1);
        } 
        else {
             m=INT_MAX;
             
        }
        return m;

    }
    int maxPoints(vector<vector<int>>& p) {
        map <double,int> m;
        int n=p.size();int maxi=0;
        if (n==1) return 1;
        
        for (int i =1 ;i<n;i++){
            unordered_map <double,int> m;
            for (int j=0;j<n;j++){
                if (i==j) continue;
                auto currslope= line(p[i][0],p[i][1],p[j][0],p[j][1]);
                m[currslope]++;
            
            }
            for (auto pair: m){
                maxi=max(maxi,pair.second+1);
            }
        }
        return maxi;

    }
};
