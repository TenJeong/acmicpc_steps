#include <iostream>

using namespace std;

int main() {

    int num;
    int min = 1000001, max = -1;
    int temp;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>num;

    for(int i = 0; i < num; i++){
        cin>>temp;

        if(min > temp) min = temp;
        if(max < temp) max = temp;
    }

    cout<<min*max;

    return 0;
}