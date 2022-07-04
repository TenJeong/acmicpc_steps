#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,m;
    vector<int> v;

    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d",&temp);
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        int temp;
        scanf("%d",&temp);
        if(binary_search(v.begin(),v.end(),temp))   printf("1 ");
        else printf("0 ");
    }

    return 0;
}