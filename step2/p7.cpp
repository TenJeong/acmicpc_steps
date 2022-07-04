#include <iostream>

using namespace std;

int main(void){
    int num[3];
    int max;

    cin>>num[0]>>num[1]>>num[2];
    max=num[0];
    if(num[0] == num[1]){
        if(num[0]==num[2]) cout<<10000+num[0]*1000;
        else cout<<1000+num[0]*100;
    }
    else{
        if(num[1] == num[2]) cout<<1000+num[1]*100;
        else{
            if(num[0] == num[2]) cout<<1000+num[0]*100;
            else{
                if(max<num[1]) max = num[1];
                if(max<num[2]) max = num[2];

                cout<<max*100;
            }
        }
    }

    return 0;
}