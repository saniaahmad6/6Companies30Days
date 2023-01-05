class Solution {
public:
    long long int mod=1e9+7;
    // vector <int> ans;
    // void help(int s,int d,vector <vector <pair<int,int>>> &adj, int cost,vector <int> &stk){
    //     if (s==d){
    //         ans.push_back(cost);
    //     }
    //     stk[s]=1;
    //     for (auto pair : adj[s]){
    //         if (!stk[pair.first]){
    //             cost+=pair.second;
    //             help (pair.first,d,adj,cost,stk);
    //             cost-=pair.second;
    //         }
            
    //     }
    //     stk[s]=0;
    // }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector <vector <pair<long long int,long long int>>> adj (n); 
        for (auto v : roads){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        vector <long long int> distance(n,1e15);
        vector <int> dp (n,0);
        // help (0,n-1,adj,0,stk);
        // int mini = *min_element(ans.begin(),ans.end());
        // int cnt=0;
        // for (auto i : ans) if (i==mini) cnt++;
        // return cnt;
        dp[0]=1;distance[0]=0;
        priority_queue <pair<long long int,long long int>,vector <pair<long long int,long long int>>, greater <pair<long long int,long long int>>> q;
        q.push({0,0});
        while (!q.empty()){
            auto curr = q.top();q.pop();
            long long int node=curr.second; long long int dis=curr.first;
            for (auto p : adj[node]){
                long long int u=p.first; long long int wt=p.second;
                if (dis+wt<distance[u]){
                    distance[u]=dis+wt;
                    q.push({distance[u],u});
                    dp[u]=dp[node]%mod;
                }
                else if(dis+wt==distance[u]){
                    dp[u]=(dp[u]%mod + dp[node]%mod) %mod;
                }
            }
        }
        return (int)dp[n-1];
        
    }
};
