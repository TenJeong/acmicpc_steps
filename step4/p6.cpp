#include <iostream>
#include <string>

using namespace std;

int main(void){
    int n, count = 0;
    int score=0;
    string ox;

    cin>>n;

    for(int i = 0; i < n; i++){
        score=0;
        count=0;
        cin>>ox;
        for(char cc : ox){
            if(cc=='O'){
                score+=++count;
            }
            else
                count=0;
        }
        cout<<score<<'\n';
    }



    return 0;
}