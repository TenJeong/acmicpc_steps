#include <iostream>
#include <algorithm>

using namespace std;

struct member{
    int age;
    string name;

    bool operator<(const struct member other_mem) const {
        return age < other_mem.age;
    }

};

int main(){

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;

    cin>>n;

    struct member arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i].age>>arr[i].name;
    }

    stable_sort(arr,arr+n);

    for(auto m : arr){
        cout<<m.age<<' '<<m.name<<'\n';
    }

    return 0;
}