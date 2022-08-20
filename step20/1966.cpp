#include <iostream>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        int popCount = 1; // pop 순서 count

        queue< pair<int, int> > docQueue; // 초기상태대로의 큐, 순서 및 중요도 
        priority_queue<int> priQueue; // 정렬된 중요도

        for(int i = 0; i < n; i++){
            int pri;
            cin>>pri;

            docQueue.push(make_pair(i, pri));
            priQueue.push(pri);
        }

        while(!docQueue.empty()){
            // 출력을 시도하는 문서의 우선순위와 현재 가장 큰 우선 순위를 비교함
            // 더 큰 우선순위가 있을 경우 큐에 다시 넣음
            if(docQueue.front().second < priQueue.top()){
                docQueue.push(docQueue.front());
                docQueue.pop();
            }
            // 더 큰 우선순위가 없다면 pop
            else{
                if(docQueue.front().first == m){
                    cout<<popCount<<'\n';
                    break;
                }
                popCount++;
                docQueue.pop();
                priQueue.pop();
            }
        }
    }

    return 0;
}