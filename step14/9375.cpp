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

        switch(list.size()){
            case 0:
                cout<<"0\n";
                break;
            case 1:
                // 의상 개수와 같음
                cout<<list.begin()->second<<'\n';
                break;
            default:
                int count = 1;
                for(auto mem : list){
                    // 의상을 착용하지 않았을 경우를 더해서 계산
                    count *= mem.second + 1;
                }
                // 모든 의상을 입지 않았을 경우 제외
                count -= 1;
                cout<<count<<'\n';
        }
    }

    if(t == 0) cout<<'0';

    return 0;
}