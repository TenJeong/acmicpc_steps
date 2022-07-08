#include <iostream>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n, m;

    cin>>n>>m;

    long long count_two = 0;
    long long count_five = 0;

    // 2와 5가 곱해지는 개수를 구한다.
    // 이항개수는 (n! / m! * (n - m)!)이다.
    // 따라서 n!에서의 2와 5의 개수를 더하고, m!과 (n - m)!에서의 2와 5의 개수를 뺀다.
    for(long long i = 2; n /i >= 1; i *= 2)
        count_two += (n / i);
    for(long long i = 5; n / i >= 1; i *= 5)
        count_five += (n / i);
    
    for(long long i = 2; m / i >= 1; i *= 2)
        count_two -= (m / i);
    for(long long i = 5; m / i >= 1; i *= 5)
        count_five -= (m / i);

    for(long long i = 2; (n - m) / i >= 1; i *= 2)
        count_two -= ((n-m) / i);
    for(long long i = 5; (n - m) / i >= 1; i *= 5)
        count_five -= ((n-m) / i);
    

    long long answer = count_two < count_five ? count_two : count_five;
    cout<<answer;

    return 0;
}