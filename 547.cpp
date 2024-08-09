#include <bits/stdc++.h>
using namespace std;
// 547. Number Of Provinces:
class Solution {
public:
    void bfs(vector<vector<int>>& adj, int s, vector<bool>& visited) {
        visited[s] = true;
        queue<int>q;
        q.push(s);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i=0; i<adj.size(); i++) {
                if(adj[node][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    void dfs(vector<vector<int>>& adj, int s, vector<bool>&visited) {
        visited[s] = true;
        for(int i=0; i<adj.size(); i++) {
            if(adj[s][i] == 1 && !visited[i])
                dfs(adj, i, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool>visited(n+1, false);
        for(int i=0; i<n; i++) {
            if(!visited[i]){
                bfs(isConnected, i, visited);   // BFS Approach
                dfs(isConnected, i, visited);   // DFS Approach
                count++;
            }
        }
        return count;
    }
};