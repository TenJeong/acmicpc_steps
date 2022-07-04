#include <iostream>
#include <string>

using namespace std;

int main(void){
    int pos[26];
    string str;

    fill(pos,pos+26,-1);

    cin>>str;

    for(int i = 0; i<str.size(); i++){
        if(pos[str[i]-'a'] == -1){
            pos[str[i]-'a'] = i;
        }
    }

    for(int c : pos){
        printf("%d ",c);
    }

    return 0;
}