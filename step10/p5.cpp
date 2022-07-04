#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n;
    int count = 1;
    int digit = 0;
    int front_count=0, rear_count=0;

    scanf("%d",&n);

    while(count != n){

        // front of number
        front_count++;
        count++;

        if(front_count % 10 == 6){
            digit = 0;
            for(int i = front_count; i % 10 == 6; i /= 10){
                digit++;
            }

            // rear of number
            int rearMax=1;
            for(int check = 0; check<digit; check++){
                rearMax*=10;
            }

            for(rear_count = 0; (rear_count < rearMax) && (count < n); rear_count++){
                count++;
            }

            if(rear_count == rearMax){
                rear_count=0;
                front_count++;
                digit=0;
            }
        }

    }

    // output
    if(front_count != 0){
        printf("%d",front_count);
    }
    for(int i = digit; i < 3; i++){
        printf("6");
    }
    int rear_nz_digit = 0;
    int temp = rear_count;
    for(rear_nz_digit = 0; temp > 0; temp /= 10){
        rear_nz_digit++;
    }
    for(int i = 0; i < digit - rear_nz_digit; i++){
        printf("0");
    }
    if(rear_nz_digit!=0){
        printf("%d",rear_count);
    }

    return 0;
}