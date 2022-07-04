#include <iostream>

using namespace std;

int main(){
    int n;
    int H, W, N;

    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>H>>W>>N;

        if(N%H==0) cout<<H;
        else cout<<N%H;

        if(N%H==0){ 
            if(N/H < 10) cout<<'0';
            cout<<N/H<<'\n';    
        }
        else {
            if(N/H+1 < 10) cout<<'0';
            cout<<N/H+1<<'\n';
        }
    }



    return 0;
}