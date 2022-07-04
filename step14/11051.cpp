#include <iostream>
#include <cstring>

using namespace std;

long long **arr;
int n,k;

long long pascal(int num_n, int num_k){
    if(arr[num_n][num_k] == 0){
        long long temp = (pascal(num_n - 1, num_k - 1) + pascal(num_n - 1, num_k)) % 10007;
        arr[num_n][num_k] = temp;
        return temp;
    }
    else
        return arr[num_n][num_k];
}

int main(){


    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;

    arr = new long long*[n+1];
    // (0, *)은 계산하지 않음
    for(int i = 1; i <= n; i++){
        arr[i] = new long long[n+1];
        // (i,0) ~ (i, i) 범위 초기화
        memset(arr[i], 0, sizeof(long long) * (i+1));
        arr[i][0] = arr[i][i] = 1;
    }

    cout<<pascal(n, k);


    for(int i = 0; i <= n; i++){
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}