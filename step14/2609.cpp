#include <iostream>

using namespace std;

int main(){
    int numA, numB;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>numA>>numB;

    int numG = numA < numB ? numA : numB;

    while(numG > 1){
        if(numA % numG == 0 && numB % numG == 0){
            cout<<numG<<'\n';
            break;
        }
        numG--;
    }

    if(numG == 1) cout<<numG<<'\n';

    cout<<numA * numB / numG;

    return 0;
}