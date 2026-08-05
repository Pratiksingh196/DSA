class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<bool> sus(n,false);
        sus[k] = true;
        queue<int> q;
        q.push(k);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int v : adj[node]){
                if(!sus[v]){
                    sus[v] = true;
                    q.push(v);
                }
            }
        }
        vector<int> ans;

        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];
            if(!sus[u] && sus[v]){
             vector<int> ans1;
             for(int i = 0 ; i < n ; i++){
                ans1.push_back(i);
              }
              return ans1;  
                
            }
        }

        for(int i = 0 ; i < n ; i ++){
            if(!sus[i]){
                ans.push_back(i);
            }
        }
        

      return ans;
    }
};