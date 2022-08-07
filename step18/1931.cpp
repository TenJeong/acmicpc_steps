#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct meeting{
    int start;
    int end;
};

int compare(struct meeting a, struct meeting b){
    if(a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, count = 0;
    struct meeting time_table[100000];
    struct meeting prev_meeting; // 이전 회의


    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>time_table[i].start>>time_table[i].end;
    }

    // 회의가 빨리 끝나는 순서로 정렬
    sort(time_table, time_table + n, compare);

    prev_meeting = time_table[count++];

    for(int i = 1; i < n; i++){
        // 새로운 회의의 시작 시간이 이전 시간의 종료 시간 이후인지를 검사 
        if(time_table[i].start >= prev_meeting.end){
            count++;
            prev_meeting = time_table[i];
        }
    }

    cout<<count;


    return 0;
}