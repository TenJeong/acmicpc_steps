#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> myStack;
int arr[9] = {0};

void find(int count){
    for(int i = 1; i <= n; i++){
        if(arr[i] == 0){
            myStack.push_back(i);
            arr[i] = 1;

            if(count - 1 == 0){
                for(int v : myStack){
                    cout<<v<<' ';
                }
                cout<<'\n';
            }
            else find(count-1);

            myStack.pop_back();
            arr[i] = 0;
        }
    }
}


int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    find(m);

    return 0;
}