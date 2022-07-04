#include <iostream>

using namespace std;


int main(){

    int min, max;
    int global_min = -1;
    int total = 0;
    bool isPrime = true;
    cin>>min>>max;

    for(int i = min; i <= max; i++){
        isPrime = i == 1? false: true;
        for(int j = 2; j < i; j++){
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime == true){
            if(global_min == -1) global_min = i;
            total += i;
        }
    }

    if(global_min == -1) cout<<-1;
    else cout<<total<<'\n'<<global_min;

    return 0;
}