#include <iostream>

using namespace std;

int main(){

    int n;
    int countArr[10001] = {0,};

    scanf("%d",&n);
    int temp;

    for(int i = 0; i < n; i++){
        scanf("%d",&temp);
        countArr[temp]++;
    }

    for(int i = 0; i < 10001; i++){
        if(countArr[i]!=0){
            for(int j = 0; j < countArr[i]; j++)
                printf("%d\n",i);
        }
    }


    return 0;
}