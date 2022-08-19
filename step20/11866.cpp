#include <iostream>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin>>n>>k;

    queue<int> myQueue;

    for(int i = 1; i <= n; i++){
        myQueue.push(i);
    }

    cout<<'<';

    while(!myQueue.empty()){
        // k-1번을 빼서 다시 큐에 넣어줌
        int rePush_count = k - 1;
        while(rePush_count--){
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
        // k번째를 빼고 출력함
        cout<<myQueue.front();
        myQueue.pop();

        if(myQueue.empty()){
            cout<<'>';
        }
        else{
            cout<<", ";
        }
    }

    return 0;
}