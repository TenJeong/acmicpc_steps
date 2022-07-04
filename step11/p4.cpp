#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    int n;
    int total = 0;
    int prev_num=4001,cur_count=-1;
    int freq_count=-1,freq_num=4001;
    bool isDuplicated = true;

    scanf("%d",&n);

    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
        total += arr[i];
    }

    float avg = round((float)total/n);
    if(avg == -0.0)
        avg = 0;

    printf("%.0f\n",avg);

    sort(arr,arr+n);

    printf("%d\n",arr[n/2]);

    for(int i = 0; i < n; i++){
        if(prev_num == arr[i]){
            cur_count++;
        }
        else{
            if (cur_count > freq_count){
                freq_count = cur_count;
                freq_num = prev_num;
                isDuplicated = false;
            }
            else if (cur_count == freq_count && !isDuplicated){
                freq_num = prev_num;
                isDuplicated = true;
            }
            else if (cur_count == -1){
                isDuplicated = false;
            }
            prev_num = arr[i];
            cur_count=1;
        }
    }

    if((cur_count > freq_count) || (cur_count == freq_count && !isDuplicated))
        freq_num = arr[n-1];

    printf("%d\n%d",freq_num,arr[n-1]-arr[0]);



    return 0;
}