#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int> &a){
    long long ans=0;

    for(int num : a){
        ans += num;
    }

    return ans;
}

int main(void){

    return 0;
}