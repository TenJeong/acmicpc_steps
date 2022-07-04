#include <iostream>
#include <set>

using namespace std;

int main() {

    int num_a, num_b;
    set<int> my_set;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>num_a>>num_b;

    for(int i = 0; i < num_a; i++){
        int temp;
        cin>>temp;
        my_set.insert(temp);
    }

    for(int i = 0; i < num_b; i++){
        int temp;
        cin>>temp;
        if(my_set.count(temp)){
            my_set.erase(temp);
        }
        else{
            my_set.insert(temp);
        }
    }

    cout<<my_set.size();



    return 0;
}