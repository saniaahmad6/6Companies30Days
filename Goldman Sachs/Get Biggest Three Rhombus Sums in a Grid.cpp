class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int>s;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int count = 1;
                bool fl = true;
                s.insert(grid[i][j]);
                while(1){
                    int r,c, cnt = count;
                    int sum = 0;
                    r = i+1, c = j-1;
                    while(fl&&cnt--){
                        if(r>=m||c<0){
                            fl = false;
                            break;
                        }
                        sum+=grid[r][c];
                        r++;
                        c--;
                    }
                    cnt = count;
                    r = i + count + 1;
                    c = j-count + 1;
                    while(fl&&cnt--){
                        if(r>=m||c>=n){
                            fl = false;
                            break;
                        }
                        sum+=grid[r][c];
                        r++;
                        c++;
                    }
                    cnt = count;
                    r = i + 2*count - 1;
                    c = j + 1;
                    while(fl&&cnt--){
                        if(r<0||c>=n){
                            fl = false;
                            break;
                        }
                        sum+=grid[r][c];
                        r--;
                        c++;
                    }
                    cnt = count;
                    r = i + count - 1;
                    c = j + count - 1;
                    while(fl&&cnt--){
                        if(r<0||c<0){
                            fl = false;
                            break;
                        }
                        sum+=grid[r][c];
                        r--;
                        c--;
                    }
                    if(fl){
                        s.insert(sum);
                    }
                    else break;
                    count++;
                }
            }
        }
        vector<int>ans;
        int count = 3;
        auto it = s.rbegin();
        while(it!=s.rend()&&count--){
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};
