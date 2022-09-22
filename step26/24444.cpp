#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, r;
vector<vector<int> > graph;
queue<int> myQueue;
int order[100001];
int counts = 0;

void bfs(){

    // 첫 시작 지점 count하고 큐에 넣음
    order[r] = ++counts;
    myQueue.push(r);

    while(!myQueue.empty()){
        // 큐에서 pop 수행
        int curVertex = myQueue.front();
        myQueue.pop();

        // 연결된 vertex 오름차순 정렬
        sort(graph[curVertex].begin(), graph[curVertex].end());

        // 해당 vertex와 연결된 vertex 확인
        for(int i = 0; i < graph[curVertex].size(); i++){
            int checkVertex = graph[curVertex][i];
            // 방문하지 않았다면 count하고 큐에 넣음
            if(order[checkVertex] == 0){
                order[checkVertex] = ++counts;
                myQueue.push(checkVertex);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>r;

    graph.resize(n + 1);
    memset(order, 0, sizeof(int) * (n + 1));

    while(m--){
        int u, v;
        cin>>u>>v;

        // 양방향 edge
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();

    for(int i = 1; i <= n; i++){
        cout<<order[i]<<'\n';
    }

    return 0;
}