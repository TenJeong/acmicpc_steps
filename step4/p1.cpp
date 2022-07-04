#include <iostream>
#define MIN_NUM -1000000
#define MAX_NUM 1000000

using namespace std;

int main(void){

    int n, num;
    int min = MAX_NUM, max = MIN_NUM;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>num;
        if(min>num) min = num;
        if(max<num) max = num;
    }

    cout<<min<<" "<<max;

    return 0;
}