#include <iostream>
#include <stack>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<char> myStack;

    while(true){
        string str;
        // 한 줄을 읽어옴
        getline(cin, str);

        if(str == ".") break;

        bool isBalanced = true;

        for(int i = 0; i < str.size(); i++){
            // 여는 괄호를 만나면 스택에 넣음
            if(str[i] == '(' || str[i] == '[') {
                myStack.push(str[i]);
            }
            else if(str[i] == ')'){
                // 대응되는 여는 괄호가 있으면 스택에서 pop 수행
                // 없다면 unbalance 함.
                if(!myStack.empty() && myStack.top() == '('){
                    myStack.pop();
                }
                else{
                    isBalanced = false;
                    while(!myStack.empty()){
                        myStack.pop();
                    }
                    break;
                }
            }
            else if(str[i] == ']'){
                // 대응되는 여는 괄호가 있으면 스택에서 pop 수행
                // 없다면 unbalance 함
                if(!myStack.empty() && myStack.top() == '['){
                    myStack.pop();
                }
                else{
                    isBalanced = false;
                    while(!myStack.empty()){
                        myStack.pop();
                    }
                }
            }
        }

        // 문자열을 확인 했는데 아직 스택이 남아있다면 unbalance 함
        if(!myStack.empty()){
            isBalanced = false;
            while(!myStack.empty()) myStack.pop();
        }

        if(isBalanced){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }

    return 0;
}