#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int f[41] = {0};
    cin>>n;
    
    f[1] = f[2] = 1;
    for(int i = 3; i <= n; i++){
        f[i] = f[i - 1] + f[i - 2];
    }

    // 코드1은 return 1의 횟수, 즉 1의 개수이므로 f[N]과 같다.
    // 코드2는 f[1]과f[2]를 제외한 수, 즉 N-2와 같다.

    cout<<f[n]<<' '<<n-2;

    return 0;
}