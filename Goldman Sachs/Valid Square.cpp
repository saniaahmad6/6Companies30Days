class Solution {
public:
    double dis(int x1,int x2,int y1,int y2){
        return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector <vector <int>> p={p1,p2,p3,p4};
        set <double> s;
       for (int i =0;i<4;i++){
           for (int j=i+1;j<4;j++){
               double currdis=dis(p[i][0],p[j][0],p[i][1],p[j][1]);
               if (currdis!=0){
                   s.insert(currdis);
               }
               else return false;
           }

       }
       return  (s.size()==2);
    }
};
