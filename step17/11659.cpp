#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int arr[100001];
int total = 0;

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        total += arr[i]; // 전체 합 저장
    }

    while(m--){
        int start, end;
        cin>>start>>end;

        // 구간 길이가 전체 길이의 반 이상일 경우
        if(end - start > (n / 2)){
            int front = 0, rear = 0;
            // 구간 앞의 합
            for(int i = 1; i < start; i++){
                front += arr[i];
            }
            // 구간 뒤의 합
            for(int i = end + 1; i <= n; i++){
                rear += arr[i];
            }
            // 구간 앞뒤를 전체에서 뺌
            cout<<total - front - rear<<'\n';
        }
        else{
            int sum = 0;
            // 구간이 짧을 경우 그냥 구함
            for(int i = start; i <= end; i++){
                sum += arr[i];
            }
            cout<<sum<<'\n';
        }
    }
    

    return 0;
}