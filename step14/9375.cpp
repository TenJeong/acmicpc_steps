#include <iostream>
#include <map>

using namespace std;

int main(){

    int t;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;

    for(int i = 0; i < t; i++){
        int n;
        cin>>n;

        map<string, int> list;

        for(int j = 0; j < n; j++){
            string temp;
            // 의복 이름은 사용하지 않음. 따라서 바로 의복 종류를 읽음
            cin>>temp>>temp;

            auto isFound = list.find(temp);
            if(isFound != list.end()){
                isFound->second = isFound->second + 1;
            }
            else{
                list.insert(make_pair(temp, 1));
            }
        }

        int count = 1;
        for(auto mem : list){
            count *= mem.second + 1;
        }
        count -= 1;
        cout<<count<<'\n';
    }

    return 0;
}