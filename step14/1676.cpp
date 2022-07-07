#include <iostream>
#include <cmath>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;

    cin>>n;

    int count = 0;
    for(int i = 1; ; i++){

        if(pow(5, i) > n) break;

        // 5의 배수가 있으면 count + 1, 5의 제곱수의 배수가 있다면 다시 한번 count + 1 
        for(int j = 1; j * pow(5, i) <= n; j++){
            count += 1;
        }
    }

    cout<<count;

    return 0;
}