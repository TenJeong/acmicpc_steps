#include <iostream>
#include <string>

using namespace std;

int main(void){
    string str;
    int max = 0, max_index = -1;
    int count[26]={0};

    cin>>str;

    for(char c : str){
        int cur_index = isupper(c) ? c-'A' : c-'a';
        if(max < ++count[cur_index]){
            max = count[cur_index];
            max_index = cur_index;
        }
    }

    for(int i = 0; i<26; i++){
        if(count[i] == max && i != max_index){
            cout<<'?';
            return 0;
        }
    }

    cout<<(char)(max_index+'A');

    return 0;
}