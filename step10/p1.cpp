#include <iostream>

using namespace std;

int main(){

    int n, m;
    int max = -1;

    scanf("%d %d\n",&n,&m);

    int arr[n] = {0};

    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    for(int first = 0; first < n-2; first++){
        for(int second = first+1; second < n-1; second++){
            for(int third = second+1; third < n; third++){

                int sum = arr[first]+ arr[second] + arr[third];

                if(sum > max && sum <= m){
                    max = sum;
                }
            }
        }
    }

    cout<<max;

    return 0;
}