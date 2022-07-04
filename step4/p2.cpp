#include <iostream>

int main(void){
    int num;
    int max_num = 0, max_index = 0;

    for(int i = 1; i <= 9; i++){
        scanf("%d",&num);

        if(max_num < num){
            max_num = num;
            max_index = i;
        }
    }

    printf("%d\n%d",max_num,max_index);

    return 0;
}