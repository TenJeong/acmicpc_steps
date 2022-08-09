#include <iostream>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string query;
    cin>>query;

    int numA = 0, numB = 0;
    // '-'가 나오기 전까지의 모든 수를 더해주고,
    // '-'이후의 수는 모두 빼는 수에 더해준다.
    // 즉, 빼는 수를 극대화 한다.

    bool isMinus = false;
    int temp = 0;
    for(int i = 0; i < query.size(); i++){
        switch(query[i]){
            case '+':
                if(isMinus) numB += temp;
                else numA += temp;
                temp = 0;
                break;
            case '-':
                if(isMinus) numB += temp;
                else numA += temp;
                temp = 0;
                isMinus = true;
                break;
            default:
                temp = temp * 10 + (query[i] - '0');
                break;
        }
    }

    if(temp != 0){
        if(isMinus) numB += temp;
        else numA += temp;
    }

    cout<<numA - numB;

    return 0;
}