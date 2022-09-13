#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

/*
    큐를 두 개로 나누어 저장하되, 현재의 원소 개수를 반으로 나누고,
    앞쪽 큐는 앞의 절반의 가장 큰 값, 뒤쪽 큐는 뒤의 절반의 가장 작은 값을 top으로 가진다.
*/

int n, insertNum;
priority_queue<int> lessPQ; // 가장 큰 값을 top으로 갖는 큐
priority_queue<int, vector<int>, greater<int> > greaterPQ; // 가장 작은 값을 top으로 갖는 큐


int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>insertNum;

        // 전체 원소 개수가 홀수
        if(i % 2 != 0){
            // 뒤의 절반에서 가장 작은 값보다 입력값이 크면 서로의 위치를 바꾼다
            if(!greaterPQ.empty() && greaterPQ.top() < insertNum){
                lessPQ.push(greaterPQ.top());
                greaterPQ.pop();
                greaterPQ.push(insertNum);
            }
            // 뒤의 큐의 모든 원소보다 작으면 앞의 큐에 push
            else{
                lessPQ.push(insertNum);
            }

            cout<<lessPQ.top()<<'\n';
        }
        // 전체 원소 개수가 짝수
        else{
            // 앞의 절반에서 가장 큰 값보다 입력값이 작다면 서로의 위치를 바꾼다
            if(insertNum < lessPQ.top()){
                greaterPQ.push(lessPQ.top());
                lessPQ.pop();
                lessPQ.push(insertNum);
            }
            // 앞의 큐의 모든 원소보다 크다면 뒤의 큐에 push
            else{
                greaterPQ.push(insertNum);
            }

            cout<<lessPQ.top()<<'\n';
        }
    }

    return 0;
}