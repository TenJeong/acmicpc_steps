#include <iostream>

using namespace std;

int main(void){
    int n;
    char num;
    int total=0;

    scanf("%d\n",&n);
    for(int i = 0; i<n; i++){
        scanf("%c",&num);
        total += num - '0';
    }

    printf("%d",total);

    return 0;
}