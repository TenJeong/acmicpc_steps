#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<vector<int> > graph;
bool visited[101];
int counts = 0;

void dfs(int v){
    // v를 방문 표시
    visited[v] = true;

    // dfs 수행
    for(int i = 0; i < graph[v].size(); i++){
        if(!visited[graph[v][i]]){
            // 방문할 수 있는 vertex 개수 count
            counts++;
            dfs(graph[v][i]);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    graph.resize(n + 1);
    memset(visited, false, sizeof(bool) * (n + 1));

    while(m--){
        int u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout<<counts;

    return 0;
}