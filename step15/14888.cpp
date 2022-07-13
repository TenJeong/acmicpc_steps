#include <iostream>

using namespace std;

int n;
int arr[11] = {0};
int op[4] = {0};

long long total_min = 1000000001;
long long total_max = -1000000001;

void calc(long long result, int count){
    if(count == n - 1){ // n-1���� ����� �������� �ּ� �� �ִ밪 ����
        if(result < total_min) total_min = result;
        if (result > total_max) total_max = result;
        return;
    }

    for(int i = 0; i < 4; i++){ // + - * / ���� ������ �ľ�
        if(op[i] != 0){ // �����ڸ� ���� �� �� �ִٸ�
            op[i]--;    // ������ ���� ����
            long long cur_result;
            switch(i){  // �����ڿ� �°� ���
                case 0:
                    cur_result = result + arr[count+1]; // +
                    calc(cur_result, count+1);  // ���� ���
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
            op[i]++; // ������ ���� ����
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