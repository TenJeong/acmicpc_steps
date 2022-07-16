#include <iostream>

using namespace std;

int fib_count = 0;
int fibonacci_count = 0;

int fib(int n){
    if(n == 1 || n == 2) {
        fib_count++;    // 코드 1 카운트
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n){
    int f[41] = {0};

    f[1] = f[2] = 1;

    for(int i = 3; i <= n; i++){
        fibonacci_count++;  // 코드 2 카운트
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    fib(n);
    fibonacci(n);

    cout<<fib_count<<' '<<fibonacci_count;

    return 0;
}