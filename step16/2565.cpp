#include <iostream>
#include <algorithm>

using namespace std;

struct link {
    int a;
    int b;
};

struct link links[100];
int dp[100];

int compare(struct link a, struct link b){
    return a.a < b.a;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
       cin>>links[i].a>>links[i].b;
    }


    // A의 순서대로 정렬
    sort(links, links+n, compare);

    int max_link = 1;
    // A와 연결된 B의 값들이 순서대로 증가해야 서로 겹치지 않는다.
    // 따라서 B가 가장 긴 증가하는 순열을 구하면 된다. 
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            // 증가 횟수 카운트
            if(links[j].b < links[i].b){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(max_link < dp[i]) max_link = dp[i];
    }

    // 전깃줄 횟수를 구했으므로 제거해야할 전깃줄 수는 N에서 뺀것과 같다.
    cout<<n - max_link;

    return 0;
}