#include <iostream>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string query;
    cin>>query;

    int answer = 0;
    // '-'가 나오기 전까지의 모든 수를 더해주고,
    // '-'이후의 수는 모두 빼는 수에 더해준다.
    // 즉, 빼는 수를 극대화 한다.

    bool isMinus = false;
    int temp = 0;
    for(int i = 0; i <= query.size(); i++){
        // 문자열의 끝이거나 연산자가 나오면 저장한 수를 계산한다.
        if(query[i] == '-' || query[i] == '+' || i == query.size()){
            if(isMinus) answer -= temp;
            else answer += temp;
            temp = 0;
        }
        // 숫자가 오면 수를 계산해서 저장한다.
        else{
            temp = temp * 10 + (query[i] - '0');
        }
        // '-'가 나온 이후의 수는 모두 뺄셈을 한다.
        if(query[i] == '-') isMinus = true;
    }

    cout<<answer;

    return 0;
}