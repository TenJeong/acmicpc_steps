#include <iostream>
#include <stack>

using namespace std;

int seq[100001];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, pushCount = 0;
    int numOfSeq = 1;
    stack<int> myStack;
    string answer = "";

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>seq[i];
    }

    while(true){
        // 순열대로 모두 출력이 됐다면 종료
        if(numOfSeq > n) break;

        // 순열내의 현재 값보다 지금 push할 값이 작을 경우 push 수행
        if(pushCount < seq[numOfSeq]){
            myStack.push(++pushCount);
            answer += "+\n";
        }
        // 순열값과 스택의 top의 값이 같으면 출력, 다음 순열 값을 가리킨다
        else if(myStack.top() == seq[numOfSeq]){
            numOfSeq++;
            myStack.pop();
            answer += "-\n";
        }
        // 위 경우에 해당하지 않을 경우 순열대로 출력이 불가하다
        else{
            answer = "NO";
            break;
        }
    }

    cout<<answer;

    return 0;
}