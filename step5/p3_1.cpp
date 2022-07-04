#include <iostream>

using namespace std;

int main(void){
    int n, count=0;
    cin>>n;
    int arr[n+1] = {0};

    for(int i = 0; i<=9; i++){
        for(int j = 1; j<=9; j++){
            int check = i;
            while(check%10+j<=9){
                check=(check*10)+(check%10+j);
                if(check<=n) {
                    printf("%d ",check);
                    arr[check]=1;
                }
                else break;
            }
        }

        for(int j = -1; j>=-9; j--){
            int check = i;
            while(check%10+j>=0){
                check=(check*10)+(check%10+j);
                if(check<=n) {
                    printf("%d ",check);
                    arr[check]=1;
                }
                else break;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(arr[i] == 1)
            count++;
    }

    cout<<count;


    return 0;
}