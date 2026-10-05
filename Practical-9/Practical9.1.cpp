#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void DFS(int start,vector<vector<int>>& graph,int n){
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);

    while(!s.empty()) {
        int node=s.top();
        s.pop();

        if (!visited[node]){
            visited[node]=true;
            cout<<node<<" ";

            for(int i=n-1;i>=0;i--){
                if(graph[node][i]&&!visited[i]){
                    s.push(i);
                }
            }
        }
    }
}

void BFS(int start, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for (int i=0;i<n;i++) {
            if (graph[node][i]&&!visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    int start;
    cin>>start;

    cout<<"DFS: ";
    DFS(start, graph, n);

    cout<<"\nBFS: ";
    BFS(start, graph, n);

    return 0;
}
