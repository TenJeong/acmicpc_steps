#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n;
    vector<int> nums,sorted;

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d",&temp);

        nums.push_back(temp);
    }

    sorted = nums;

    sort(sorted.begin(),sorted.end());
    sorted.erase(unique(sorted.begin(),sorted.end()),sorted.end());

    for(auto m : nums){
        auto lb = lower_bound(sorted.begin(),sorted.end(),m);
        printf("%d ",lb - sorted.begin());
    }




    return 0;
}