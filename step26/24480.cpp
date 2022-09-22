#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, r;
vector<vector<int> > graph;
int order[100001];
int counts = 0;

void dfs(int v){

    // v의 방문 순서 저장
    order[v] = ++counts;

    // v와 연결된 vertex들의 내림차순 정렬
    sort(graph[v].begin(), graph[v].end(), greater<int>());

    // dfs 수행
    for(int i = 0; i < graph[v].size(); i++){
        if(order[graph[v][i]] == 0){
            dfs(graph[v][i]);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>r;

    // 초기화
    graph.resize(n + 1);
    memset(order, 0, sizeof(order));

    while(m--){
        int u, v;
        cin>>u>>v;

        // 양방향 edge
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(r);

    for(int i = 1; i <= n; i++){
        cout<<order[i]<<'\n';
    }

    return 0;
}