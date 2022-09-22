#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int r;

vector<vector<int> > graph;
int order[100001]; // vertex 방문 순서
int counts = 1;

void dfs(int v){

    // 방문 순서 저장
    order[v] = counts++;

    // 오름차순 정렬
    sort(graph[v].begin(), graph[v].end());

    // 깊이 우선 탐색
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
    for(int i = 0; i <= n; i++){
        order[i] = 0;

        vector<int> v;
        graph.push_back(v);
    }

    // edge 입력
    while(m--){
        int u, v;
        cin>>u>>v;

        // 양방향 edge
        graph[u].push_back(v);   
        graph[v].push_back(u);
    }

    // dfs 수행
    dfs(r);

    // 각 vertex의 방문 순서 출력
    for(int i = 1; i <= n; i++){
        cout<<order[i]<<'\n';
    }

    return 0;
}