#include <iostream>
#include <queue>

using namespace std;

// 우선순위 큐를 이용해서 최대 heap을 구현한다
// 입력된 수는 큐 내부적으로 정렬이 수행된다
priority_queue<int> pq;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    while(n--){
        int query;
        cin>>query;
        // top 출력 및 pop 수행
        if(query == 0){
            // 큐가 비었으면 '0' 출력
            if(pq.empty()){
                cout<<"0\n";
            }
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        // 입력 값 push 및 자동 정렬
        else{
            pq.push(query);
        }
    }

    return 0;
}