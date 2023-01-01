class Solution {
public:
    vector <vector <int>> ans;
    void help(int bound,int target,int end,vector <int> ds){
        if (target==0 && bound==0){
            ans.push_back(ds);
            return;
        }
        if (bound==0 || end==0){
            return;
        }
        for (int i=1;i<=end;i++){
            ds.push_back(i);
            help(bound-1,target-i,i-1,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> ds;
        help(k,n,9,ds);
        return ans;
    }
};
