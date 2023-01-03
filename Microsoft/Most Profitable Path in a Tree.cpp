class Solution {
public:
    vector<vector<int>> adj;
    vector<int> par,dis;
    unordered_set <int> visited;
    int ans=0,max_ans=INT_MIN;
    void dfspardis(int s,int p,int distance){
        par[s]=p;
        dis[s]=distance;
        for (auto u : adj[s]){
            if (u!=p){
                dfspardis(u,s,distance+1);
            }
        }
    }
    void dfs (int s,vector<int> &amount){
        ans+=amount[s];
        visited.insert(s);
        int traversed=0;
        for (auto u :adj[s]){
            if (visited.find(u)==visited.end()){
                dfs(u,amount);
                traversed++;

            }
        }
        if (traversed==0) max_ans=max(max_ans,ans);
        ans-=amount[s];

    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        adj.resize(n,vector <int> ());
        for (auto p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        par.resize(n);
        dis.resize(n);
        dfspardis(0,0,0);

        int curr = bob;
        int bobdis=0;
        while (curr!=0){
            if (dis[curr]>bobdis){
                amount[curr]=0;
            }
            else if (dis[curr]==bobdis){
                amount[curr]/=2;
            }
            bobdis++;
            curr=par[curr];
        }
        
        dfs(0,amount);
        return max_ans;
    }
};
