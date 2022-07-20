#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
long long largest[100001]; // largest[i] -> 어떤 수에서 i까지의 합 중에서 가장 큰 것
long long answer = -1001;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    largest[0] = arr[0];
    answer = largest[0];

    for(int i = 1; i < n; i++){
        // largest[i-1] + arr[i]와 arr[i]를 비교한다.
        // arr[i]보다 작다는 것은 앞까지의 합이 음수라서
        // arr[i]에 더했을 때 손실이 발생한다는 뜻이다.
        if(largest[i-1] + arr[i] < arr[i]){ // 손해가 있다면 i부터 다시 추적
            largest[i] = arr[i];
        }
        else{
            largest[i] = largest[i-1] + arr[i];
        }

        if(answer < largest[i]) answer = largest[i];
    }

    cout<<answer;

    return 0;
}