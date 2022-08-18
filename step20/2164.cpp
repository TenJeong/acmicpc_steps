#include <iostream>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    queue<int> myQueue;
    int n;

    cin>>n;

    for(int i = 1; i <= n; i++){
        myQueue.push(i);
    }

    while(true){
        // 큐의 원소 개수 확인
        if(myQueue.size() == 1) break;

        // 맨 위에 것을 pop
        myQueue.pop();

        // 큐의 원소 개수 확인
        if(myQueue.size() == 1) break;

        // 맨 위 원소를 push해주고 pop 수행
        myQueue.push(myQueue.front());
        myQueue.pop();
    }

    cout<<myQueue.front();

    return 0;
}