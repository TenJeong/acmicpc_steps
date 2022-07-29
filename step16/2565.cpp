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


    // A�� ������� ����
    sort(links, links+n, compare);

    int max_link = 1;
    // A�� ����� B�� ������ ������� �����ؾ� ���� ��ġ�� �ʴ´�.
    // ���� B�� ���� �� �����ϴ� ������ ���ϸ� �ȴ�. 
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            // ���� Ƚ�� ī��Ʈ
            if(links[j].b < links[i].b){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(max_link < dp[i]) max_link = dp[i];
    }

    // ������ Ƚ���� �������Ƿ� �����ؾ��� ������ ���� N���� ���Ͱ� ����.
    cout<<n - max_link;

    return 0;
}