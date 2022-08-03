#include <iostream>

using namespace std;

string str;
int n;
int counts[200000][26]; // counts[i][c]: i번째까지의 'c' 개수

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>str;
    cin>>n;

    // 첫번째 문자 카운트
    for(int i = 0; i < 26; i++){
        if(i == (int)(str[0] - 'a')) counts[0][i] = 1;
        else counts[0][i] = 0;
    }

    for(int i = 1; i < str.size(); i++){
        for(int j = 0; j < 26; j++){
            if(j == (int)(str[i] - 'a')) counts[i][j] = counts[i-1][j] + 1; // 해당 문자의 개수를 카운트
            else counts[i][j] = counts[i-1][j]; // 다른 문자는 개수 유지
        }
    }

    while(n--){
        char query;
        int start, end;

        cin>>query>>start>>end;

        if(start == 0) cout<<counts[end][(int)(query - 'a')]<<'\n'; // [0, i] 범위는 i값만 출력
        else // start의 개수도 포함해야 하므로 start-1의 값을 뺌 
            cout<<counts[end][(int)(query - 'a')] - counts[start - 1][(int)(query - 'a')]<<'\n';
    }

    return 0;
}