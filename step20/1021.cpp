#include <iostream>
#include <deque>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    deque<int> myDeque;
    int target[50];
    int totalCount = 0;

    for(int i = 1; i <= n; i++){
        myDeque.push_back(i);
    }

    for(int i = 0; i < m; i++){
        cin>>target[i];
    }

    for(int i = 0; i < m; i++){
        int CCWCount = 0; // 시계반대방향 회전 시 횟수
        int CWCount = 0; // 시계방향 회전 시 횟수

        // 한쪽 방향으로 회전시켜서 회전 횟수를 구함
        while(myDeque.front() != target[i]){
            CCWCount++;
            myDeque.push_back(myDeque.front());
            myDeque.pop_front();
        }

        // 반대방향 회전시의 횟수는 (큐 안의 원소 개수 - 한쪽 방향 회전 횟수)이다. 
        CWCount = (int)myDeque.size() - CCWCount;

        // 더 적은 횟수를 더한다.
        totalCount += CCWCount < CWCount ? CCWCount : CWCount;
        
        // 찾은 수를 pop한다.
        myDeque.pop_front();
    }

    cout<<totalCount;

    return 0;
}