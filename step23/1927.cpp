#include <iostream>
#include <queue>

using namespace std;

int n, query;
// 내림차순 큐
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    while(n--){
        cin>>query;

        // 0이 입력됨
        if(query == 0){
            // 큐가 비었으면 0 출력
            if(pq.empty()){
                cout<<"0\n";
            }
            // 큐의 top을 출력하고 pop
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        // 입력된 수를 push
        else{
            pq.push(query);
        }
    }

    return 0;
}