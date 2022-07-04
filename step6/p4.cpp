#include <iostream>
#include <string>

using namespace std;

int main(void){
    int n, times;
    string str;

    scanf("%d\n",&n);

    for(int i = 0; i < n; i++){
        scanf("%d ",&times);
        cin>>str;
        for(char c : str){
            for(int j = 0; j<times;j++){
                printf("%c",c);
            }
        }
        printf("\n");
    }

    return 0;
}