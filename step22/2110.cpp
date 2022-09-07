#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    가장 인접한 곳의 거리가 최대임 = 거리가 거의 공평하게 유지됨
    따라서 인접한 곳의 거리를 비슷하게 설정해준다
*/

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, c;
    int answer = 0;

    cin>>n>>c;
    vector<int> housePos;

    for(int i = 0; i < n; i++){
        int pos;
        cin>>pos;

        housePos.push_back(pos);
    }

    sort(housePos.begin(), housePos.end());

    // 최소: 1, 최대: 마지막과 첫 집의 거리
    int left = 1, right = housePos[n - 1] - housePos[0];
    int maxDis = right;

    while(left <= right){
        int mid = (right + left) / 2;

        // 주어진 거리를 최대한으로 만들기 위해서 첫번째 집에는 무조건 설치함
        int plantCount = 1;
        int lastPlantIdx = 0;
        int shortest = maxDis;

        // 마지막으로 설치한 곳과 거리를 비교함
        for(int curPos = 1; curPos < n; curPos++){
            // 거리가 mid 이상이면 해당하는 집에 설치하고 마지막 설치 위치를 갱신
            int curDis = housePos[curPos] - housePos[lastPlantIdx];
            if(curDis >= mid){
                // 설치 대수 갱신
                plantCount++;
                lastPlantIdx = curPos;
                if(curDis < shortest){
                    shortest = curDis;
                }
            }
        }

        // 설치 대수가 c보다 적으면 거리를 좁게하여 더 많이 설치한다
        if(plantCount < c){
            right = mid - 1;
        }
        // 설치 대수가 c와 같거나 크면 거리를 넓게하여 가장 인접한 거리를 늘여본다
        else{
            // 가장 인접한 거리 갱신
            if(answer < shortest) answer = shortest;
            left = mid + 1;
        }
    }

    cout<<answer;

    return 0;
}