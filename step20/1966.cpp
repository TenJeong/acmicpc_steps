#include <iostream>
#include <queue>

using namespace std;

typedef struct docprint{
    int orderNum; // 초기 상태에서의 순서
    int priority; // 중요도
} docPrint;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        int priorCount[10]; // 중요도별 남은 문서 개수
        int popCount = 1; // pop 수행 횟수
        for(int i = 0; i < 10; i++) priorCount[i] = 0;

        queue<docPrint> myQueue;

        for(int i = 0; i < n; i++){
            int pri;
            cin>>pri;

            priorCount[pri]++;
            docPrint doc;
            doc.orderNum = i; doc.priority = pri;
            myQueue.push(doc); // {초기 상태에서의 순서, 중요도}
        }

        while(!myQueue.empty()){
            bool isPopable = true;
            // 중요도가가 높은 것이 남았는지 확인
            for(int i = 9; i > myQueue.front().priority; i--){
                if(priorCount[i] != 0){
                    isPopable = false;
                    break;
                }
            }
            // 중요도가 높은 것이 없다면 pop
            if(isPopable){
                priorCount[myQueue.front().priority]--;
                // 찾던 번호를 pop 했다면 pop 순서를 출력하고 더 이상 진행하지 않음
                if(myQueue.front().orderNum == m){
                    cout<<popCount<<'\n';
                    break;
                }
                myQueue.pop();
                popCount++;
            }
            // 중요도가 더 높은 것이 있다면 큐의 뒤에 다시 넣어줌
            else{
                myQueue.push(myQueue.front());
                myQueue.pop();
            }
        }
    }

    return 0;
}