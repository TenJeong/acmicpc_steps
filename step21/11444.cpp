#include <iostream>
#define DIVISOR 1000000007

using namespace std;

/*
    피보나치 수열을 행렬 형태로 표현했을때,
    {Fk+2, Fk+1} = {{1, 1}, {1, 0}} * {Fk+1, Fk}
    와 같은 미분 방적식으로 표현 할 수 있음을 이용한다.
    
    따라서, Fn을 구하기 위해서는 {F1, F0}에 변환 행렬식을 n-1번 곱해주면 된다.
*/

long long n;
long long transMat[2][2] = {{1, 1}, {1, 0}};
long long originMat[2][2] = {{1, 1}, {1, 0}};
long long nums[2] = {1, 0}; // {f1, f0}

// matA * matB를 수행해서 matA에 결과값을 넣는다
void matMul(long long matA[2][2], long long matB[2][2]){
    long long result[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            result[i][j] = 0;
            for(int k = 0; k < 2; k++){
                result[i][j] += matA[i][k] % DIVISOR * matB[k][j] % DIVISOR;
                result[i][j] %= DIVISOR;
            }
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            matA[i][j] = result[i][j];
        }
    }
}

void transition(long long counts){
    
    if(counts <= 1) return;
    
    // 행렬^(counts / 2)을 구한다.
    transition(counts / 2);

    // 행렬^counts = 행렬^2 * 행렬^2 (counts가 짝수)
    //            = 행렬^2 * 행렬^2 * 초기행렬 (counts가 홀수)
    if(counts % 2 == 0){
        matMul(transMat, transMat);
    }
    else{
        matMul(transMat, transMat);
        matMul(transMat, originMat);
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    // 변환 행렬의 (n-1) 제곱 수행
    transition(n - 1);

    if(n != 1){
        // 변환행렬을 곱해줌
        long long tempNums[2] = {0, 0};
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                tempNums[i] += transMat[i][j] % DIVISOR * nums[j] % DIVISOR;
                tempNums[i] %= DIVISOR;
            }
        }
        nums[0] = tempNums[0]; nums[1] = tempNums[1];
    }

    cout<<nums[0];

    return 0;
}