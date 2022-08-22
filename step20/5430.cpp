#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        string query;
        cin>>query;

        int numSize;
        cin>>numSize;

        string strBuffer;
        cin>>strBuffer;

        // '[', ']' 제거
        strBuffer = strBuffer.substr(1, strBuffer.size() - 2);

        stringstream ss(strBuffer);
        string temp;

        deque<int> numList;

        // ','를 기준으로 문자열을 분리하고 정수로 변환
        while(getline(ss, temp, ',')){
            if(temp != "") numList.push_back(stoi(temp));
        }

        bool isError = false;
        bool isReverse = false; // 현재 역방향 여부

        // 함수 수행
        for(int i = 0; i < query.size(); i++){
            if(query[i] == 'R'){
                // 정방향, 역방향 변환
                isReverse = !isReverse;
            }
            else if(query[i] == 'D'){
                // 덱이 비었다면 에러
                if(numList.empty()){
                    isError = true;
                    break;
                }

                // 역방향일 경우 back, 정방향일 경우 front를 pop함
                if(isReverse) numList.pop_back();
                else numList.pop_front();
            }
        }

        if(isError){
            cout<<"error\n";
        }
        else{
            cout<<'[';
            while(!numList.empty()){
                // 역방향일 경우 뒤에서부터, 정방향일 경우 앞에서부터 출력함
                if(isReverse){
                    cout<<numList.back();
                    numList.pop_back();
                }
                else{
                    cout<<numList.front();
                    numList.pop_front();
                }
                if(!numList.empty()) cout<<',';
            }
            cout<<"]\n";
        }

    }

    return 0;
}