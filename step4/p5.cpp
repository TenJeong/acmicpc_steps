#include <iostream>

using namespace std;

int main(void){
    int n, num;
    int max = -1;
    float total = 0.0f;

    cin>>n;

    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        total+=num;
        if(max<num) max = num;
    }

    cout<<(total/max)*100/n;

    return 0;
}