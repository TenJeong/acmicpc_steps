#include <iostream>
#include <cmath>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;

    cin>>n;

    int count = 0;
    for(int i = 1; ; i++){

        if(pow(5, i) > n) break;

        // 5�� ����� ������ count + 1, 5�� �������� ����� �ִٸ� �ٽ� �ѹ� count + 1 
        for(int j = 1; j * pow(5, i) <= n; j++){
            count += 1;
        }
    }

    cout<<count;

    return 0;
}