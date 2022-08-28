#include <iostream>

using namespace std;

int n, m, k;
int matA[100][100];
int matB[100][100];
int mulMat[100][100];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>matA[i][j];
        }
    }

    cin>>m>>k;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++){
            cin>>matB[i][j];
        }
    }

    // 점화식: mulMat[i][j] += matA[i][l] * matB[l][j]
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            mulMat[i][j] = 0;
            for(int l = 0; l < m; l++){
                mulMat[i][j] += matA[i][l] * matB[l][j];
            }
            cout<<mulMat[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}