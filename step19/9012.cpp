#include <iostream>
#include <stack>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        string str;
        cin>>str;

        stack<char> check_stack;
        bool isPS = true;

        for(int i = 0; i < str.size(); i++){
            // '('와 ')'의 짝을 맞춘다.
            if(str[i] == '(') check_stack.push(str[i]);
            else if(str[i] == ')'){
                // '('와 ')'의 개수가 맞지 않으면 PS가 아님
                if(check_stack.empty()){
                    isPS = false;
                    break;
                }

                // 짝이 맞다면 '(' 하나를 스택에서 제거함
                check_stack.pop();
            }
        }

        // 문자열 전체를 읽었을 때 아직 스택에 문자가 있다면 짝이 맞지 않은 것이다.
        if(!check_stack.empty()) isPS = false;

        if(isPS) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}