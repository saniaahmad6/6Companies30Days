class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> adj[numCourses];
        for (auto pair:prerequisites){
            adj[pair[1]].push_back(pair[0]);
        }

        queue <int> q;
        vector <int> indeg(numCourses,0);
        for (int i=0;i<numCourses;i++){
            for (auto u :adj[i]){
                indeg[u]++;
            }
        }
        for (int i =0 ;i<numCourses;i++){
            if (indeg[i]==0) q.push(i);
        }
        int n=numCourses;int cnt=0;
        while (!q.empty()){
            auto curr=q.front();q.pop();cnt++;
            for (auto u :adj[curr]){
                indeg[u]--;
                if (indeg[u]==0) q.push(u);
            }
        }
        if (cnt==numCourses) return true;
        else return false;
    }
};
