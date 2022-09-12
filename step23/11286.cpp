#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// 비교 연산을 위한 compare 구조체
// 절대값의 오름차순을 유지하도록 한다
struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, query;
    // 큐에 입력되는 원소들은 절대값의 오름차순으로 배열된다
    priority_queue<int, vector<int>, cmp> pq;

    cin>>n;

    while(n--){
        cin>>query;

        // 0이 입력될 경우
        if(query == 0){
            // 큐가 비었다면 0을 출력한다
            if(pq.empty()){
                cout<<"0\n";
            }
            // 큐에 원소가 있다면 top을 출력하고 pop을 한다
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        // 0이 아닐 경우 해당 수를 push한다
        else{
            pq.push(query);
        }
    }

    return 0;
}