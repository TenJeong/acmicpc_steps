#include <iostream>

using namespace std;

int n;
int arr[11] = {0};
int op[4] = {0};

long long total_min = 1000000001;
long long total_max = -1000000001;

void calc(long long result, int count){
    if(count == n - 1){ // n-1개의 계산을 끝냈으면 최소 및 최대값 갱신
        if(result < total_min) total_min = result;
        if (result > total_max) total_max = result;
        return;
    }

    for(int i = 0; i < 4; i++){ // + - * / 순의 연산자 파악
        if(op[i] != 0){ // 연산자를 선택 할 수 있다면
            op[i]--;    // 연산자 개수 감소
            long long cur_result;
            switch(i){  // 연산자에 맞게 계산
                case 0:
                    cur_result = result + arr[count+1]; // +
                    calc(cur_result, count+1);  // 다음 계산
                    break;
                case 1:
                    cur_result = result - arr[count+1]; // -
                    calc(cur_result, count+1);
                    break;
                case 2:
                    cur_result = result * arr[count+1]; // *
                    calc(cur_result, count+1);
                    break;
                case 3:
                    cur_result = result / arr[count+1]; // /
                    calc(cur_result, count+1);
                    break;
                default:
                    fprintf(stderr,"error!\n");
                    return;
            }
            op[i]++; // 연산자 개수 복구
        }
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < 4; i++){
        cin>>op[i];
    }

    calc(arr[0], 0);

    cout<<total_max<<'\n'<<total_min;

    return 0;
}