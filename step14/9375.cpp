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
            // �Ǻ� �̸��� ������� ����. ���� �ٷ� �Ǻ� ������ ����
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
                // �ǻ� ������ ����
                cout<<list.begin()->second<<'\n';
                break;
            default:
                int count = 1;
                for(auto mem : list){
                    // �ǻ��� �������� �ʾ��� ��츦 ���ؼ� ���
                    count *= mem.second + 1;
                }
                // ��� �ǻ��� ���� �ʾ��� ��� ����
                count -= 1;
                cout<<count<<'\n';
        }
    }

    if(t == 0) cout<<'0';

    return 0;
}