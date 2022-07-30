#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str1, str2;
    cin>>str1>>str2;

    int str1_len = str1.size();
    int str2_len = str2.size();

    // 0번째 좌표들은 모두 0으로 채움
    for(int i = 0; i <= str1_len; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= str2_len; i++){
        dp[i][0] = 0;
        for(int j = 1; j <= str1_len; j++){
            // 각 자리 문자가 같은 경우, 해당 문자를 뺀 두 문자열의 LCS + 1과 같다.
            if(str1[j-1] == str2[i-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            // 각 자리 문자가 다른 경우, 두 문자열 중에서 하나만 추가했을 때의 LCS와 같다.
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<dp[str2_len][str1_len];


    return 0;
}