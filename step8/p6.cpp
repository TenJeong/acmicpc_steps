#include <iostream>

using namespace std;

int main(){
    int primeArr[10001] = {0};

    primeArr[1] = 1;

    for(int i = 2; i<=10000; i++){
        if(primeArr[i] == 0){
            for(int j = i+i; j<=10000; j+=i){
                primeArr[j] = 1;
            }
        }
    }

    int num;

    while(cin>>num){
        for(int i = num/2; i>1; i--){
            if(primeArr[i] == 0 && primeArr[num-i] == 0){
                if(i<num-i){
                    cout<<i<<' '<<num-i<<'\n';
                }
                else{
                    cout<<num-i<<' '<<i<<'\n';
                }
                break;
            }
        }
    }

    return 0;
}