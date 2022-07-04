#include <iostream>

using namespace std;

int main(void){
    int count[42]={0};
    int exc_count=0;
    int num;

    for(int i = 0; i < 10; i++){
        cin>>num;
        if(count[num%42]==0){
            exc_count++;
            count[num%42]++;
        }
    }

    cout<<exc_count;

    return 0;
}