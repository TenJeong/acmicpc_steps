#include <iostream>

using namespace std;

int n;
long long b;

long long originalMat[5][5]; // 초기 배열
long long matA[5][5]; // 행렬곱의 결과가 저장됨

void matMul(long long matX[5][5], long long matY[5][5]){
    long long matMulResult[5][5];

    // matX와 matY의 곱을 구해서 matMulResult라는 행렬에 저장
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matMulResult[i][j] = 0;
            for(int k = 0; k < n; k++){
                matMulResult[i][j] += matX[i][k] % 1000 * matY[k][j] % 1000;
                matMulResult[i][j] %= 1000;
            }
        }
    }

    // 행렬곱의 결과를 matX로 옮김
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matX[i][j] = matMulResult[i][j];
        }
    }
}

void dnc(long long counts){

    // count가 1이면 matA에 초기 행렬값을 넣고 종료
    if(counts == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matA[i][j] = originalMat[i][j];
            }
        }
        return ;
    }

    // 행렬의 (counts/2) 제곱을 구함 -> matA에 저장
    dnc(counts / 2);

    // counts가 홀수 -> mat^(counts/2) * mat^(counts/2) * mat
    if(counts % 2 == 1){

        matMul(matA, matA);
        matMul(matA, originalMat);
    }
    // counts가 짝수 -> mat^(counts/2) * mat^(counts/2)
    else{
        matMul(matA, matA);
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>b;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>originalMat[i][j];
        }
    }

    dnc(b);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // b가 1일 경우를 대비
            cout<<matA[i][j] % 1000<<' ';
        }
        cout<<'\n';
    }

    return 0;
}