#include <iostream>

using namespace std;

int main(){
    long target;
    long check = 0;

    cin>>target;

    for(long i = 1;;i++){
        check = check + i;
        if(target<=check){
            if(i%2==0){
                int c = i - (check-target);
                int p = i + 1 - c;
                cout<<c<<"/"<<p;
            }
            else{
                int p = i - (check - target);
                int c = i + 1 - p;
                cout<<c<<"/"<<p;
            }
            break;
        }
    }

    return 0;
}