#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    해당 알고리즘으로 수행했을 때, 벡터 내부를 출력하면 가장 긴 증가하는 부분 순열(LIS)과 같지 않을 수 있다.
    우리가 필요한 것은 해당 원소가 아닌 길이이며,
    해당 알고리즘은 원소들을 최대한 많이 넣게 하기 위한 알고리즘이다.
    정확한 LIS를 구할 필요가 없는 해당 문제에서는 사용이 가능하다.
*/

int n, num;
vector<int> seq;


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    cin>>num;

    // 첫번째 수 push
    seq.push_back(num);

    for(int i = 1; i < n; i++){
        cin>>num;

        // 증가하는 방향일 경우 마지막 위치에 push
        if(seq.back() < num){
            seq.push_back(num);
        }
        // 증가하는 방향이 아닐 경우 num보다 크거나 같은 값의 첫번째 위치에 replace
        else{
            vector<int>::iterator replacePoint = lower_bound(seq.begin(), seq.end(), num);
            *replacePoint = num;
        }
    }

    // 생성된 부분 수열 원소 개수 출력
    cout<<seq.size();

    return 0;
}