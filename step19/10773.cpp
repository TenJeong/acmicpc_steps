#include <iostream>
#include <stack>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;
    cin>>k;

    stack<int> myStack;

    while(k--){
        int query;
        cin>>query;

        if(query == 0) myStack.pop(); // 0 입력시 pop
        else myStack.push(query); // 0 이외의 정수 입력 시 push
    }

    long long answer = 0;

    while(!myStack.empty()){
        answer += myStack.top(); // stack의 가장 위에 것을 더하고 pop 수행
        myStack.pop();
    }

    cout<<answer;

    return 0;
}