#include <iostream>

using namespace std;

int main(void){
    int new_num=0;
    int origin_num;
    int count=0;

    cin>>origin_num;
    new_num = origin_num;


    while(true){
        new_num = (new_num % 10) * 10 + (new_num / 10 + new_num % 10) % 10;
        count++;
        if(origin_num==new_num)
            break;
    }

    cout<<count;

    return 0;
}