#include <iostream>
#define MAX_COUNT 5000

using namespace std;

int main(){

    int num;
    int total = MAX_COUNT;
    cin>>num;

    for(int w5 = num / 5; w5 >= 0; w5--){
        int rem = num - w5 * 5;

        if(rem % 3 == 0 &&  w5 + rem / 3 < total)
            total = w5 + rem / 3;
    }

    if(total == MAX_COUNT) cout<<-1;
    else cout<<total;    

    return 0;
}