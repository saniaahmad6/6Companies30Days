class Solution {
public:
    vector <int> dx={-1,-1,-2,-2,1,1,2,2};
    vector <int> dy={-2,2,1,-1,2,-2,-1,1};
    bool check (int i,int j,int n){
        return (i>=0 && i<n && j>=0 && j<n);
    }
    double solve (int i,int j,int moves,int n,vector <vector <vector<double>>> &dp){
        if (moves==0){
            return 1;
        }
        if (dp[i][j][moves]!=-1) return dp[i][j][moves];
        double curr= 0;
        for (int c=0;c<8;c++){
            int nx = i + dx[c];
            int ny = j + dy[c];
            if (check(nx,ny,n)){
                curr+= (0.125 * solve(nx,ny,moves-1,n,dp));
            }
            
        }
        return dp[i][j][moves]=curr;

    }
    double knightProbability(int n, int k, int row, int column) {
        vector <vector <vector<double>>> dp(n,vector <vector <double>> (n,vector <double> (k+1,-1)));
        return solve(row,column,k,n,dp);

    }
};
