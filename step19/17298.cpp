#include <iostream>
#include <stack>

using namespace std;

int n;
int arr[1000000];
int answer[1000000];
stack<int> myStack;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = n - 1; i >= 0; i--){
        // 해당 수보다 큰 수만 남을 떄까지 pop함
        while(!myStack.empty() && myStack.top() <= arr[i]){
            myStack.pop();
        }
        // 스택이 비었으면 오른쪽에 큰 수가 존재하지 않음
        if(myStack.empty()){
            answer[i] = -1;
            myStack.push(arr[i]);
        }
        // 큰 수만 남았다면 top을 저장하고 현재 수를 push함
        else{
            answer[i] = myStack.top();
            myStack.push(arr[i]);
        }
    }

    for(int i = 0; i < n; i++){
        cout<<answer[i]<<' ';
    }

    return 0;
}