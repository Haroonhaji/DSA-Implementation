#include<bits/stdc++.h>
using namespace std;

vector<int>bfs(int m, vector<int> adj[]){
    vector<int>ans;
    int visited[m]={0};
    queue<int>q;
    q.push(0);
    int a;
    visited[0]=1;
    while(!q.empty()){
        a = q.front();
        q.pop();
        ans.push_back(a);
        for(auto it: adj[a]){
            if( visited[it]==0){
                 q.push(it);
                 visited[it]=1;
            }

        }
    }
    return ans;
}


void fun(vector<int>&visited,int v, vector<int>adj[],vector<int>&ans, int node){
        if(visited[node]==0){
            ans.push_back(node);
            visited[node]=1;
            for(auto it: adj[node]){
                fun(visited,v,adj,ans,it); 
            }
        }
        else return;
}
vector<int>dfs(int v, vector<int>adj[]){
    vector<int>visited(v,0);
    vector<int>ans;
    fun(visited,v,adj,ans,0);
    return ans;
}


int main(){
    int n=5, m =5;
    vector<int> adj[m] ={{1,3}, {2,0}, {1}, {0}};
    vector<int>a = bfs(4,adj);
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
    vector<int>d = dfs(4,adj);
    for(auto it:d) cout<<it<<" ";
    
}